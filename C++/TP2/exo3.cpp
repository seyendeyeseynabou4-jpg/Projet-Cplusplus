#include <iostream>

#include "exo3.hpp"


void saisir_date_de_naisssance (int &jour_naiss, int &annee_naiss , int &mois_naiss)
{
    std::cout << "Saisir la date de naissance (annee mois jour):";
    std::cin >> annee_naiss >> mois_naiss >> jour_naiss;
}

void sasir_date_du_jour (int &annee_actu , int &mois_actu , int &jour_actu)
{
    std::cout << "Saisir la date du jour (annee mois jour):";
    std::cin >> annee_actu >> mois_actu >> jour_actu;
}

void verification (int &annee_naiss , int &mois_naiss , int &jour_naiss , int &annee_actu , int &mois_actu , int &jour_actu)
{
    if (annee_actu < (annee_naiss +18))
        std::cout << "Vous etes majeur" << std::endl;
    else if (annee_actu == (annee_naiss +18))
    {
        if (mois_actu < mois_naiss)
           std::cout << "Vous etes mineur" << std::endl;
        else if (mois_actu == mois_naiss)
        {
            if (jour_actu < jour_naiss)
               std::cout << "Vous etes mineur" << std::endl;
            else
               std::cout << "Vous etes majeur" << std::endl;
        }
        else
           std::cout << "Vous etes mineur" << std::endl;

     }
}

int main()
{
    int annee_naiss , mois_naiss , jour_naiss;
    int annee_actu , mois_actu , jour_actu;
    saisir_date_de_naisssance (annee_naiss , mois_naiss , jour_naiss);
    sasir_date_du_jour (annee_actu , mois_actu , jour_actu);
    verification (annee_naiss , mois_naiss , jour_naiss , annee_actu , mois_actu , jour_actu);
    return 0;
}
