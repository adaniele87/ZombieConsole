#include <Windows.h>
#include <iostream>
#include "game.h"
#include "animations.h"

#define HEARTBEAT_THEME 0

Game::Game(int enemies)
{
    object = new Object[2+enemies];      // create player, oat, and enemies
    object[0].x(0);
    object[0].y(0);

    cols        = console.getCols()-2;   // set initial values
    enemySlowD  = 10;
    level       = 1;
    oatWorth    = 200;
    objects     = 2+enemies;
    playerSlowD = 2;
    rows        = console.getRows()-2;
    score       = 0;
    ticks       = GetTickCount();

    srand(ticks);                        // set random start locations for oat and enemies
    for (int i = 1; i < 2+enemies; i++)
    {
        randLocation(object[i]);
        if(object[i].x() < 15) object[i].x(15);
        if(object[i].y() < 15) object[i].y(15);
    }
}

Game::~Game()
{
    delete[] object;
}
bool Game::contact(Object& player, Object& object)
{
    return ((player.x() >= object.x()-1 && player.x() <= object.x()+1) && 
            (player.y() >= object.y()-1 && player.y() <= object.y()+1));
}

int Game::gameLoop()
{
    Object ScoreDisplay(0,0);
    int displayScore  = 0;
    int moveEnemy = 0;
    int movePlayer = 0;
    int oatpoints = oatWorth;
    int moveScoreUp = 0;
    int nextRandomMove = 0;
    int lastScore = 0;
    int nextLevel = 0;
    int rMove = 0;
    bool done = false;

    while(!done)
    {
        ticks = GetTickCount();
        render();

        if (nextRandomMove==100)
        {
            srand(ticks);
            for(int i = 2; i < objects; object[i++].setDirection(0));
            nextRandomMove=0;
        }
        if (nextLevel > 1000)
        {
            levelUp();
            nextLevel -= 1000;
        }

        // input and output of user and enemies
        if (movePlayer >= playerSlowD)
        {
            object[0].getInput();
            movePlayer = 0;
        }
        if (moveEnemy >= enemySlowD)
        {
            for (int i = 2; i < objects; i++)
            {
                if(!tooClose(object[0], object[i])) object[i].randMove(rand()%5);
            }
            moveEnemy = 0;
        }
        for (int i = 0; i < objects; testCollision(object[i++]));
        for (int i = 2; i < objects && !done; done = contact(object[0],object[i++]));

        // check if player ate oat
        if (contact(object[0],object[1]))
        {
            ScoreDisplay.x() = object[1].x();
            ScoreDisplay.y() = object[1].y();
            randLocation(object[1]);
            score+=oatpoints;
            nextLevel += oatpoints;
            if (oatWorth > MAXOATWORTH) console.alarm();
            lastScore  = oatpoints;
            oatpoints  = oatWorth;
        }

        // display score of oat just eaten
        if (lastScore > 0 && moveScoreUp < showScorexln)
        {
            if (displayScore < showScore1ln)
            {
                console.setPos(ScoreDisplay.y(), ScoreDisplay.x());
                std::cout << lastScore;
                displayScore++;
            }
            else
            {
                ScoreDisplay.x()++;
                ScoreDisplay.y()--;
                displayScore = 0;
                moveScoreUp++;
            }
        }
        else 
        {
            moveScoreUp = 0;
            lastScore   = 0;
        }

        // change counter values
        if (oatpoints > 0) oatpoints--;
        else
        {
            randLocation(object[1]);
            oatpoints = oatWorth;
        }
        moveEnemy++;
        movePlayer++;
        nextRandomMove++;

        // regulate fps
        if (1000/FPS > GetTickCount()-ticks)
        {
            Sleep(1000/FPS-(GetTickCount()-ticks));
        }
    }

    return score;
}

int Game::getScore() { return score; }
int Game::getLevel() { return level; }

void Game::heartBeat()
{
    static int i = 0;
    int sleepers[2] = {200,700};

    i = !i;

    Beep(100,100);
    Sleep(sleepers[i]);
}

void Game::levelUp()
{
    if (enemySlowD-2 > MINENEMYSPEED) enemySlowD -= 2;
    else enemySlowD = MINENEMYSPEED;

    if (oatWorth < MAXOATWORTH) oatWorth += 20;
    else oatWorth = MAXOATWORTH;

    if (oatWorth != MAXOATWORTH && enemySlowD != MINENEMYSPEED) level++;
}

void Game::moveEnemyClose(Object& player, Object& enemy)
{
    if(player.x() > enemy.x()) enemy.moveRight();
    if(player.x()+1 < enemy.x()) enemy.moveLeft();
    if(player.y() > enemy.y()) enemy.moveDown();
    if(player.y()+1 < enemy.y()) enemy.moveUp();
}

void Game::render()
{
    console.clear();
    object[1].draw(oat);
    object[0].draw(character);
    for (int i = 2; i < objects; object[i++].draw(zombie));
}
void Game::randLocation(Object& object)
{
    object.x(rand()%cols);
    object.y(rand()%rows);
}

void Game::testCollision(Object& object)
{
    if(object.x() < 0) object.x(0);
    if(object.y() < 0) object.y(0);
    if(object.x()+1 > cols) object.x(cols-1);
    if(object.y()+1 > rows) object.y(rows-1);
}

void Game::titleScreen()
{
    Object titleScreen(10,5);
    Object pStart(15, 18);
    titleScreen.Frame(1);
    int i                = 0;
    int pressStartEffect = 0;

    if (HEARTBEAT_THEME) pressStartEffect = 3;
    else pressStartEffect = 50;

    int done = false;

    while (titleScreen.Frame() < 57 && !done) // draw zoom animation of title
    {
        ticks = GetTickCount();
        console.clear();
        titleScreen.draw(title);
        titleScreen.Frame(titleScreen.Frame()+1);
        titleScreen.x(titleScreen.x()+1);

        if (GetKeyState(VK_RETURN) & 0x80) done = true;

        if (1000/FPS > GetTickCount()-ticks)
        {
            Sleep(1000/FPS-(GetTickCount()-ticks));
        }
    }

    done = false;
    console.clear();
    if (!HEARTBEAT_THEME) Sleep(200);

    titleScreen.x(10);
    titleScreen.y(5);
    titleScreen.Frame(0);

    while (!done)
    {
        ticks = GetTickCount();

        if (HEARTBEAT_THEME) heartBeat();

        if (i == 0)
        {
            titleScreen.draw(title);
            pStart.draw(pressStart);
        }
        if (i == pressStartEffect/2)
        {
            console.clear();
            titleScreen.draw(title);
        }

        if (i < pressStartEffect) i++;
        else i = 0;

        if (GetKeyState(VK_RETURN) & 0x80) done = true;

        if (1000/FPS > GetTickCount()-ticks)
        {
            Sleep(1000/FPS-(GetTickCount()-ticks));
        }
    }
}

bool Game::tooClose(Object& player, Object& enemy)
{
    if ((player.x() > enemy.x() - 15) &&
        (player.x()+1 < enemy.x() + 15) &&
        (player.y() > enemy.y() - 15) &&
        (player.y()+1 < enemy.y() + 15))
    {
        moveEnemyClose(player, enemy);
        return true;
    }
    else return false;
}
