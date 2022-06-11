#include "ParenthLogger.h"

// public
void ParenthLogger::ansiDisable(void)
{
    ansiEnabled = false;
}
void ParenthLogger::ansiEnable(void)
{
    ansiEnabled = true;
}
void ParenthLogger::ansiSet(const char *defaultStyle)
{
    this->defaultStyle = defaultStyle;
}
ParenthLogger &ParenthLogger::useFormat(const char *format, const char *formatStyle)
{
    this->format = format;
    this->formatStyle = (strlen(formatStyle) == 0) ? defaultStyle : formatStyle;
    printUtilPlaceHolder();
    return *this;
}

// private
void ParenthLogger::printUtilPlaceHolder()
{
    if (ansiEnabled)
        Serial.print(formatStyle);
    while (!(format[0] == '%' && format[1] == 'i'))
    {
        if (format[0] == '\0')
            break;
        Serial.print(format[0]);
        format = &format[1];
    }
}