/* this code is from the OOP344 notes: http://www.20133notes/SecB/07-Sep27/CIO */
/* and has been partly modified */

#ifndef __FS_CONSOLE_H__
#define __FS_CONSOLE_H__

#include "bconsole.h"


namespace cio{

  class Console:public bio::BConsole{
    static bool _insertMode;
  public:
  void display(const char* str, int row, int col, int len = 0, int strOffset = 0, int curPosition = -1);
  };
  
  extern Console console;
}


#endif
