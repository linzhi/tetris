#ifndef __ENGINE_H__
#define __ENGINE_H__

#include "tetris.h"
#include <GL/glut.h>

class Engine {
public:
    Engine();
    ~Engine();

    void run();

    // set normal key, such as ESC Space and so on
    void normal_key(unsigned char key, int x, int y);

    // set special key using glut
    void special_key(int key, int x, int y);

    int get_speed();

private:
    int speed;

    Tetris __tetris;
};

#endif



