#include <iostream>
#include <vector>
#include <array>
using namespace std;

int main(){

    char alfabeto[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    int escolhaUsuario, inicio=0, fim=0, contador=2;

    cout << "Altura: ";
    cin >> escolhaUsuario;

    for(int i=1; i<=escolhaUsuario; i++){
        inicio += i - 1;
        for(int j=inicio; j<=fim; j++){
            cout << alfabeto[j];
        }
        cout << endl;
        fim += contador;
        contador++;
    }
    return 0;
}
