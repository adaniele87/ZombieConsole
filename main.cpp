#include <iostream>
#include <windows.h>
#include "game.h"
#include "animations.h"

int main()
{
    int rows  = console.getRows()-1;
    int cols  = console.getCols()-1;

    Game game(4);
    game.titleScreen();
    game.gameLoop();
    console.clear();
    console.display("You DIED!", rows/2, cols/2/2);
    console.display("  score:", rows/2+1, cols/2/2);
    console.display("  level:", rows/2+2, cols/2/2);

    console.setPos(rows/2+1, cols/2/2+10);
    std::cout << game.getScore();
    console.setPos(rows/2+2, cols/2/2+10);
    std::cout << game.getLevel();
    
    std::cin.ignore();
    getchar();
}