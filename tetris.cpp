#include "tetris.h"
#include <cstdlib>
#include <ctime>
#include <cstring>

// I shape
const int __shape_I[4][4] = {
    {0, 1, 0, 0},
    {0, 1, 0, 0},
    {0, 1, 0, 0},
    {0, 1, 0, 0},
};

// J shape
const int __shape_J[4][4] = {
    {0, 0, 1, 0},
    {0, 0, 1, 0},
    {0, 1, 1, 0},
    {0, 0, 0, 0},
};

// L shape
const int __shape_L[4][4] = {
    {0, 1, 0, 0},
    {0, 1, 0, 0},
    {0, 1, 1, 0},
    {0, 0, 0, 0},
};

// O shape
const int __shape_O[4][4] = {
    {0, 0, 0, 0},
    {0, 1, 1, 0},
    {0, 1, 1, 0},
    {0, 0, 0, 0},
};

// S shape
const int __shape_S[4][4] = {
    {0, 0, 0, 0},
    {0, 1, 1, 0},
    {1, 1, 0, 0},
    {0, 0, 0, 0},
};

// T shape
const int __shape_T[4][4] = {
    {0, 0, 0, 0},
    {1, 1, 1, 0},
    {0, 1, 0, 0},
    {0, 0, 0, 0},
};

// Z shape
const int __shape_Z[4][4] = {
    {0, 0, 0, 0},
    {1, 1, 0, 0},
    {0, 1, 1, 0},
    {0, 0, 0, 0},
};

Tetris::Tetris() : r(0.0), g(0.0), b(0.0), __x(3), __y(0)
{
    __shape[4][4] = {0};
    __grid[HEI][WID] = {0};

    rand_tetris();
}

Tetris::~Tetris()
{

}

void Tetris::rand_tetris()
{
    switch (rand() % 7) {
        case 0:
            memcpy(__shape, __shape_I, 4 * 4 * sizeof(int));
            r = 0.0;
            g = 1.0;
            b = 1.0;
            break;
        case 1:
            memcpy(__shape, __shape_J, 4 * 4 * sizeof(int));
            r = 0.0;
            g = 1.0;
            b = 0.0;
            break;
        case 2:
            memcpy(__shape, __shape_L, 4 * 4 * sizeof(int));
            r = 0.0;
            g = 0.0;
            b = 1.0;
            break;
        case 3:
            memcpy(__shape, __shape_O, 4 * 4 * sizeof(int));
            r = 1.0;
            g = 1.0;
            b = 0.0;
            break;
        case 4:
            memcpy(__shape, __shape_S, 4 * 4 * sizeof(int));
            r = 1.0;
            g = 0.0;
            b = 1.0;
            break;
        case 5:
            memcpy(__shape, __shape_T, 4 * 4 * sizeof(int));
            r = 1.0;
            g = 0.0;
            b = 0.0;
            break;
        case 6:
            memcpy(__shape, __shape_Z, 4 * 4 * sizeof(int));
            r = 1.0;
            g = 0.5;
            b = 1.0;
            break;
    }
}

void Tetris::draw_grid()
{
    for (int i = 0; i < WID * 8; i += 8) {
        glColor3f(0.0, 0.0, 0.0); 
        glBegin(GL_LINES);
        glVertex2f(i, 0);
        glVertex2f(i, HEI * 8);
        glEnd();
    }

    for (int j = 0; j < HEI * 8; j += 8) {
        glColor3f(0.0, 0.0, 0.0); 
        glBegin(GL_LINES);
        glVertex2f(0, j);
        glVertex2f(WID * 8, j);
        glEnd();
    }

    for (int i = 0; i < HEI; i++) {
        for (int j = 0; j < WID; j++) {
            if (__grid[i][j] == 1) {
                int x_1 = j * 8; 
                int y_1 = i * 8;
                int x_2 = x_1 + 8;
                int y_2 = y_1 + 8;

                glColor3f(0.0, 0.0, 0.0);
                glBegin(GL_QUADS);
                glVertex2f(x_1, y_1);
                glVertex2f(x_2, y_1);
                glVertex2f(x_2, y_2);
                glVertex2f(x_1, y_2);
                glEnd();

                glColor3f(1.0, 1.0, 1.0);
                glBegin(GL_LINE_LOOP);
                glVertex2f(x_1, y_1);
                glVertex2f(x_2, y_1);
                glVertex2f(x_2, y_2);
                glVertex2f(x_1, y_2);
                glEnd();
            }
        }
    }
}

void Tetris::draw_tetris()
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (__shape[i][j] == 1) {
                int x_1 = (j + __x) * 8;
                int y_1 = (i + __y) * 8;
                int x_2 = x_1 + 8;
                int y_2 = y_1 + 8;

                glColor3f(r, g, b);
                glBegin(GL_QUADS);
                glVertex2f(x_1, y_1);
                glVertex2f(x_2, y_1);
                glVertex2f(x_2, y_2);
                glVertex2f(x_1, y_2);
                glEnd();

                glColor3f(0.0, 0.0, 0.0);
                glBegin(GL_LINE_LOOP);
                glVertex2f(x_1, y_1);
                glVertex2f(x_2, y_1);
                glVertex2f(x_2, y_2);
                glVertex2f(x_1, y_2);
                glEnd();
            }
        }
    }
}

int Tetris::collision()
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (__shape[i][j] == 1) {
                int x_1 = __x + j; 
                int y_1 = __y + i;

                // hit the wall
                if (x_1 < 0 || x_1 >= WID)
                    return 1;

                // hit the floor or other block
                else if (y_1 >= HEI || __grid[y_1][x_1] == 1)
                    return 2;
            }
        }
    }

    return -1;
}

void Tetris::update()
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (__shape[i][j] == 1)     
                __grid[__y + i][__x + j] = 1;
        }
    }

    __x = 3;
    __y = 0;

    rand_tetris();
}

void Tetris::rotate()
{
    int tmp[4][4] = {0};

    memcpy(tmp, __shape, 4 * 4 * sizeof(int));

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            __shape[i][j] = tmp[3 - j][i];
        }
    }

    // if collision then don't rotate the block
    if (collision() != -1)
        memcpy(__shape, tmp, 4 * 4 * sizeof(int));
}

void Tetris::remove_line()
{
    for (int i = HEI - 1; i > 0; i--) {
        int count = 0;

        for (int j = 0; j < WID; j++) {
            if (__grid[i][j] == 1)     
                count++;
        }

        if (count == 10) {
            for (int t = i; t > 0; t--) {
                for (int k = 0; k < WID; k++)
                    __grid[t][k] = __grid[t - 1][k];
            }
        }
    }
}

bool Tetris::over()
{
    for (int i = 0; i < WID; i++)
        if (__grid[4][i] == 1)
            return true;

    return false;
}

void Tetris::restart()
{
    for (int i = 0; i < HEI; i++) {
        for (int j = 0; j < WID; j++) {
            __grid[i][j] = 0;
        }
    }

    __x = 3;
    __y = 0;

    rand_tetris();
}

void Tetris::move_down()
{
    __y++; 

    // collision
    if (collision() == 2) {
        __y--;
        update();
    }
}

void Tetris::move_left()
{
    __x--;

    // collision
    if (collision() != -1)
        __x++;
}

void Tetris::move_right()
{
    __x++;

    // collision
    if (collision() != -1)
        __x--;
}

int Tetris::get_x()
{
    return __y;
}

int Tetris::get_y()
{
    return __x;
}



