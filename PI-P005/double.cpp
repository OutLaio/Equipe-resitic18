#include <iostream>
#include <math.h>
using namespace std;

int main(){

    // LETRA A
    double x, y, z;

    // LETRA B
    cout << "Digite um valor: ";
    cin >> x;
    cout << "Digite um valor: ";
    cin >> y;

    // LETRA C
    z = 5 * x + 2;
    y > z ? cout << "Acima da curva"<<endl:cout<<"";
    y < z ? cout << "Abaixo da curva"<<endl:cout<<"";
    y == z ? cout << "Na curva"<<endl:cout<<"";

    // LETRA D
    z = sqrt((pow(x, 2))+(pow(y, 2)));
    cout << "Distância Euclidiana: " << z << endl;

    // LETRA E
    z = x * y;
    cout << "Z: " << scientific << z << endl;

    return 0;
}
