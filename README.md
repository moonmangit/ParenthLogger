# ParenthesisLogger

ParenthLogger(Parenthesis-Logger) is library for streaming fomatted-colorized text using ANSI escape colors

---

## Before use

This library need little configuration on `platformio.ini` file

```cpp
//platformio.ini
monitor_flags = --raw
```

---

## Usage

In order to use this library provide `plog` out of the box you don't need to create it.

### 1. Basic Parenthesis Form

syntax : `plog(<int,double,string>, <color>, <line-limit>)`

```cpp
plog(10, red); 
=> 10 //in-red

plog(3.1415, cyan); 
=> 3.1415 //in-cyan

plog("hello-this-is-log-text", green, 8); 
=> hello... // in-green

plog("hello", red, 10)(":"); 
=> hello          : // in-red

plog(10)(20)(":", yellow)("Hello",red); 
=> 1020:Hello // in-white-white-yellow-red respectively

```

```cpp
void funx() {
    Serial.begin(<speed>); // <- still need this

    double x = 10;
    plog("\n>*",yellow)("value of x : ")(x, red);
}
```

### 2. Template

syntax: `plog.use(<template-string>, <color>)`

```cpp

plog.use("\n> %i + %i = %i")(10)(20)(10+20); 
=> > 10 + 20 = 30

plog.use("\n> %i + %i = %i", magenta)(10, red)(20, yellow)(10+20, green); 
=> > 10 + 20 = 30 // all-template except %i will be magenta color

plog.use("\n> %i : %i", yellow)
    .print("key-of-value", red, 10)
    .print(3.14, blue);
=> > key-of-... : 3.14


```
