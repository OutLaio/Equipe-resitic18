#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main(){

    string numeroUsuario;
    int soma = 0;

    cout << "Digite um número: ";
    cin >> numeroUsuario;

    for(char a : numeroUsuario){
        soma += pow((a - '0'), numeroUsuario.size());
    }

    if(to_string(soma) == numeroUsuario){
        cout << numeroUsuario << " é um número Armstrong!" << endl;
    } else cout << numeroUsuario << " não é um número Armstrong!" << endl;

    return 0;
}
