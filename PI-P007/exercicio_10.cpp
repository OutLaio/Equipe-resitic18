#include <iostream>
using namespace std;

int main(){
    int escolhaUsuario, anterior, proximo;

    cout << "Digite um valor: ";
    cin >> escolhaUsuario;

    cout << endl << escolhaUsuario << " números de Fibonnacci" << ": 1 ";
    anterior = 1;
    proximo = 2;
    for(int i=2; i<=escolhaUsuario; i++){
        int numeroTemporario;
        cout << anterior << " ";
        numeroTemporario = proximo;
        proximo = anterior + proximo;
        anterior = numeroTemporario;
    }
    return 0;
}
