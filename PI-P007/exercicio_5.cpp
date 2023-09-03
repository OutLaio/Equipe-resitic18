#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
    srand (time(NULL));
    int numeroJogador = 0, numeroPartida = 0;

    cout << "Jogo de Adivinhação" << endl;
    numeroPartida = rand() % 100 + 1;
    do{
        cout << endl << "Escoha um numero: " << endl << "> ";
        cin >> numeroJogador;
        if(numeroPartida > numeroJogador) cout << "Baixo!" << endl;
        else if(numeroPartida < numeroJogador) cout << "Alto!" << endl;
        else cout << "Correto!" << endl;
    }while(numeroJogador != numeroPartida);

    return 0;
}
