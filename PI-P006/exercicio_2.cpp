#include<iostream>
#include<math.h>

using namespace std;

int main(){
    int a, b, c;

    cout << endl << "Digite um valor inteiro: ";
    cin >> a;
    cout << "Digite outro valor inteiro: ";
    cin >> b;

    c = 4*a + b/3 - 5;

    cout << endl << "O resultado da expressao eh: " << c << endl << endl;

    return 0;
}