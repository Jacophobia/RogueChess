#pragma once

enum class Color
{
    white = 0b01,
    black = 0b10
};

namespace color
{
    inline Color rotate_color(Color color)
    {
        constexpr int num_of_colors = 2;
        int binary_color = static_cast<int>(color);
        
        int rotated_binary_color = (binary_color << 1) | (binary_color >> (num_of_colors - 1));

        return static_cast<Color>(rotated_binary_color);
    }
    
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
