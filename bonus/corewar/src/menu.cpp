/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** menu
*/

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include "../../include/vm.hpp"

sf::Vector3f menu_size(int x, int y, float *heights, unsigned char *map)
{
    if (map[x + y * 96] == '0')
        return (sf::Vector3f(10.f, 10.f, 10.f));
    return (sf::Vector3f(10.f, 10.f, heights[x + y * 96]));
}

sf::Vector3f menu_color(int x, int y, unsigned char *map)
{
    sf::Vector3f color;

    if (map[x + y * 96] == '1') {
        color.x = 1.f;
        color.y = 0.f;
        color.z = 0.f;
    }
    else if (map[x + y * 96] == '2') {
        color.x = 0.f;
        color.y = 0.f;
        color.z = 1.f;
    }
    else if (map[x + y * 96] == '3') {
        color.x = 0.f;
        color.y = 1.f;
        color.z = 0.f;
    }
    else if (map[x + y * 96] == '4') {
        color.x = 1.f;
        color.y = 1.f;
        color.z = 0.f;
    }
    else if (map[x + y * 96] == '5') {
        color.x = 1.f;
        color.y = 1.f;
        color.z = 1.f;
    }
    else {
        color.x = 0.5f;
        color.y = 0.5f;
        color.z = 0.5f;
    }
    return (color);
}

int draw_menu(sf::RenderWindow *win, vm_t *vm, unsigned char *map)
{
    float heights[MEM_SIZE] = { 0.f };
    sf::Font font = sf::Font();
    sf::Text text;
    sf::FloatRect rect;

    font.loadFromFile("font.ttf");
    text = sf::Text("Press [SPACE] to launch the game.", font, 30);
    rect = text.getLocalBounds();
    text.setOrigin(rect.left + rect.width / 2.f, rect.top + rect.height / 2.f);
    text.setPosition(1920 / 2.f, 800.f);
    for (int i = 0; i < MEM_SIZE; ++i) {
        if (map[i] != '0')
            heights[i] = rand() % (40 - 20) + 20;
    }
    sf::Clock clock;
    clock.restart();
    while (1) {
        sf::Event event;
        while (win->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                return (42);
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                return (42);
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
                return (0);
        }
        win->clear();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(-750.f, 700.f, -840.f);
        glRotatef(-10.f, 1.f, 0.f, 0.f);
        if (clock.getElapsedTime().asSeconds() >= 0.5) {
            for (int i = 0; i < MEM_SIZE; ++i) {
                heights[i] = rand() % (40 - 20) + 20;
            }
            clock.restart();
        }
        for (int i = 0; i < 64; ++i) {
            for (int j = 0; j < 96; ++j) {
                if (map[j + i * 96] != '0') {
                    glPushMatrix();
                    glTranslatef(j * 15, -i * 15, 0.f);
                    draw_cube(menu_size(j, i, heights, map), menu_color(j, i, map));
                    glPopMatrix();
                }
            }
        }
        win->pushGLStates();
        win->draw(text);
        win->popGLStates();
        win->display();
    }
    return (0);
}

int menu(vm_t *vm, sf::RenderWindow *win)
{
    unsigned char map[6144];
    int fd = open(".menu.menu", O_RDONLY);

    read(fd, map, 6144);
    close(fd);
    return (draw_menu(win, vm, map));
}