#include<iostream>
#include<limits>
#include<iomanip>

using namespace std;

int main(){
    
    float pif = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862;

    cout << fixed << setprecision(2);
    cout << "Valor de pi: " << pif << endl;

    cout << fixed << setprecision(4);
    cout << "Valor de pi: " << pif << endl;

    cout << fixed << setprecision(8);
    cout << "Valor de pi: " << pif << endl;

    cout << fixed << setprecision(16);
    cout << "Valor de pi: " << pif << endl;

    return 0;
}