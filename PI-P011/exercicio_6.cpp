#include <iostream>
using namespace std;

int* intercala(int *vet1, int tam1, int *vet2, int tam2);

int main(){

    int vetor1[5] = {10, 20, 30, 40, 50};
    int vetor2[5] = {100, 200, 300, 400, 500};
    int tam1 = 5, tam2 = 5;
    int* vetorJuncao = intercala(vetor1, tam1, vetor2, tam2);

    for(int i=0; i<tam1+tam2; i++){
        cout << "- " << vetorJuncao[i] << endl;
    }

    return 0;
}

int* intercala(int *vet1, int tam1, int *vet2, int tam2){
    int* vetorTemp = new int[tam1 + tam2];
    int x=0, y=0, z=0;
    
    while (x < tam1 && y < tam2) {
        vetorTemp[z++] = vet1[x++];
        vetorTemp[z++] = vet2[y++];
    }
    if(x < tam1){
        while (x < tam1) {
            vetorTemp[z++] = vet1[x++];
        }
    } else if(y < tam2){
        while (y < tam2) {
            vetorTemp[z++] = vet2[y++];
        }
    }

    return vetorTemp;
}