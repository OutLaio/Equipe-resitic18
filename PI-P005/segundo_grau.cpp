#include <iostream>
#include <math.h>
using namespace std;

int main(){

    // LETRA A
    float a, b, c;
    float delta;
    float x1, x2;
    float x, resultado;

    delta = pow(b, 2) - 4 * a * c;

    if(delta > 0) cout << "Duas raizes!" << endl;
    else if (delta == 0) cout << "Uma raiz!" << endl;
    else cout << "Nenhuma raiz real!" << endl;

    if(delta > 0 || delta == 0){
        x1 = (-b+sqrt(delta))/2*a;
        x2 = (-b-sqrt(delta))/2*a;
    }

    // LETRA B
    cout << "Digite um valor: ";
    cin >> x;

    resultado = a*pow(x, 2) + b*x + c;
    cout << "Resultado p(x): " << resultado << endl;

    return 0;
}
