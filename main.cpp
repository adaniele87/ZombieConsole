#include <iostream>
#include <windows.h>
#include "game.h"
#include "animations.h"

int main()
{
    int rows  = console.getRows()-1;
    int cols  = console.getCols()-1;
    int i     = 0; // times played, for now just skips intro after first playthrough
    int key   = 0;
    bool done = false;
    bool choice = false;

    while(!done)
    {
        Game* game = new Game(4);

        if(!i++) game->titleScreen();

        game->gameLoop();

        console.clear();
        console.display("You DIED!", rows/2, cols/2/2);
        console.display("  score:", rows/2+1, cols/2/2);
        console.display("  level:", rows/2+2, cols/2/2);

        console.display("ENTER - play again", rows, 0);
        console.display("ESCAPE - exit", rows, cols-13);

        console.setPos(rows/2+1, cols/2/2+10);
        std::cout << game->getScore();
        console.setPos(rows/2+2, cols/2/2+10);
        std::cout << game->getLevel();

        while(!choice)
        {
            if (GetKeyState(VK_RETURN) & 0x80)
            {
                delete game;
                choice = true;
            }
            if (GetKeyState(VK_ESCAPE) & 0x80)
            {
                done   = true;
                choice = true;
            }
        }
        choice = false;

    } // end of while(!done)

} // end of main()