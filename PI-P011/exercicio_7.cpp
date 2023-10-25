#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<math.h>

using namespace std;

void multiplica_por_n(int *vet, int qtde, int n){
    for (int i = 0; i < qtde; i++){
        vet[i] *= n;
    }
    return;
}

int main(){
    int vet[6] = {1,2,3,4,5,6};
    
    multiplica_por_n(vet, 6, 3);

    for (int i = 0; i < 6; i++){
        cout << vet[i] << " ";
    }
    
    
    return 0;
}