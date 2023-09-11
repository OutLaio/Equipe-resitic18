#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<math.h>

using namespace std;

int* intercala(int *vet1, int tam1, int *vet2, int tam2){
    int qtd = tam1+tam2, q1 = 0, q2 = 0;
    int *vetor = (int*)malloc(qtd * sizeof(int));

    if (vetor == NULL) {
        return NULL;
    }

    for (int i = 0; i < qtd;){
        if(q1 < tam1){
            vetor[i] = vet1[q1];
            q1++;
            i++;
        }
        if (q2 < tam2){
            vetor[i] = vet2[q2];
            q2++;
            i++;
        }
    }
    return vetor;
}


int main(){
    int vet1[6] = {1,2,3,4,5,6}, vet2[10] = {1,2,3,4,5,6,7,8,9,10}, *vet;

    vet = intercala(vet2, 10, vet1, 6);

    for (int i = 0; i < 16; i++){
        cout << vet[i] << " ";
    }
    
    free(vet);
    return 0;
}