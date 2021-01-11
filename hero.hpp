#pragma once
#include "box.hpp"

class Hero
{
public:
    Box box;
    Hero(void);
    void draw(void);
    void left(void);
    void right(void);
    int detect_x_cord(void);
    void fire(void);
private:
    int x_cord{0};
    int y_cord{0};
};