#ifndef __PARENTH_LOGGER_STYLE_H__
#define __PARENTH_LOGGER_STYLE_H__

namespace ansi_style
{
    constexpr const char *black = "\033[0;30m";
    constexpr const char *red = "\033[0;31m";
    constexpr const char *green = "\033[0;32m";
    constexpr const char *yellow = "\033[0;33m";
    constexpr const char *blue = "\033[0;34m";
    constexpr const char *magenta = "\033[0;35m";
    constexpr const char *cyan = "\033[0;36m";
    constexpr const char *white = "\033[0;37m";

    constexpr const char *black_bold = "\033[1;30m";
    constexpr const char *red_bold = "\033[1;31m";
    constexpr const char *green_bold = "\033[1;32m";
    constexpr const char *yellow_bold = "\033[1;33m";
    constexpr const char *blue_bold = "\033[1;34m";
    constexpr const char *magenta_bold = "\033[1;35m";
    constexpr const char *cyan_bold = "\033[1;36m";
    constexpr const char *white_bold = "\033[1;37m";

    constexpr const char *black_italic = "\033[3;30m";
    constexpr const char *red_italic = "\033[3;33m";
    constexpr const char *green_italic = "\033[3;32m";
    constexpr const char *yellow_italic = "\033[3;33m";
    constexpr const char *blue_italic = "\033[3;34m";
    constexpr const char *magenta_italic = "\033[3;35m";
    constexpr const char *cyan_italic = "\033[3;36m";
    constexpr const char *white_italic = "\033[3;37m";

    constexpr const char *black_underline = "\033[4;30m";
    constexpr const char *red_underline = "\033[4;31m";
    constexpr const char *green_underline = "\033[4;32m";
    constexpr const char *yellow_underline = "\033[4;33m";
    constexpr const char *blue_underline = "\033[4;34m";
    constexpr const char *magenta_underline = "\033[4;35m";
    constexpr const char *cyan_underline = "\033[4;36m";
    constexpr const char *white_underline = "\033[4;37m";
}

#endif