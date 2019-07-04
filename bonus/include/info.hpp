/*
** EPITECH PROJECT, 2019
** info
** File description:
** info
*/

#ifndef INFO_H_
# define INFO_H_

#include <SFML/Graphics.hpp>
#include "corewar.hpp"

class Info
{
public:
    Info();
    ~Info();

    int get_winner(vm_t *vm);
    int champ_processes(champ_t *champ);
    int total_processes(vm_t *vm);
    champ_t *get_champ_by_nb(vm_t *vm, int nb);

    int init_values(vm_t *vm);
    int set_position(int x, int y);
    int display_info(sf::RenderWindow *win, vm_t *vm);
    int display_info_values(sf::RenderWindow *win, vm_t *vm);

    int init_winner(vm_t *vm);
    int display_winner(sf::RenderWindow *win);

private:
    sf::Font font;
    sf::Text global;
    sf::Text tcycle;
    sf::Text ctd;
    sf::Text cycled;
    sf::Text nbrlive;
    sf::Text processes;
    sf::Text lastlive;
    sf::Text p1;
    sf::Text p1name;
    sf::Text p1lastlive;
    sf::Text p1nbrlive;
    sf::Text p1processes;
    sf::Text p1status;
    sf::Text p2;
    sf::Text p2name;
    sf::Text p2lastlive;
    sf::Text p2nbrlive;
    sf::Text p2processes;
    sf::Text p2status;
    sf::Text p3;
    sf::Text p3name;
    sf::Text p3lastlive;
    sf::Text p3nbrlive;
    sf::Text p3processes;
    sf::Text p3status;
    sf::Text p4;
    sf::Text p4name;
    sf::Text p4lastlive;
    sf::Text p4nbrlive;
    sf::Text p4processes;
    sf::Text p4status;

    sf::Text tcyclev;
    sf::Text ctdv;
    sf::Text cycledv;
    sf::Text nbrlivev;
    sf::Text processesv;
    sf::Text lastlivev;
    sf::Text p1namev;
    sf::Text p1lastlivev;
    sf::Text p1nbrlivev;
    sf::Text p1processesv;
    sf::Text p1statusv;
    sf::Text p2namev;
    sf::Text p2lastlivev;
    sf::Text p2nbrlivev;
    sf::Text p2processesv;
    sf::Text p2statusv;
    sf::Text p3namev;
    sf::Text p3lastlivev;
    sf::Text p3nbrlivev;
    sf::Text p3processesv;
    sf::Text p3statusv;
    sf::Text p4namev;
    sf::Text p4lastlivev;
    sf::Text p4nbrlivev;
    sf::Text p4processesv;
    sf::Text p4statusv;

    sf::Text winner_name;
    sf::Text winner_text;
};

#endif /* !INFO_H_ */