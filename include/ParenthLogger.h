#ifndef __PARENTHLOGGER__H__
#define __PARENTHLOGGER__H__

#include "AnsiColors.h"
#include <Arduino.h>
#define V2CSTR(VAR) String(#VAR).c_str()
#define B2CSTR(BOOL) (BOOL) ? "true" : "false"
#define B2OPTS(BOOL, IFT, IFF) (BOOL) ? IFT : IFF

typedef uint16_t pchar_t;

struct ParenthData {
    const char *content;
    clr_t color;
    pchar_t lineLimit;
};

class ParenthLogger {
private:
    const char *pt = NULL;
    pchar_t pti = 0;
    clr_t ptc = none;
    bool ansiEnabled = true;

public:
    ParenthLogger(bool ansiEnabled = true) {
        this->ansiEnabled = ansiEnabled;
    }
    ~ParenthLogger() {}
    ParenthLogger &use(const char *parenthTemplate, clr_t parenthTemplateColor = white);
    ParenthLogger &print(ParenthData parenthData);

    ParenthLogger &print(const char *content, clr_t color = white, pchar_t lineLimit = 0);
    ParenthLogger &operator()(const char *content, clr_t color = white, pchar_t lineLimit = 0);

    ParenthLogger &print(int content, clr_t color = white, pchar_t lineLimit = 0);
    ParenthLogger &operator()(int content, clr_t color = white, pchar_t lineLimit = 0);

    ParenthLogger &print(unsigned int content, clr_t color = white, pchar_t lineLimit = 0);
    ParenthLogger &operator()(unsigned int content, clr_t color = white, pchar_t lineLimit = 0);

    ParenthLogger &print(double content, clr_t color = white, pchar_t lineLimit = 0);
    ParenthLogger &operator()(double content, clr_t color = white, pchar_t lineLimit = 0);
};

static ParenthLogger plog(true);

/*
    use-case
        plog.use(<ParenthTemplate>)
                   "\n %i %i %i"
        plog(<ParenthData>)
    ex:
        (1) plog.use("\n-> %i + %i = %i ", yellow);
      (1.1) plog(x)(y)(x*y);
      (1.2) plog(x);
            plog(y);
            plog(x*y);

        (2) plog.use("\n-> %i + %i = %i ", yellow)(x)(y)(x*y);

        (3) plog.use("\n-> %i + %i = %i ");
            plog(x, 0, red)(y, 0, green)(x*y, 0, blue);
*/

#endif //!__PARENTHLOGGER__H__