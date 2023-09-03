#include <iostream>
#include <math.h>
using namespace std;

int main(){

    float r;
    const float PI = 3.14;

    cout << "Digite o raio: ";
    cin >> r;

    cout << "Diametro: " << r*2 << endl;
    cout << "Perimetro: " << 2*PI*r << endl;
    cout << "Area: " << PI*pow(r, 2) << endl;

    return 0;
}
