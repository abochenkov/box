#include <iostream>
#include <GL/glut.h>
#include <cstdlib>
#include "field.hpp"
#include "box.hpp"
#include "hero.hpp"


Hero hero;

void display()
{
  glClear(GL_COLOR_BUFFER_BIT);
  
  hero.draw();
  hero.box.draw();
  glutSwapBuffers();
}

void timer(int = 0)
{
  display();
  glutTimerFunc(300, timer, 0);
}

void specialKeyEvent(int key, int, int)
{
  switch (key)
  {
  case GLUT_KEY_LEFT:
    //
    hero.left();
    break;
  case GLUT_KEY_UP:
    
    break;
  case GLUT_KEY_RIGHT:
    hero.right();
    break;
  case GLUT_KEY_DOWN:
    
    break;
  }
}

void normalKeyEvent(unsigned char key, int, int)
{
  switch (key)
  {
  case ' ':
    hero.fire();
    break;
  }
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(Field::WIDTH * Field::BLOCK_WIDTH, 
		    Field::HEIGHT * Field::BLOCK_HEIGHT);
  glutInitWindowPosition(100, 780);
  glutCreateWindow("Box");
  glClearColor(0, 0, 0, 1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, Field::WIDTH * Field::BLOCK_WIDTH, 
	  Field::HEIGHT * Field::BLOCK_HEIGHT, 0, 
	  -1.0, 1.0);
  glutDisplayFunc(display);
  glutSpecialFunc(specialKeyEvent);
  glutKeyboardFunc(normalKeyEvent);
  timer();

  glutMainLoop();
}