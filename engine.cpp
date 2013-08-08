#include "engine.h"
#include <cstdlib>
#include <ctime>

Engine::Engine() : speed(250)
{
    srand(time(NULL));
}

Engine::~Engine()
{

}

void Engine::run()
{
    __tetris.remove_line();

    __tetris.draw_grid();
    __tetris.draw_tetris();

    __tetris.move_down();

    if (__tetris.over())
        __tetris.restart();
}

int Engine::get_speed()
{
    return speed;
}

void Engine::normal_key(unsigned char key, int x, int y)
{
    switch (key) {
        // press ESC key to exit game
        case 27:
            exit(EXIT_SUCCESS);
            break;
        // press space key to restart game
        case 32:
            __tetris.restart();
            break;
        default:
            break;
    }
}

void Engine::special_key(int key, int x, int y)
{
    switch (key) {
        case GLUT_KEY_UP:
            __tetris.rotate();
            break;
        case GLUT_KEY_DOWN:
            __tetris.move_down();
            break;
        case GLUT_KEY_LEFT:
            __tetris.move_left();
            break;
        case GLUT_KEY_RIGHT:
            __tetris.move_right();
            break;
        default:
            break;
    }
}





