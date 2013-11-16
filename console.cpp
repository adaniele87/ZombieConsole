/* this code is from the OOP344 notes: http://www.20133notes/SecB/07-Sep27/CIO */
/* and has been partly modified */

#include "console.h"

namespace cio{
    Console console;
    bool Console::_insertMode = true;

    void Console::display(const char* str, int row, int col, int len, int strOffset, int curPosition){
        int i=strOffset;
        setPos(row, col);
        if(len){ //limited number of chars
          for(;i<len+strOffset&&str[i];i++){
            putChar(str[i]);
          }
          for(;i<len+strOffset;i++){
            putChar(' ');
          }
        }
        else{  // print the whole thing
          for(;str[i];i++){
            putChar(str[i]);
          }    
        }
        if(curPosition >= 0){
          setPos(row, col + curPosition);
        }
    }
}