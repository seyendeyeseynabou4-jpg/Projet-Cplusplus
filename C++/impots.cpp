#include <iostream>

using namespace std;

int main()
{
    const double plafond1 = 500;
    const double plafond2 = 1200;
    const double taux1 = 0.15;
    const double taux2 = 0.25;

    cout << "Revenu imposable de l'année précédente? >";
    double revenu_imposable;
    cin >> revenu8imposable;
    if (revenu_imposable < plafond1)
    impot = 0;
    else 
    {
        impot = revenu_imposable * taux1;
        if(revenu_imposable >= plafond2)
          impot = impot + (revenu_imposable - plafond2) * taux2;

    }
cout <<"L'impot du est de:"  : " << impot << endl;"
return 0 ; 
}