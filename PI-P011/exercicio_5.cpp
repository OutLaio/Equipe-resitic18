#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<math.h>

using namespace std;

int insere_meio( int *vetor, int qtde, int elemento){
    int meio = qtde/2;

    for (int i = qtde; i > meio; i--){
        vetor[i] = vetor[i-1];
    }
    vetor[meio] = elemento;
    qtde++;

    return qtde;
}

int main(){
    int vetor[10] = {1,2,3,4,5,6}, qtde = 6;

    qtde = insere_meio(vetor, qtde, 100);
    
    for (int i = 0; i < qtde; i++){
        cout << vetor[i] << " ";
    }
    
    
    return 0;
}