#ifndef __PARENTH_LOGGER_H__
#define __PARENTH_LOGGER_H__

#include <Arduino.h>
#include "ParenthLoggerStyle.h"

class ParenthLogger
{
public:
    void ansiDisable(void);
    void ansiEnable(void);
    void ansiSet(const char *defaultStyle);
    ParenthLogger &useFormat(const char *format, const char *formatStyle = "");

    template <typename T>
    ParenthLogger &print(T content, const char *contentStyle = "")
    {
        if (ansiEnabled)
            Serial.print((strcmp(contentStyle, "") == 0) ? defaultStyle : contentStyle);
        Serial.print(content);
        return *this;
    }
    template <typename T>
    ParenthLogger &operator()(T content, const char *contentStyle = "")
    {
        return print<T>(content, contentStyle);
    };

    template <typename T>
    ParenthLogger &f(T content, const char *contentStyle = "")
    {
        if (strlen(format) < 2)
            return *this;

        if (format[0] == '%' && format[1] == 'i')
        {
            print<T>(content, contentStyle);
            format = &format[2];
        }
        printUtilPlaceHolder();
        return *this;
    }

private:
    bool ansiEnabled;
    const char *defaultStyle, *format, *formatStyle;
    void printUtilPlaceHolder();

public:
    ParenthLogger(const char *defaultStyle = ansi_style::blue, bool ansiEnabled = true)
    {
        this->ansiEnabled = ansiEnabled;
        this->defaultStyle = defaultStyle;
        format = "";
    }
    ~ParenthLogger() {}
};

#endif