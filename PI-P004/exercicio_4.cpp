#include<iostream>
#include<limits>
#include<iomanip>

using namespace std;

int main(){

    long double pild = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862;
    double pid = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862;

    cout << fixed << setprecision(50);
    cout << "Valor de pi (long double): " << pild << endl;
    cout << "Valor de pi (double): " << pid << endl;

    // Aparentemente NÃO há diferença entre Double e Long Double

    return 0;
}