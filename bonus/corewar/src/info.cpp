/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** info
*/

#include "../../include/info.hpp"

Info::Info()
{
    this->font = sf::Font();
    this->font.loadFromFile("./font.ttf");
    this->global = sf::Text("GLOBAL INFORMATIONS", this->font, 12);
    this->global.setFillColor(sf::Color(255, 0, 255, 255));
    this->tcycle = sf::Text("Total cycles:", this->font, 12);
    this->ctd = sf::Text("Cycle to die:", this->font, 12);
    this->cycled = sf::Text("Cycle delta:", this->font, 12);
    this->nbrlive = sf::Text("Nbr live:", this->font, 12);
    this->processes = sf::Text("Processes:", this->font, 12);
    this->lastlive = sf::Text("Last live:", this->font, 12);
    this->p1 = sf::Text("PLAYER 1", this->font, 12);
    this->p1.setFillColor(sf::Color(255, 0, 0, 255));
    this->p1name = sf::Text("Name:", this->font, 12);
    this->p1lastlive = sf::Text("Last live:", this->font, 12);
    this->p1nbrlive = sf::Text("Nbr live:", this->font, 12);
    this->p1processes = sf::Text("Processes:", this->font, 12);
    this->p1status = sf::Text("Status:", this->font, 12);
    this->p2 = sf::Text("PLAYER 2", this->font, 12);
    this->p2.setFillColor(sf::Color(0, 0, 255, 255));
    this->p2name = sf::Text("Name:", this->font, 12);
    this->p2lastlive = sf::Text("Last live:", this->font, 12);
    this->p2nbrlive = sf::Text("Nbr live:", this->font, 12);
    this->p2processes = sf::Text("Processes:", this->font, 12);
    this->p2status = sf::Text("Status:", this->font, 12);
    this->p3 = sf::Text("PLAYER 3", this->font, 12);
    this->p3.setFillColor(sf::Color(0, 255, 0, 255));
    this->p3name = sf::Text("Name:", this->font, 12);
    this->p3lastlive = sf::Text("Last live:", this->font, 12);
    this->p3nbrlive = sf::Text("Nbr live:", this->font, 12);
    this->p3processes = sf::Text("Processes:", this->font, 12);
    this->p3status = sf::Text("Status:", this->font, 12);
    this->p4 = sf::Text("PLAYER 4", this->font, 12);
    this->p4.setFillColor(sf::Color(255, 255, 0, 255));
    this->p4name = sf::Text("Name:", this->font, 12);
    this->p4lastlive = sf::Text("Last live:", this->font, 12);
    this->p4nbrlive = sf::Text("Nbr live:", this->font, 12);
    this->p4processes = sf::Text("Processes:", this->font, 12);
    this->p4status = sf::Text("Status:", this->font, 12);

    this->tcyclev = sf::Text("", this->font, 12);
    this->tcyclev.setFillColor(sf::Color(255, 0, 255, 255));
    this->ctdv = sf::Text("", this->font, 12);
    this->ctdv.setFillColor(sf::Color(255, 0, 255, 255));
    this->cycledv = sf::Text("", this->font, 12);
    this->cycledv.setFillColor(sf::Color(255, 0, 255, 255));
    this->nbrlivev = sf::Text("", this->font, 12);
    this->nbrlivev.setFillColor(sf::Color(255, 0, 255, 255));
    this->processesv = sf::Text("", this->font, 12);
    this->processesv.setFillColor(sf::Color(255, 0, 255, 255));
    this->lastlivev = sf::Text("", this->font, 12);
    this->lastlivev.setFillColor(sf::Color(255, 0, 255, 255));
    this->p1namev = sf::Text("", this->font, 12);
    this->p1namev.setFillColor(sf::Color(255, 0, 0, 255));
    this->p1lastlivev = sf::Text("", this->font, 12);
    this->p1lastlivev.setFillColor(sf::Color(255, 0, 0, 255));
    this->p1nbrlivev = sf::Text("", this->font, 12);
    this->p1nbrlivev.setFillColor(sf::Color(255, 0, 0, 255));
    this->p1processesv = sf::Text("", this->font, 12);
    this->p1processesv.setFillColor(sf::Color(255, 0, 0, 255));
    this->p1statusv = sf::Text("", this->font, 12);
    this->p1statusv.setFillColor(sf::Color(255, 0, 0, 255));
    this->p2namev = sf::Text("", this->font, 12);
    this->p2namev.setFillColor(sf::Color(0, 0, 255, 255));
    this->p2lastlivev = sf::Text("", this->font, 12);
    this->p2lastlivev.setFillColor(sf::Color(0, 0, 255, 255));
    this->p2nbrlivev = sf::Text("", this->font, 12);
    this->p2nbrlivev.setFillColor(sf::Color(0, 0, 255, 255));
    this->p2processesv = sf::Text("", this->font, 12);
    this->p2processesv.setFillColor(sf::Color(0, 0, 255, 255));
    this->p2statusv = sf::Text("", this->font, 12);
    this->p2statusv.setFillColor(sf::Color(0, 0, 255, 255));
    this->p3namev = sf::Text("", this->font, 12);
    this->p3namev.setFillColor(sf::Color(0, 255, 0, 255));
    this->p3lastlivev = sf::Text("", this->font, 12);
    this->p3lastlivev.setFillColor(sf::Color(0, 255, 0, 255));
    this->p3nbrlivev = sf::Text("", this->font, 12);
    this->p3nbrlivev.setFillColor(sf::Color(0, 255, 0, 255));
    this->p3processesv = sf::Text("", this->font, 12);
    this->p3processesv.setFillColor(sf::Color(0, 255, 0, 255));
    this->p3statusv = sf::Text("", this->font, 12);
    this->p3statusv.setFillColor(sf::Color(0, 255, 0, 255));
    this->p4namev = sf::Text("", this->font, 12);
    this->p4namev.setFillColor(sf::Color(255, 255, 0, 255));
    this->p4lastlivev = sf::Text("", this->font, 12);
    this->p4lastlivev.setFillColor(sf::Color(255, 255, 0, 255));
    this->p4nbrlivev = sf::Text("", this->font, 12);
    this->p4nbrlivev.setFillColor(sf::Color(255, 255, 0, 255));
    this->p4processesv = sf::Text("", this->font, 12);
    this->p4processesv.setFillColor(sf::Color(255, 255, 0, 255));
    this->p4statusv = sf::Text("", this->font, 12);
    this->p4statusv.setFillColor(sf::Color(255, 255, 0, 255));

    this->winner_name = sf::Text("", this->font, 54);
    this->winner_text = sf::Text("", this->font, 72);
}

Info::~Info()
{

}

int Info::get_winner(vm_t *vm)
{
    int last_live = 0;
    champ_t *tmp = vm->champs;

    while (tmp) {
        if (tmp->last_live > last_live)
            last_live = tmp->last_live;
        tmp = tmp->next;
    }
    tmp = vm->champs;
    while (tmp) {
        if (last_live && tmp->last_live == last_live) {
            return (tmp->nb);
        }
        tmp = tmp->next;
    }
    return (0);
}

int Info::champ_processes(champ_t *champ)
{
    pc_t *tmp = champ->pc;
    int count = 0;

    while (tmp) {
        count += 1;
        tmp = tmp->next;
    }
    return (count);
}

int Info::total_processes(vm_t *vm)
{
    champ_t *champ = vm->champs;
    pc_t *pc = champ->pc;
    int count = 0;

    while (champ) {
        pc = champ->pc;
        while (pc) {
            count += 1;
            pc = pc->next;
        }
        champ = champ->next;
    }
    return (count);
}

champ_t *Info::get_champ_by_nb(vm_t *vm, int nb)
{
    champ_t *tmp = vm->champs;

    while (tmp && tmp->nb != nb)
        tmp = tmp->next;
    return (tmp);
}

int Info::init_values(vm_t *vm)
{
    int winner = 0;

    if (is_game_over(vm))
        winner = get_winner(vm);
    this->tcyclev.setString(std::to_string(vm->cycle));
    this->ctdv.setString(std::to_string(vm->cycle_to_die));
    this->cycledv.setString(std::to_string(CYCLE_DELTA));
    this->nbrlivev.setString(std::to_string(vm->lives));
    this->processesv.setString(std::to_string(total_processes(vm)));
    if (vm->last_live) {
        this->lastlivev.setString(get_champ_by_nb(vm, vm->last_live)->name);
        if (vm->last_live == 1)
            this->lastlivev.setFillColor(sf::Color(255, 0, 0, 255));
        if (vm->last_live == 2)
            this->lastlivev.setFillColor(sf::Color(0, 0, 255, 255));
        if (vm->last_live == 3)
            this->lastlivev.setFillColor(sf::Color(0, 255, 0, 255));
        if (vm->last_live == 4)
            this->lastlivev.setFillColor(sf::Color(255, 255, 0, 255));
    }
    if (get_champ_by_nb(vm, 1))
        this->p1namev.setString(get_champ_by_nb(vm, 1)->name);
    if (get_champ_by_nb(vm, 1))
        this->p1lastlivev.setString(std::to_string(get_champ_by_nb(vm, 1)->last_live));
    if (get_champ_by_nb(vm, 1))
        this->p1nbrlivev.setString(std::to_string(get_champ_by_nb(vm, 1)->total_lives));
    if (get_champ_by_nb(vm, 1))
        this->p1processesv.setString(std::to_string(champ_processes(get_champ_by_nb(vm, 1))));
    if (get_champ_by_nb(vm, 1)) {
        if (!winner) {
            this->p1statusv.setString(get_champ_by_nb(vm, 1)->dead ? "Dead" : "Alive");
            this->p1statusv.setFillColor(get_champ_by_nb(vm, 1)->dead ? sf::Color(255, 0, 0, 255) : sf::Color(0, 255, 0, 255));
        } else {
            this->p1statusv.setString(winner == 1 ? "Winner" : "Loser");
            this->p1statusv.setFillColor(winner == 1 ? sf::Color(255, 255, 0, 255) : sf::Color(255, 0, 0, 255));
        }
    }
    if (get_champ_by_nb(vm, 2))
        this->p2namev.setString(get_champ_by_nb(vm, 2)->name);
    if (get_champ_by_nb(vm, 2))
        this->p2lastlivev.setString(std::to_string(get_champ_by_nb(vm, 2)->last_live));
    if (get_champ_by_nb(vm, 2))
        this->p2nbrlivev.setString(std::to_string(get_champ_by_nb(vm, 2)->total_lives));
    if (get_champ_by_nb(vm, 2))
        this->p2processesv.setString(std::to_string(champ_processes(get_champ_by_nb(vm, 2))));
    if (get_champ_by_nb(vm, 2)) {
        if (!winner) {
            this->p2statusv.setString(get_champ_by_nb(vm, 2)->dead ? "Dead" : "Alive");
            this->p2statusv.setFillColor(get_champ_by_nb(vm, 2)->dead ? sf::Color(255, 0, 0, 255) : sf::Color(0, 255, 0, 255));
        } else {
            this->p2statusv.setString(winner == 2 ? "Winner" : "Loser");
            this->p2statusv.setFillColor(winner == 2 ? sf::Color(255, 255, 0, 255) : sf::Color(255, 0, 0, 255));
        }
    }
    if (get_champ_by_nb(vm, 3))
        this->p3namev.setString(get_champ_by_nb(vm, 3)->name);
    if (get_champ_by_nb(vm, 3))
        this->p3lastlivev.setString(std::to_string(get_champ_by_nb(vm, 3)->last_live));
    if (get_champ_by_nb(vm, 3))
        this->p3nbrlivev.setString(std::to_string(get_champ_by_nb(vm, 3)->total_lives));
    if (get_champ_by_nb(vm, 3))
        this->p3processesv.setString(std::to_string(champ_processes(get_champ_by_nb(vm, 3))));
    if (get_champ_by_nb(vm, 3)) {
        if (!winner) {
            this->p3statusv.setString(get_champ_by_nb(vm, 3)->dead ? "Dead" : "Alive");
            this->p3statusv.setFillColor(get_champ_by_nb(vm, 3)->dead ? sf::Color(255, 0, 0, 255) : sf::Color(0, 255, 0, 255));
        } else {
            this->p3statusv.setString(winner == 3 ? "Winner" : "Loser");
            this->p3statusv.setFillColor(winner == 3 ? sf::Color(255, 255, 0, 255) : sf::Color(255, 0, 0, 255));
        }
    }
    if (get_champ_by_nb(vm, 4))
        this->p4namev.setString(get_champ_by_nb(vm, 4)->name);
    if (get_champ_by_nb(vm, 4))
        this->p4lastlivev.setString(std::to_string(get_champ_by_nb(vm, 4)->last_live));
    if (get_champ_by_nb(vm, 4))
        this->p4nbrlivev.setString(std::to_string(get_champ_by_nb(vm, 4)->total_lives));
    if (get_champ_by_nb(vm, 4))
        this->p4processesv.setString(std::to_string(champ_processes(get_champ_by_nb(vm, 4))));
    if (get_champ_by_nb(vm, 4)) {
        if (!winner) {
            this->p4statusv.setString(get_champ_by_nb(vm, 4)->dead ? "Dead" : "Alive");
            this->p4statusv.setFillColor(get_champ_by_nb(vm, 4)->dead ? sf::Color(255, 0, 0, 255) : sf::Color(0, 255, 0, 255));
        } else {
            this->p4statusv.setString(winner == 4 ? "Winner" : "Loser");
            this->p4statusv.setFillColor(winner == 4 ? sf::Color(255, 255, 0, 255) : sf::Color(255, 0, 0, 255));
        }
    }
    return (0);
}

int Info::set_position(int x, int y)
{
    this->global.setPosition((sf::Vector2f){ float(x + 0), float(940 - y) });
    this->tcycle.setPosition((sf::Vector2f){ float(x + 0), float(960 - y) });
    this->ctd.setPosition((sf::Vector2f){ float(x + 0), float(980 - y) });
    this->cycled.setPosition((sf::Vector2f){ float(x + 0), float(1000 - y) });
    this->nbrlive.setPosition((sf::Vector2f){ float(x + 0), float(1020 - y) });
    this->processes.setPosition((sf::Vector2f){ float(x + 0), float(1040 - y) });
    this->lastlive.setPosition((sf::Vector2f){ float(x + 0), float(1060 - y) });
    this->p1.setPosition((sf::Vector2f){ float(x + 300), float(940 - y) });
    this->p1name.setPosition((sf::Vector2f){ float(x + 300), float(960 - y) });
    this->p1lastlive.setPosition((sf::Vector2f){ float(x + 300), float(980 - y) });
    this->p1nbrlive.setPosition((sf::Vector2f){ float(x + 300), float(1000 - y) });
    this->p1processes.setPosition((sf::Vector2f){ float(x + 300), float(1020 - y) });
    this->p1status.setPosition((sf::Vector2f){ float(x + 300), float(1040 - y) });
    this->p2.setPosition((sf::Vector2f){ float(x + 600), float(940 - y) });
    this->p2name.setPosition((sf::Vector2f){ float(x + 600), float(960 - y) });
    this->p2lastlive.setPosition((sf::Vector2f){ float(x + 600), float(980 - y) });
    this->p2nbrlive.setPosition((sf::Vector2f){ float(x + 600), float(1000 - y) });
    this->p2processes.setPosition((sf::Vector2f){ float(x + 600), float(1020 - y) });
    this->p2status.setPosition((sf::Vector2f){ float(x + 600), float(1040 - y) });
    this->p3.setPosition((sf::Vector2f){ float(x + 900), float(940 - y) });
    this->p3name.setPosition((sf::Vector2f){ float(x + 900), float(960 - y) });
    this->p3lastlive.setPosition((sf::Vector2f){ float(x + 900), float(980 - y) });
    this->p3nbrlive.setPosition((sf::Vector2f){ float(x + 900), float(1000 - y) });
    this->p3processes.setPosition((sf::Vector2f){ float(x + 900), float(1020 - y) });
    this->p3status.setPosition((sf::Vector2f){ float(x + 900), float(1040 - y) });
    this->p4.setPosition((sf::Vector2f){ float(x + 1200), float(940 - y) });
    this->p4name.setPosition((sf::Vector2f){ float(x + 1200), float(960 - y) });
    this->p4lastlive.setPosition((sf::Vector2f){ float(x + 1200), float(980 - y) });
    this->p4nbrlive.setPosition((sf::Vector2f){ float(x + 1200), float(1000 - y) });
    this->p4processes.setPosition((sf::Vector2f){ float(x + 1200), float(1020 - y) });
    this->p4status.setPosition((sf::Vector2f){ float(x + 1200), float(1040 - y) });

    this->tcyclev.setPosition((sf::Vector2f){ float(x + 100 + 0), float(960 - y) });
    this->ctdv.setPosition((sf::Vector2f){ float(x + 100 + 0), float(980 - y) });
    this->cycledv.setPosition((sf::Vector2f){ float(x + 100 + 0), float(1000 - y) });
    this->nbrlivev.setPosition((sf::Vector2f){ float(x + 100 + 0), float(1020 - y) });
    this->processesv.setPosition((sf::Vector2f){ float(x + 100 + 0), float(1040 - y) });
    this->lastlivev.setPosition((sf::Vector2f){ float(x + 100 + 0), float(1060 - y) });
    this->p1namev.setPosition((sf::Vector2f){ float(x + 100 + 300), float(960 - y) });
    this->p1lastlivev.setPosition((sf::Vector2f){ float(x + 100 + 300), float(980 - y) });
    this->p1nbrlivev.setPosition((sf::Vector2f){ float(x + 100 + 300), float(1000 - y) });
    this->p1processesv.setPosition((sf::Vector2f){ float(x + 100 + 300), float(1020 - y) });
    this->p1statusv.setPosition((sf::Vector2f){ float(x + 100 + 300), float(1040 - y) });
    this->p2namev.setPosition((sf::Vector2f){ float(x + 100 + 600), float(960 - y) });
    this->p2lastlivev.setPosition((sf::Vector2f){ float(x + 100 + 600), float(980 - y) });
    this->p2nbrlivev.setPosition((sf::Vector2f){ float(x + 100 + 600), float(1000 - y) });
    this->p2processesv.setPosition((sf::Vector2f){ float(x + 100 + 600), float(1020 - y) });
    this->p2statusv.setPosition((sf::Vector2f){ float(x + 100 + 600), float(1040 - y) });
    this->p3namev.setPosition((sf::Vector2f){ float(x + 100 + 900), float(960 - y) });
    this->p3lastlivev.setPosition((sf::Vector2f){ float(x + 100 + 900), float(980 - y) });
    this->p3nbrlivev.setPosition((sf::Vector2f){ float(x + 100 + 900), float(1000 - y) });
    this->p3processesv.setPosition((sf::Vector2f){ float(x + 100 + 900), float(1020 - y) });
    this->p3statusv.setPosition((sf::Vector2f){ float(x + 100 + 900), float(1040 - y) });
    this->p4namev.setPosition((sf::Vector2f){ float(x + 100 + 1200), float(960 - y) });
    this->p4lastlivev.setPosition((sf::Vector2f){ float(x + 100 + 1200), float(980 - y) });
    this->p4nbrlivev.setPosition((sf::Vector2f){ float(x + 100 + 1200), float(1000 - y) });
    this->p4processesv.setPosition((sf::Vector2f){ float(x + 100 + 1200), float(1020 - y) });
    this->p4statusv.setPosition((sf::Vector2f){ float(x + 100 + 1200), float(1040 - y) });
    return (0);
}

int Info::display_info(sf::RenderWindow *win, vm_t *vm)
{
    win->draw(this->global);
    win->draw(this->tcycle);
    win->draw(this->ctd);
    win->draw(this->cycled);
    win->draw(this->nbrlive);
    win->draw(this->processes);
    win->draw(this->lastlive);
    win->draw(this->p1);
    win->draw(this->p1name);
    win->draw(this->p1lastlive);
    win->draw(this->p1nbrlive);
    win->draw(this->p1processes);
    win->draw(this->p1status);
    win->draw(this->p2);
    win->draw(this->p2name);
    win->draw(this->p2lastlive);
    win->draw(this->p2nbrlive);
    win->draw(this->p2processes);
    win->draw(this->p2status);
    win->draw(this->p3);
    win->draw(this->p3name);
    win->draw(this->p3lastlive);
    win->draw(this->p3nbrlive);
    win->draw(this->p3processes);
    win->draw(this->p3status);
    win->draw(this->p4);
    win->draw(this->p4name);
    win->draw(this->p4lastlive);
    win->draw(this->p4nbrlive);
    win->draw(this->p4processes);
    win->draw(this->p4status);
    display_info_values(win, vm);
    return (0);
}

int Info::display_info_values(sf::RenderWindow *win, vm_t *vm)
{
    init_values(vm);
    win->draw(this->tcyclev);
    win->draw(this->ctdv);
    win->draw(this->cycledv);
    win->draw(this->nbrlivev);
    win->draw(this->processesv);
    win->draw(this->lastlivev);
    win->draw(this->p1namev);
    win->draw(this->p1lastlivev);
    win->draw(this->p1nbrlivev);
    win->draw(this->p1processesv);
    win->draw(this->p1statusv);
    win->draw(this->p2namev);
    win->draw(this->p2lastlivev);
    win->draw(this->p2nbrlivev);
    win->draw(this->p2processesv);
    win->draw(this->p2statusv);
    win->draw(this->p3namev);
    win->draw(this->p3lastlivev);
    win->draw(this->p3nbrlivev);
    win->draw(this->p3processesv);
    win->draw(this->p3statusv);
    win->draw(this->p4namev);
    win->draw(this->p4lastlivev);
    win->draw(this->p4nbrlivev);
    win->draw(this->p4processesv);
    win->draw(this->p4statusv);
    return (0);
}

int Info::init_winner(vm_t *vm)
{
    int winner = get_winner(vm);
    sf::FloatRect player_rect = this->winner_name.getLocalBounds();
    sf::FloatRect winner_rect = this->winner_text.getLocalBounds();

    if (winner == 1) {
        this->winner_name.setString("PLAYER 1");
        this->winner_name.setFillColor(sf::Color(255, 0, 0, 255));
    }
    if (winner == 2) {
        this->winner_name.setString("PLAYER 2");
        this->winner_name.setFillColor(sf::Color(0, 0, 255, 255));
    }
    if (winner == 3) {
        this->winner_name.setString("PLAYER 3");
        this->winner_name.setFillColor(sf::Color(0, 255, 0, 255));
    }
    if (winner == 4) {
        this->winner_name.setString("PLAYER 4");
        this->winner_name.setFillColor(sf::Color(255, 255, 0, 255));
    }
    this->winner_text.setString("WINNER");
    this->winner_name.setOutlineColor(sf::Color(0, 0, 0, 255));
    this->winner_text.setOutlineColor(sf::Color(0, 0, 0, 255));
    this->winner_name.setOutlineThickness(10.f);
    this->winner_text.setOutlineThickness(10.f);
    this->winner_name.setOrigin(player_rect.left + player_rect.width / 2.f, player_rect.top + player_rect.height / 2.f);
    this->winner_text.setOrigin(winner_rect.left + winner_rect.width / 2.f, winner_rect.top + winner_rect.height / 2.f);
    this->winner_name.setPosition((sf::Vector2f){ float(1920 / 2), float(1080 / 2 - 10 - player_rect.height) });
    this->winner_text.setPosition((sf::Vector2f){ float(1920 / 2), float(1080 / 2 + 10 + winner_rect.height) });
    return (0);
}

int Info::display_winner(sf::RenderWindow *win)
{
    win->draw(this->winner_name);
    win->draw(this->winner_text);
    return (0);
}