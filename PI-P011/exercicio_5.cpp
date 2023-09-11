#include <iostream>
using namespace std;

int insere_meio(int *vetor, int qtde, int elemento);

int main(){

    int vetorInteiros[15] = {1, 2, 3, 4, 5, 6};
    int quantidade = 6;
    int elementoNovo = 100;

    quantidade = insere_meio(vetorInteiros, quantidade, elementoNovo);

    for(int i=0; i<quantidade; i++) cout << "Valor [" << i << "]: " << vetorInteiros[i] << endl; 

    return 0;
}
int insere_meio(int *vetor, int qtde, int elemento){
    int meio = int(qtde / 2);
    
    for (int i=qtde; i>meio; i--){
        vetor[i] = vetor[i-1];
    }
    vetor[meio] = elemento;
    qtde++;
    return qtde;
}
