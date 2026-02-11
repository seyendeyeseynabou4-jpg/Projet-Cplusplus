#ifndef MENU_HPP
#define MENU_HPP

#include "bibliotheque.hpp"


void logo();

enum class Menu {
    principal,
    consulterreference,
    gererreferences,
    chercherreferences,
    exporterenhtml,
    parametres,
    quitterappli
};

bool executerAction(Menu etat, Bibliotheque & bibliotheque);

#endif
