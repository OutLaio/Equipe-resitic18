#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<math.h>

using namespace std;

int conta_primos (int *vet, int qtde){
    int qtdPrimo = qtde;

    for (int i = 0; i < qtde; i++){
        for (int j = 2; j*j <= vet[i]; j++){
            if (vet[i]%j == 0){
                qtdPrimo--;
                break;
            }
        }
    }
    return qtdPrimo;
}

int main(){
    int vet[10] = {2,4,6,3,73,97,10,35,63,49};
    
    cout << conta_primos(vet, 10) << endl;
    
    return 0;
}