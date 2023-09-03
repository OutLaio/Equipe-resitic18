#include <iostream>
using namespace std;

int main(){
    
    // LETRA A
    int a=0, b=0, c=0;

    // LETRA B
    cout << "Digite um numero: ";
    cin >> a;
    cout << "Digite um numero: ";
    cin >> b;

    // LETRA C
    c = a + b;
    cout << "C hexadecimal: " << hex << c << endl;

    // LETRA D
    c = a * b;
    cout << "C octal: " << oct << c << endl;

    // LETRA E
    a - b >= 0 ? c = a - b : c = (a - b) * (-1);
    cout << "Modulo de C: " << dec << c << endl;

    // LETRA F
    c = a - b;
    cout << "Modulo de C: " << abs(c) << endl;

    // LETRA G
    if(b > 0) c = a / b;
    else cout << "Não é possível dividir por 0.";
    cout << "Quociente de C: " << c << endl;

    // LETRA H
    if(a % b == 0) c = a / b;
    else cout << "Não é divisivel de forma exata" << endl;

    return 0;
}
