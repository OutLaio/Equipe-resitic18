#include <iostream>
using namespace std;

void multiplica_por_n(int *vet, int qtde, int n);

int main(){

    int vetorInteiros[5] = {5, 10, 15, 20, 25};
    int qnt = 5;
    int multiplicador = 2;

    multiplica_por_n(vetorInteiros, qnt, multiplicador);

    for(int i=0; i<qnt; i++) cout << "[" << i << "] - " << vetorInteiros[i] << endl;

    return 0;
}
void multiplica_por_n(int *vet, int qtde, int n){
    for(int i=0; i<qtde; i++){
        vet[i] = vet[i] * n;
    }
}