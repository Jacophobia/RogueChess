#pragma once

#include <string>

class Piece;

class Square
{
public:
    std::string to_string() const;
    
private:
    Piece* piece;

};
