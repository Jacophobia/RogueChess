#pragma once

enum class Color
{
    black,
    white
};

namespace color
{
    inline const char* to_string(Color e)
    {
        switch (e)
        {
        case Color::black: return "black";
        case Color::white: return "white";
        default: return "unknown";
        }
    }
}
