#include <ParenthLogger.h>

using namespace ansi_style;

ParenthLogger plog(blue_italic, true);

void setup()
{
    Serial.begin(9600);
    plog("\ncurrent time is ")(":")(__TIME__);
    plog.useFormat("\nTest Pi Value => %i * %i = %i", yellow_italic)
        .f(PI)
        .f(2)
        .f(PI * 2, red);
    plog(F("Hello this is long text, you need to use F() to reduce memory usage"), green);
}

void loop() {}