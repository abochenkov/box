#include "hero.hpp"
#include "field.hpp"
#include <GL/gl.h>


Hero::Hero(void)
{
    x_cord = 10;
    y_cord = Field::HEIGHT - 1;
};

void Hero::draw(void)
{
    glColor3f(0, 0, 1);
	glBegin(GL_QUADS);
	glVertex2f(x_cord * Field::BLOCK_WIDTH, y_cord * Field::BLOCK_HEIGHT);
	glVertex2f((x_cord + 1) * Field::BLOCK_WIDTH, y_cord * Field::BLOCK_HEIGHT);
	glVertex2f( (x_cord + 1) * Field::BLOCK_WIDTH, (y_cord + 1) * Field::BLOCK_HEIGHT);
	glVertex2f(x_cord * Field::BLOCK_WIDTH, (y_cord + 1) * Field::BLOCK_HEIGHT);
	glEnd();
};

void Hero::left(void)
{
    if(x_cord > 0)
        x_cord--;
};

void Hero::right(void)
{
    if(x_cord < (Field::WIDTH - 1))
        x_cord++;
};

int Hero::detect_x_cord(void)
{
    return x_cord;
}

void Hero::fire(void)
{
    if(box.detect_x_cord() == detect_x_cord())
        box.crash();
};
