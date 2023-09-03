#include <iostream>

using namespace std;

int main() {
    int num, somaDivisores = 0;

    cout << "Digite um numero inteiro positivo: ";
    cin >> num;

    if (num <= 0) {
        cout << "O numero deve ser positivo." << endl;
        return 1;
    }

    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            somaDivisores += i;
        }
    }

    cout << endl << "O numero " << num << (somaDivisores==num ? " " : " nao ") << "eh um numero perfeito" << endl;

    return 0;
}