/*********************************************************/
/* Andrew Daniele                  adaniele1@myseneca.ca */
/* October 09, 2013                                      */
/* animations.h                                          */
/*                                                       */
/* This file is to contain all the declarations of       */
/* animation functions. An animation function for the    */
/* time being may not return anything, and must take in  */
/* exactly 3 referenced integers where:                  */
/* int  firstParam = c; will hold the column of where to */
/*                      start displaying the animation   */
/* int  secondParam= r; will hold the row of where to    */
/*                      start displaying the animation   */
/* int  thirdParam = f; will hold the frame to display   */
/*                      when function is called          */
/*********************************************************/

void character (int c, int r, int f); // draws a race track like arrow
void oat       (int c, int r, int f); // draws an O in a 4x4 grid
void title     (int c, int r, int f); // draws a big title "ZOMBIE CONSOLE"
void pressStart(int c, int r, int f); // draws a small "PRESS START"
void zombie    (int c, int r, int f); // draws a small zombie