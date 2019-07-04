/*
** EPITECH PROJECT, 2019
** help
** File description:
** help
*/

#ifndef HELP_H_
# define HELP_H_

#include <SFML/Graphics.hpp>

class Help
{
public:
    Help();
    ~Help();

    int display_help(sf::RenderWindow *win);

private:
    sf::Font font;
    sf::Text run;
    sf::Text pause;
    sf::Text sbs;
    sf::Text fwd;
    sf::Text bwd;
    sf::Text left;
    sf::Text right;
    sf::Text up;
    sf::Text down;
    sf::Text quit;
    sf::Text pitch_up;
    sf::Text pitch_down;
    sf::Text yaw_up;
    sf::Text yaw_down;
    sf::Text roll_up;
    sf::Text roll_dowm;
    sf::Text first;
    sf::Text second;
    sf::Text infos;
};

#endif /* !HELP_H_ */