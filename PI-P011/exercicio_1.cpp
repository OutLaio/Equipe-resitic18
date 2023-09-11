#include <iostream>
using namespace std;

/**
 * @brief Função para obter o maior e menor valor de um vetor.
 * @param vetor[] Vetor com valores inteiros.
 * @param n Tamanho do vetor.
 * @param maximo Inteiro para armazenar o maior entre os valores do vetor.
 * @param minimo Inteiro para armazenar o menor entre os valores do vetor.
*/
void maxmin(int vetor[], int n, int &maximo, int &minimo);

int main(){
    int tamanho = 5;
    int vetorDeInteiros[tamanho] = {50, 40, 70, 35, 100};
    int maiorValor, menorValor;

    maxmin(vetorDeInteiros, tamanho, maiorValor, menorValor);

    cout << "Maior valor: " << maiorValor << endl;
    cout << "Menor Valor: " << menorValor << endl;

    return 0;
}

void maxmin(int vetor[], int n, int &maximo, int &minimo){
    if (n < 1){
        cout << "Vetor vazio!" << endl;
        return;
    } else {
        maximo = vetor[0];
        minimo = vetor[0];
        for(int i=0; i<n; i++){
            if(vetor[i] > maximo) maximo = vetor[i];
            if(vetor[i] < minimo) minimo = vetor[i];
        }
    }
}