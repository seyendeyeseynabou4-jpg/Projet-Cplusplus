#include <iostream>

#include "exo5.hpp"
#include using namespace std;
#include using namespace trigonometrie;

void module (double &degres){
    const double pi = 3.14;
    cout << "Donnez un angle en degres ;";
    cin >> degres;
    double radian = (degres * pi/180);
    cout << "L'angle en radians est : " << degres << endl;
}

void module (double &radians){
    const double pi = 3.14;
    cout << "Donnez un angle en radians ;";
    cin >> radians;
    double degres = (radians * 180/pi);
    cout << "L'angle en degres est: " << degres << endl;
}

int main()
{
    const double pi = 3.14;
    double degres;
    double radians;
    module(degres);
    module(radians);

    return 0;
}
