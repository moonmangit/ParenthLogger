#ifndef __ANSICOLORS__H__
#define __ANSICOLORS__H__

#include <Arduino.h>

typedef uint8_t clr_t;

static const char *const ANSI_COLOR_TAGS[] = {"\033[1;30m",
                                              "\033[1;31m",
                                              "\033[1;32m",
                                              "\033[1;33m",
                                              "\033[1;34m",
                                              "\033[1;35m",
                                              "\033[1;36m",
                                              "\033[1;37m"};
enum Colors { black,
              red,
              green,
              yellow,
              blue,
              magenta,
              cyan,
              white,
              none };

#endif //!__ANSICOLORS__H__