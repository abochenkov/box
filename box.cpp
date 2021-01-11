#include "box.hpp"
#include "field.hpp"
#include <GL/gl.h>

Box::Box()
{
	x_cord = rand() % 20 ;
	 
}

void Box::draw(void)
{
	
	glColor3f(0, 1, 0);
	glBegin(GL_QUADS);
	glVertex2f(x_cord * Field::BLOCK_WIDTH, y_cord * Field::BLOCK_HEIGHT);
	glVertex2f((x_cord + 1) * Field::BLOCK_WIDTH, y_cord * Field::BLOCK_HEIGHT);
	glVertex2f( (x_cord + 1) * Field::BLOCK_WIDTH, (y_cord + 1) * Field::BLOCK_HEIGHT);
	glVertex2f(x_cord * Field::BLOCK_WIDTH, (y_cord + 1) * Field::BLOCK_HEIGHT);
	glEnd();
   
    y_cord++; 

	Box::gameover();
}

void Box::gameover(void)
{
	if(y_cord > Field::HEIGHT )
	{
		exit(1);
	}
	
}

void Box::crash(void)
{
	x_cord = rand() % 20;
	y_cord = 0;
}

int Box::detect_x_cord(void)
{
	return x_cord;
}