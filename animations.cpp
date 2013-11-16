/*********************************************************/
/* Andrew Daniele                  adaniele1@myseneca.ca */
/* November 16, 2013                                     */
/* animations.cpp                                        */
/*                                                       */
/* write all your animation definitions here, no need to */
/* comment here. Use comments in header file instead.    */
/*********************************************************/
#include "animations.h"
#include "console.h"
using namespace cio;

void character(int c, int r, int f)
{
    switch(f)
    {
    default:
        console.display("^^", r, c);
        console.display("^^", r+1, c);  
        break;
    case 2:
        console.display(">>", r, c);
        console.display(">>", r+1, c); 
        break;
    case 3:
        console.display("VV", r, c);
        console.display("VV", r+1, c); 
        break;
    case 4:
        console.display("<<", r, c);
        console.display("<<", r+1, c); 
        break;
    }
}
void zombie(int c, int r, int f)
{
    switch(f)
    {
    default:
    case 1:
    case 2:
        console.display("(}", r, c);
        console.display("|^", r+1, c);  
        break;
    case 3:
    case 4:
        console.display("{)", r, c);
        console.display("^|", r+1, c); 
        break;
    }
}

void oat(int c, int r, int f)
{
    console.display("OO", r, c);
    console.display("OO", r+1, c);
}

void pressStart(int c, int r, int f)
{
    console.display(" _   _   _  _   _     _  _   ___  _  _", r, c);
    console.display("|_| |_| |_ |_  |_    |_  |\\|  |  |_ |_|",  r+1, c);
    console.display("|   | \\ |_  _|  _|   |_  | |  |  |_ | \\", r+2, c);
}
void title(int c, int r, int f)
{
    int s = f > 0 ? 5 : 0;

    console.display("  ZZZZZZ    OOOO    MM   MM   BBBB    IIIIII   EEEEEE   " ,r   ,c,s,f);
    console.display("     ZZ    OO  OO   MMM MMM   BB BB     II     EE       " ,r+1 ,c,s,f);
    console.display("    ZZ     OO  OO   MM M MM   BBBB      II     EEEEEE   " ,r+2 ,c,s,f);
    console.display("   ZZ      OO  OO   MM   MM   BB BB     II     EE       " ,r+3 ,c,s,f);
    console.display("  ZZZZZZ    OOOO    MM   MM   BBBB    IIIIII   EEEEEE   " ,r+4 ,c,s,f);
    console.display("                                                        " ,r+5 ,c,s,f);
    console.display(" CCCC     OOOO    NN  NN   SSSS    OOOO    LL     EEEEEE" ,r+6 ,c,s,f);
    console.display("CC  CC   OO  OO   NNN NN   SS     OO  OO   LL     EE    " ,r+7 ,c,s,f);
    console.display("CC       OO  OO   NN NNN   SSSS   OO  OO   LL     EEEEEE" ,r+8 ,c,s,f);
    console.display("CC  CC   OO  OO   NN  NN     SS   OO  OO   LL     EE    " ,r+9 ,c,s,f);
    console.display(" CCCC     OOOO    NN  NN   SSSS    OOOO    LLLL   EEEEEE" ,r+10,c,s,f);
}
