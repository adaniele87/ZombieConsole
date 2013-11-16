/*********************************************************/
/* Andrew Daniele                  adaniele1@myseneca.ca */
/* November 16, 2013                                     */
/* object.h                                              */
/*                                                       */
/* Object's method definitions.                          */
/*********************************************************/

#include "object.h"
#include "windows.h"

/* CONSTRUCTORS */
Object::Object()
{
    xCoord    = 0;
    yCoord    = 0;
    frame     = 0;
}
Object::Object(int _x, int _y)
{
    xCoord    = _x;
    yCoord    = _y;
    frame     = 0;
}


/* virtual destructor, does nothing */
Object::~Object(){}


/* get input from keyboard to move object */
void Object::getInput()
{
    if(GetKeyState(VK_UP) & 0x80)
    {
        moveUp();
    }
    if(GetKeyState(VK_RIGHT) & 0x80)
    {
        moveRight();
    }
    if(GetKeyState(VK_DOWN) & 0x80)
    {
        moveDown();
    }
    if(GetKeyState(VK_LEFT) & 0x80)
    {
        moveLeft();
    }
}


/* receives a pointer to an animation function and draws it */
void Object::draw(void (*animation)(int _x, int _y, int _f))
{
    (*animation)(xCoord, yCoord, frame);
}



/* Getters + Setters. Return and/or modify Object's Xcoord, Ycoord, or _frame's value */
int& Object::x(int c)
{
    if (c < 0)
    {
        return xCoord;
    }
    else
        xCoord = c;

    return xCoord;
}
int& Object::y(int r)
{
    if (r < 0)
    {
        return yCoord;
    }
    else
        yCoord = r;

    return yCoord;
}
int& Object::Frame(int _frame)
{
    if (_frame < 0)
    {
        return frame;
    }
    else
        frame = _frame;

    return frame;
}

/* Alter Object's coordinates to allow movement on the screen */
void Object::moveUp(){
    yCoord--;
    setDirection(1);
}
void Object::moveRight(){
    xCoord++;
    setDirection(2);
}
void Object::moveDown(){
    yCoord++; 
    setDirection(3);
}
void Object::moveLeft(){
    xCoord--;
    setDirection(4);
}

/* set moving direction for frame, controls direction character is drawn facing */
void Object::setDirection(int sd) { frame = sd; }


/* receives an integer of a random value, and moves character accordingly,
   ie. rand()%4 as the variable to pass, and seed with srand(GetTickCount()) */
void Object::randMove(int random)
{
    if (frame) // don't move randomly if frame has a value
    {
        switch(frame)
        {
        case 1:
            moveUp();
            break;
        case 2:
            moveRight();
            break;
        case 3:
            moveDown();
            break;
        case 4:
            moveLeft();
            break;
        }
    }
    else // move randomly
    {
        switch(random)
        {
        default:
            moveUp();
            break;
        case 2:
            moveRight();
            break;
        case 3:
            moveDown();
            break;
        case 4:
            moveLeft();
            break;
        }
    }
}