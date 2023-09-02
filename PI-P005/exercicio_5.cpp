#include<iostream>
#include<math.h>
#include<bitset>

using namespace std;

int main(){
    unsigned char gene;
    int qtd = 0, i;
    
    cout << endl << "Digite o caractere correspondente ao gene: ";
    cin >> gene;

    bitset<8> x(gene);
    cout << "Os genes possuem a seguinte composicao: " << x << endl;

    for (i = 0; i < 8; i++){
        qtd += ((gene & 1<<i) == (1<<i)) ? 1 : 0;
    }

    cout << "Estao presentes " << qtd << " genes estudados!" << endl << endl;

    return 0;
}