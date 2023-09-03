#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));

    int numeroAleatorio = rand() % 100 + 1;
    int palpite, tentativas = 0;

    do {
        cout << "Tente adivinhar o numero (entre 1 e 100): ";
        cin >> palpite;
        tentativas++;

        if (palpite < numeroAleatorio) {
            cout << "Palpite baixo. Tente novamente." << endl;
        } else if (palpite > numeroAleatorio) {
            cout << "Palpite alto. Tente novamente." << endl;
        } else {
            cout << "Parabens! Voce acertou o numero " << numeroAleatorio << " em " << tentativas << " tentativas." << endl;
        }
    } while (palpite != numeroAleatorio);

    return 0;
}