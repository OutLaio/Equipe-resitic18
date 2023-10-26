#include <iostream>
using namespace std;

int conta_primos(int *vet, int qtde);
bool primo(int x);

int main(){

    int vetorInteiros[5] = {1, 2, 3, 4, 5};
    int qnt = 5;

    cout << "quantidade de primos: " << conta_primos(vetorInteiros, qnt) << endl;

    return 0;
}
int conta_primos(int *vet, int qtde){
    int contador = 0;

    for(int i=0; i<qtde; i++){
        if(primo(vet[i])) contador++;
    }
    return contador;
}
bool primo(int x){
    if (x <= 1) return false;
    else if (x <= 3) return true;
    else if (x % 2 == 0 || x % 3 == 0) return false;

    for (int divisor = 5; divisor * divisor <= x; divisor += 6) {
        if (x % divisor == 0 || x % (divisor + 2) == 0) {
            return false;
        }
    }
    return true;
}