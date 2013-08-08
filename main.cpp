#include "engine.h"
#include <GL/glut.h>

Engine game;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    game.run();
    glutSwapBuffers();
}

void on_timer(int value)
{
    if (value == 0) {
        glutTimerFunc(game.get_speed(), on_timer, value);
        display();
    }
}

void normal_key(unsigned char key, int x, int y)
{
    game.normal_key(key, x, y);
}

void special_key(int key, int x, int y)
{
    game.special_key(key, x, y);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(300, 600);
    glutInitWindowPosition(500, 500);
    glutCreateWindow("Tetris-Linzhi");
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 8 * WID, 8 * HEI, 0, 0, 1.0);
    glDisable(GL_DEPTH_TEST);

    glutDisplayFunc(display);
    glutKeyboardFunc(normal_key);
    glutSpecialFunc(special_key);

    glutTimerFunc(game.get_speed(), on_timer, 0);

    glutMainLoop();

    return 0;
}




