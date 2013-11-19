#include "object.h"
#include "console.h"
using namespace cio;

class Game
{
    //private members
    Object* object;
    int cols;
    int enemySlowD;
    int level;
    int oatWorth;
    int objects;
    int playerSlowD;
    int rows;
    int score;
    int ticks;
    //private methods
    void levelUp();
public:
    Game(int enemies = 4);
    ~Game();
    bool contact(Object&, Object&);
    void render();
    int  gameLoop();
    void heartBeat();
    void moveEnemyClose(Object&, Object&);
    void randLocation(Object&);
    int  getScore();
    int  getLevel();
    void testCollision(Object&);
    void titleScreen();
    bool tooClose(Object&, Object&);
};

const int MAXOATWORTH    = 500;
const int MINENEMYSPEED  = 3;  // slows down enemy
const int FPS            = 60; // regulate frames
const int showScore1ln   = 4; // how long to show float-away score on one line
const int showScorexln   = 4;  // how many lines to show float-away score