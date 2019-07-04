/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** help
*/

#include "../../include/help.hpp"

Help::Help()
{
    this->font = sf::Font();
    this->font.loadFromFile("./font.ttf");
    this->run = sf::Text("V: RUN", this->font, 15);
    this->pause = sf::Text("B: PAUSE", this->font, 15);
    this->sbs = sf::Text("N: STEP BY STEP", this->font, 15);
    this->fwd = sf::Text("W: MOVE FORWARD", this->font, 15);
    this->bwd = sf::Text("S: MOVE BACKWARDS", this->font, 15);
    this->left = sf::Text("Q: MOVE LEFT", this->font, 15);
    this->right = sf::Text("D: MOVE RIGHT", this->font, 15);
    this->up = sf::Text("I: MOVE UP", this->font, 15);
    this->down = sf::Text("K: MOVE DOWN", this->font, 15);
    this->quit = sf::Text("ESCAPE: QUIT", this->font, 15);
    this->pitch_up = sf::Text("UP ARROW: INCREASE PITCH", this->font, 15);
    this->pitch_down = sf::Text("DOWN ARROW: DECREASE PITCH", this->font, 15);
    this->yaw_up = sf::Text("LEFT ARROW: INCREASE YAW", this->font, 15);
    this->yaw_down = sf::Text("RIGHT ARROW: DECREASE YAW", this->font, 15);
    this->roll_up = sf::Text("A: INCREASE ROLL", this->font, 15);
    this->roll_dowm = sf::Text("E: DECREASE ROLL", this->font, 15);
    this->first = sf::Text("R: FIRST VIEW", this->font, 15);
    this->second = sf::Text("T: SECOND VIEW", this->font, 15);
    this->infos = sf::Text("P: TOGGLE GAME INFOS", this->font, 15);

    this->run.setPosition(0, 0);
    this->pause.setPosition(0, 20);
    this->sbs.setPosition(0, 40);
    this->fwd.setPosition(0, 60);
    this->bwd.setPosition(0, 80);
    this->left.setPosition(0, 100);
    this->right.setPosition(0, 120);
    this->up.setPosition(0, 140);
    this->down.setPosition(0, 160);
    this->quit.setPosition(0, 180);
    this->pitch_up.setPosition(0, 200);
    this->pitch_down.setPosition(0, 220);
    this->yaw_up.setPosition(0, 240);
    this->yaw_down.setPosition(0, 260);
    this->roll_up.setPosition(0, 280);
    this->roll_dowm.setPosition(0, 300);
    this->first.setPosition(0, 320);
    this->second.setPosition(0, 340);
    this->infos.setPosition(0, 360);
}

Help::~Help()
{

}

int Help::display_help(sf::RenderWindow *win)
{
    win->draw(this->run);
    win->draw(this->pause);
    win->draw(this->sbs);
    win->draw(this->fwd);
    win->draw(this->bwd);
    win->draw(this->left);
    win->draw(this->right);
    win->draw(this->up);
    win->draw(this->down);
    win->draw(this->quit);
    win->draw(this->pitch_up);
    win->draw(this->pitch_down);
    win->draw(this->yaw_up);
    win->draw(this->yaw_down);
    win->draw(this->roll_up);
    win->draw(this->roll_dowm);
    win->draw(this->first);
    win->draw(this->second);
    win->draw(this->infos);
    return (0);
}