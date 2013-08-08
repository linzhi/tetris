#ifndef __TETRIS_H__
#define __TETRIS_H__

#include <GL/glut.h>

#define HEI 20
#define WID 10

class Tetris {
public:
    Tetris();        
    ~Tetris();

    void rand_tetris();

    // draw grid of Tetris
    void draw_grid();

    // draw seven difformity block
    void draw_tetris();

    // if the block collide a wall return 1, otherwise return 2
    int collision();

    bool over();

    void restart();

    void rotate();

    void remove_line();

    void move_left();
    void move_right();
    void move_down();

    int get_x();
    int get_y();

private:
    void update();

    GLfloat r;
    GLfloat g;
    GLfloat b;

    int __x;
    int __y;

    int __grid[HEI][WID];

    int __shape[4][4];
};

#endif





