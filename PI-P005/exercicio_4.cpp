#include<iostream>
#include<math.h>

using namespace std;

int main(){

    double x, y, z;
    int a;

    cout << "Digite um numero real: ";
    cin >> x;
    cout << "Digite outro numero real: ";
    cin >> y;

    z = x*y;
    cout.setf(ios::scientific);
    cout << "O produto entre os dois numeros eh: " << z << endl;

    return 0;
}