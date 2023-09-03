#include <iostream>
using namespace std;

int main(){
    int numeroUsuario, soma=0;
    
    do{
        cout << "Digite um número: ";
        cin >> numeroUsuario;

        if(numeroUsuario <= 0) cout << "Digite um valor maior que 0!" << endl;
    }while(numeroUsuario <= 0);
    
    for(int i=numeroUsuario - 1; i>=1; i--){
        if(numeroUsuario % i == 0){
            soma += i;
        }
    }
    
    if(soma == numeroUsuario) cout << numeroUsuario << " é um número perfeito!" << endl;
    else cout << numeroUsuario << " não é um número perfeito!" << endl;

    return 0;
}
