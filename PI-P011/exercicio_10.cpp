#include <iostream>
using namespace std;

void encontraLetra(char* str, char letra, int* &posicoes, int &tamanho);

int main() {
    char* minhaString = "programacao";
    char letraProcurada = 'a';
    int* posicoes;
    int tamanho = 0;

    encontraLetra(minhaString, letraProcurada, posicoes, tamanho);

    if (tamanho > 0) {
        cout << "A letra '" << letraProcurada << "' foi encontrada nas posições: ";
        for (int i = 0; i < tamanho; i++) cout << posicoes[i] << " ";
        cout << endl;

    } else cout << "A letra '" << letraProcurada << "' não foi encontrada na string." << endl;
    
    delete[] posicoes;

    return 0;
}
void encontraLetra(char* str, char letra, int*& posicoes, int& tamanho){
    tamanho = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == letra) tamanho++;
    }
    posicoes = new int[tamanho];

    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == letra) posicoes[j++] = i;
    }
}