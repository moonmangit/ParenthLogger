#include "ParenthLogger.h"

ParenthLogger &ParenthLogger::print(ParenthData parenthData) {
    if (parenthData.color != none && ansiEnabled) {
        // open color tag
        Serial.print(ANSI_COLOR_TAGS[parenthData.color]);
    }

    // print content
    if (parenthData.lineLimit != 0) {
        uint16_t content_l = strlen(parenthData.content);
        if (content_l > parenthData.lineLimit) {
            // append ... for last 3 limit characters
            for (size_t i = 0; i < parenthData.lineLimit; i++) {
                if (i >= parenthData.lineLimit - 3) {
                    Serial.print('.');
                } else {
                    Serial.print(parenthData.content[i]);
                }
            }
        } else {
            // append ' ' for rest
            for (size_t i = 0; i < parenthData.lineLimit; i++) {
                if (i >= content_l) {
                    Serial.print(' ');
                } else {
                    Serial.print(parenthData.content[i]);
                }
            }
        }
    } else {
        Serial.print(parenthData.content);
    }

    if (parenthData.color != none && ansiEnabled) {
        // close color tag
        Serial.print("\033[0m");
    }

    if (pt != NULL) {
        if (pti + 2 < strlen(pt)) {
            pti += 2;
        }
        if (ptc != none && ansiEnabled) {
            Serial.print(ANSI_COLOR_TAGS[ptc]);
        }
        while (pt[pti] != '\0' && (pt[pti] != '%' || pt[pti + 1] != 'i')) {
            Serial.print(pt[pti]);
            pti++;
        }
        if (pt[pti] == '\0')
            pt = NULL;
        if (ptc != none && ansiEnabled) {
            Serial.print("\033[0m");
        }
    }

    return *this;
}
ParenthLogger &ParenthLogger::use(const char *parenthTemplate, clr_t parenthTemplateColor) {
    pt = parenthTemplate;
    pti = 0;
    ptc = parenthTemplateColor;

    if (ptc != none && ansiEnabled) {
        Serial.print(ANSI_COLOR_TAGS[ptc]);
    }
    while (pt[pti] != '\0' && (pt[pti] != '%' || pt[pti + 1] != 'i')) {
        Serial.print(pt[pti]);
        pti++;
    }
    if (pt[pti] == '\0')
        pt = NULL;
    if (ptc != none && ansiEnabled) {
        Serial.print("\033[0m");
    }

    return *this;
}

ParenthLogger &ParenthLogger::print(const char *content, clr_t color, pchar_t lineLimit) {
    return print({content, color, lineLimit});
}
ParenthLogger &ParenthLogger::operator()(const char *content, clr_t color, pchar_t lineLimit) {
    return print({content, color, lineLimit});
}

ParenthLogger &ParenthLogger::print(int content, clr_t color, pchar_t lineLimit) {
    return print({String(content).c_str(), color, lineLimit});
}
ParenthLogger &ParenthLogger::operator()(int content, clr_t color, pchar_t lineLimit) {
    return print({String(content).c_str(), color, lineLimit});
}

ParenthLogger &ParenthLogger::print(unsigned int content, clr_t color, pchar_t lineLimit) {
    return print({String(content).c_str(), color, lineLimit});
}
ParenthLogger &ParenthLogger::operator()(unsigned int content, clr_t color, pchar_t lineLimit) {
    return print({String(content).c_str(), color, lineLimit});
}

ParenthLogger &ParenthLogger::print(double content, clr_t color, pchar_t lineLimit) {
    return print({String(content).c_str(), color, lineLimit});
}
ParenthLogger &ParenthLogger::operator()(double content, clr_t color, pchar_t lineLimit) {
    return print({String(content).c_str(), color, lineLimit});
}