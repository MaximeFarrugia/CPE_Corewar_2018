/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "../../include/vm.hpp"
#include "../../include/corewar.hpp"
#include "../../include/help.hpp"
#include "../../include/info.hpp"

int main(int ac, char **av)
{
    Corewar cw = Corewar();
    vm_t vm;
    Help help = Help();
    Info info = Info();

    if (menu(&vm, cw.get_window()) == 42)
        cw.set_running(false);
    init_struct(&vm);
    if (create_list(ac, av, &vm))
        return (my_free_exit(&vm, 84));
    float roll = 0.f;
    float dist = -1060.f;
    float pitch = -40.f;
    float side = -700.f;
    float yaw = 0.f;
    float pos = 500.f;
    int pause = 1;
    int step = 0;
    int dinfos = 1;
    int view = 0;
    float heights[MEM_SIZE] = { 0.f };
    for (int i = 0; i < MEM_SIZE; ++i) {
        if (vm.gboard[i])
            heights[i] = rand() % (40 - 20) + 20;
    }
    sf::Clock clock;
    clock.restart();
    while (cw.get_running()) {
        sf::Event event;
        while (cw.get_window()->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                cw.set_running(false);
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::A)
                roll += 5;
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::E)
                roll -= 5;
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::W)
                dist += 20;
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S)
                dist -= 20;
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Q)
                side += 20;
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::D)
                side -= 20;
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down)
                pitch += 5;
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up)
                pitch -= 5;
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right)
                yaw += 5;
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left)
                yaw -= 5;
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::I)
                pos -= 20;
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::K)
                pos += 20;
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R) {
                roll = 0.f;
                dist = -1060.f;
                pitch = -40.f;
                side = -700.f;
                yaw = 0.f;
                pos = 500.f;
                view = 0;
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::T) {
                roll = 0.f;
                dist = -1300.f;
                pitch = -40.f;
                side = 460.f;
                yaw = -90.f;
                pos = 760.f;
                view = 1;
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::V) {
                pause = 0;
                break;
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::B) {
                pause = 1;
                break;
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::N) {
                step = 1;
                break;
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                cw.set_running(false);
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P)
                dinfos = !dinfos;
        }
        cw.get_window()->clear();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(side, pos, dist);
        glRotatef(pitch, 1.f, 0.f, 0.f);
        glRotatef(roll, 0.f, 1.f, 0.f);
        glRotatef(yaw, 0.f, 0.f, 1.f);
        if (clock.getElapsedTime().asSeconds() >= 0.5) {
            for (int i = 0; i < MEM_SIZE; ++i) {
                heights[i] = rand() % (40 - 20) + 20;
            }
            clock.restart();
        }
        for (int i = 0; i < 64; ++i) {
            for (int j = 0; j < 96; ++j) {
                glPushMatrix();
                glTranslatef(j * 15, -i * 15, 0.f);
                draw_cube(get_size(&vm, j, i, heights), get_color(&vm, j, i));
                glPopMatrix();
            }
        }
        if (cw.get_running() && !is_game_over(&vm) && (!pause || step)) {
            if (vm.dump != -1 && vm.cycle == vm.dump)
                cw.set_running(false);
            get_opcodes(&vm);
            exec_opcodes(&vm);
            check_death(&vm);
            vm.cycle += 1;
            step = 0;
        }
        cw.get_window()->pushGLStates();
        help.display_help(cw.get_window());
        if (dinfos) {
            info.set_position(300, view ? 940 : 0);
            info.display_info(cw.get_window(), &vm);
            if (is_game_over(&vm)) {
                info.init_winner(&vm);
                info.display_winner(cw.get_window());
            }
        }
        cw.get_window()->popGLStates();
        cw.get_window()->display();
    }
    return (0);
}