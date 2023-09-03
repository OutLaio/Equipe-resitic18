#include <iostream>
using namespace std;

int main(){

    // LETRA A
    double x, y, z;

    // LETRA B
    cout << "Digite um numero: ";
    scanf("%lf", &x);
    cout << "Digite um numero: ";
    scanf("%lf", &y);

    // LETRA C
    z = x + y;
    cout << "Z: " << z << endl;

    // LETRA D
    z = (x + y) / 2;
    cout << "Z: " << z << endl;

    // LETRA E
    z = x * y;
    cout << "Z: " << z << endl;

    // LETRA F
    x > y ? z = x : z = y;
    cout << "Z: " << z << endl;

    return 0;
}
