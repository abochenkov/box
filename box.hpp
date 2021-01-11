#pragma once
#include <cstdlib>

class Box
{
public:
    Box();
    void draw(void);
    void gameover(void);
    void crash(void);
    int detect_x_cord(void);
private:
    int y_cord{0};
    int x_cord{0};
};