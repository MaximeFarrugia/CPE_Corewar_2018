/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** corewar
*/

#ifndef COREWAR_H_
# define COREWAR_H_

# include <SFML/Graphics.hpp>
# include <SFML/OpenGL.hpp>
# include <GL/glut.h>
# include "vm.hpp"

class Corewar
{
public:
    Corewar();
    ~Corewar();

    int init_window();
    int init_opengl();

    int set_running(bool running);
    bool get_running();

    sf::RenderWindow *get_window();

private:
    sf::RenderWindow *window;
    int running;
    vm_t vm;
};

#endif /* !COREWAR_H_ */