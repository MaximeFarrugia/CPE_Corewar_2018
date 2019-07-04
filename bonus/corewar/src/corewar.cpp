/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** corewar
*/

#include "../../include/corewar.hpp"

Corewar::Corewar()
{
    init_window();
    init_opengl();
    Corewar::set_running(true);
}

Corewar::~Corewar()
{
    this->window->close();
    delete this->window;
}

int Corewar::init_window()
{
    sf::ContextSettings context = sf::ContextSettings(24, 8, 2, 0, 1);

    this->window = new sf::RenderWindow(sf::VideoMode::getFullscreenModes()[0], "Corewar", sf::Style::Fullscreen, context);
    this->window->setVerticalSyncEnabled(true);
    this->window->setActive(true);
    return (0);
}

int Corewar::init_opengl()
{
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glClearDepth(1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90.0f, 16.0f / 9.0f, 1.0f, 10000.0f);
    return (0);
}

int Corewar::set_running(bool running)
{
    this->running = running;
    return (0);
}

bool Corewar::get_running()
{
    return (this->running);
}

sf::RenderWindow *Corewar::get_window()
{
    return (this->window);
}