#include <iostream>
#include <float.h>
#include <iomanip>
using namespace std;

int main(){

    // LETRA A
    float maiorFloat = FLT_MAX;
    float menorFloat = FLT_MIN;
    cout << "Maior float possível: " << maiorFloat << endl;
    cout << "Menor float possível: " << menorFloat << endl;

    // LETRA B;
    float pif = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679;
    cout << "PI: " << pif << endl;
    
    // LETRA C
    cout << "2 casas - " << setprecision(3) << pif << endl;
    cout << "4 casas - " << setprecision(5) << pif << endl;
    cout << "8 casas - " << setprecision(9) << pif << endl;
    cout << "16 casas - " << setprecision(17) << pif << endl;

    // LETRA D
    double pid = pif;
    cout << "PID: " << pid << endl;

    // LETRA E
    cout << "2 casas - " << setprecision(3) << pid << endl;
    cout << "4 casas - " << setprecision(5) << pid << endl;
    cout << "8 casas - " << setprecision(9) << pid << endl;
    cout << "16 casas - " << setprecision(17) << pid << endl;
    
    return 0;
}
