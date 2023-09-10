#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<math.h>

using namespace std;

int* contaLetra(string txt, char letra, int *qtde){
    *qtde = 0;
    int qtd = *qtde;
    int *indice = (int*)malloc(qtd*sizeof(int));
    for (int i = 0; i < txt.length(); i++){
        if (txt[i] == letra){
            (*qtde)++;
            qtd = *qtde;
            indice = (int*)realloc(indice, qtd*sizeof(int));
            indice[*qtde-1] = i;
        }
    }
    return indice;
}

int main(){
    string texto = "Ser ou nao ser, eis a questao!";
    int qtde, *indice;

    indice = contaLetra(texto, 'e', &qtde);

    for (int i = 0; i < qtde; i++){
        cout << indice[i] << " ";
    }
    
    free(indice);
    return 0;
}