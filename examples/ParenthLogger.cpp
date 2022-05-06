#include <ParenthLogger.h>

int number1 = 10;
float float1 = 3.14;
double double1 = 123.4125123;
const char *string1 = "Hello World";
bool bool1 = true;

// normal use-case
void my_function() {
    plog("\n")("Hello")("World: ")(string1); // => \nHelloWolrd: HelloWorld
    plog("\n> Number-1 : < ", blue)(number1, green)(" >");
    plog.use("\n> Number-1 : < %i >", blue)(number1, green);
    plog(V2CSTR(string1))(":")(string1, Colors::red);
    plog("this is bool1 in string form : ")(B2CSTR(bool1)); // this is bool1 in string form : true
}
