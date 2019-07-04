/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** cell
*/

#include "../../include/vm.hpp"

int is_pc(vm_t *vm, int x, int y)
{
    for (champ_t *champ = vm->champs; champ; champ = champ->next) {
        for (pc_t *pc = champ->pc; pc; pc = pc->next) {
            if (pc->pc == (x + y * 96))
                return (pc->p->nb);
        }
    }
    return (0);
}

sf::Vector3f get_size(vm_t *vm, int x, int y, float *heights)
{
    if (is_pc(vm, x, y))
        return (sf::Vector3f(10.f, 10.f, 60.f));
    if (!vm->gboard[x + y * 96])
        return (sf::Vector3f(10.f, 10.f, 10.f));
    return (sf::Vector3f(10.f, 10.f, heights[x + y * 96]));
}

sf::Vector3f get_color(vm_t *vm, int x, int y)
{
    sf::Vector3f color;
    int nb = 0;

    if (vm->gboard[x + y * 96] == 1) {
        color.x = 0.5f;
        color.y = 0.f;
        color.z = 0.f;
    }
    else if (vm->gboard[x + y * 96] == 2) {
        color.x = 0.f;
        color.y = 0.f;
        color.z = 0.5f;
    }
    else if (vm->gboard[x + y * 96] == 3) {
        color.x = 0.f;
        color.y = 0.5f;
        color.z = 0.f;
    }
    else if (vm->gboard[x + y * 96] == 4) {
        color.x = 0.5f;
        color.y = 0.5f;
        color.z = 0.f;
    }
    else {
        color.x = 0.5f;
        color.y = 0.5f;
        color.z = 0.5f;
    }
    if ((nb = is_pc(vm, x, y))) {
        if (nb == 1)
            color = (sf::Vector3f){ 1.f, 0.f, 0.f };
        if (nb == 2)
            color = (sf::Vector3f){ 0.f, 0.f, 1.f };
        if (nb == 3)
            color = (sf::Vector3f){ 0.f, 1.f, 0.f };
        if (nb == 4)
            color = (sf::Vector3f){ 1.f, 1.f, 0.f };
    }
    return (color);
}

int draw_cube(sf::Vector3f size, sf::Vector3f color)
{
    glBegin(GL_QUADS);
    glColor3f(color.x, color.y, color.z);
    glVertex3f(0.f, 0.f, 0.f);
    glVertex3f(size.x, 0.f, 0.f);
    glVertex3f(size.x, size.x, 0.f);
    glVertex3f(0.f, size.y, 0.f);

    glColor3f(color.x, color.y, color.z);
    glVertex3f(0.f, 0.f, size.z);
    glVertex3f(size.x, 0.f, size.z);
    glVertex3f(size.x, size.y, size.z);
    glVertex3f(0.f, size.y, size.z);

    glColor3f(color.x, color.y, color.z);
    glVertex3f(0.f, size.y, size.z);
    glVertex3f(size.x, size.y, size.z);
    glVertex3f(size.x, size.y, 0.f);
    glVertex3f(0.f, size.y, 0.f);

    glColor3f(color.x, color.y, color.z);
    glVertex3f(0.f, 0.f, size.z);
    glVertex3f(size.x, 0.f, size.z);
    glVertex3f(size.x, 0.f, 0.f);
    glVertex3f(0.f, 0.f, 0.f);

    glColor3f(color.x, color.y, color.z);
    glVertex3f(0.f, 0.f, 0.f);
    glVertex3f(0.f, 0.f, size.z);
    glVertex3f(0.f, size.y, size.z);
    glVertex3f(0.f, size.y, 0.f);

    glColor3f(color.x, color.y, color.z);
    glVertex3f(size.x, 0.f, 0.f);
    glVertex3f(size.x, 0.f, size.z);
    glVertex3f(size.x, size.y, size.z);
    glVertex3f(size.x, size.y, 0.f);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0, 0, 0);
    glVertex3f(0.f, 0.f, 0.f);
    glVertex3f(size.x, 0.f, 0.f);
    glVertex3f(size.x, size.x, 0.f);
    glVertex3f(0.f, size.y, 0.f);

    glColor3f(0, 0, 0);
    glVertex3f(0.f, 0.f, size.z);
    glVertex3f(size.x, 0.f, size.z);
    glVertex3f(size.x, size.y, size.z);
    glVertex3f(0.f, size.y, size.z);

    glColor3f(0, 0, 0);
    glVertex3f(0.f, size.y, size.z);
    glVertex3f(size.x, size.y, size.z);
    glVertex3f(size.x, size.y, 0.f);
    glVertex3f(0.f, size.y, 0.f);

    glColor3f(0, 0, 0);
    glVertex3f(0.f, 0.f, size.z);
    glVertex3f(size.x, 0.f, size.z);
    glVertex3f(size.x, 0.f, 0.f);
    glVertex3f(0.f, 0.f, 0.f);

    glColor3f(0, 0, 0);
    glVertex3f(0.f, 0.f, 0.f);
    glVertex3f(0.f, 0.f, size.z);
    glVertex3f(0.f, size.y, size.z);
    glVertex3f(0.f, size.y, 0.f);

    glColor3f(0, 0, 0);
    glVertex3f(size.x, 0.f, 0.f);
    glVertex3f(size.x, 0.f, size.z);
    glVertex3f(size.x, size.y, size.z);
    glVertex3f(size.x, size.y, 0.f);
    glEnd();
    return (0);
}