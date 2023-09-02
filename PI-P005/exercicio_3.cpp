#include<iostream>

using namespace std;

int main(){
    int a, b, c;

    cout << "Digite um numero: ";
    cin >> a;
    cout << "Digite outro numero: ";
    cin >> b;

    c = abs(a-b);
    // A função abs retorna o valor absoluto, em outras palavras o módulo de um valor

    cout << "A diferenca absoluta entre os dois numeros eh : " << c <<endl;

    return 0;
}