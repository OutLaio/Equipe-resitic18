#include<iostream>

using namespace std;

int main(){

    double x, y, z;
    int a;

    cout << "Digite um numero real: ";
    cin >> x;
    cout << "Digite outro numero real: ";
    cin >> y;

    z = 5*x + 2;

    a = (y>z) ? -1 : (y<z) ? 1 : 0;

    cout << "O ponto (" << x << ", " << y << ") se encontra ";

    switch (a){
        case -1:
            cout << "a esquerda d";
            break;
        case 0:
            cout << "n";
            break;
        case 1:
            cout << "a direita d";
            break;
        default:
            break;
    }

    cout << "a curva!" << endl;

    return 0;
}