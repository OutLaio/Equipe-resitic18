#include <iostream>
#include <math.h>
using namespace std;

int main(){

    // LETRA A
    int a, b, c;

    // LETRA B
    cout << "Digite um numero: ";
    cin >> a;
    cout << "Digite um numero: ";
    cin >> b;

    // LETRA C
    c = 4 * a + b / 3;

    // LETRA D
    cout << "C: " << c << endl;

    // LETRA E
    c = 4 * (a + b) / (3 - 5);
    cout << "C: " << c << endl;

    // LETRA F
    /*
        Os resultados são diferentes por conta da prioridade estabelecidas
        pelos parenteses.
    */
    c = (a + (b - 2)) * 3;
    cout << "C: " << c << endl;
    c = a + (b - (2 * 1));
    cout << "C: " << c << endl;

    // LETRA G
    c = pow(a, 2) + 2 * b + c;
    cout << "C: " << c << endl;

    return 0;
}
