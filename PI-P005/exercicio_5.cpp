#include<iostream>
#include<math.h>
#include<bitset>

using namespace std;

int main(){
    unsigned char gene;
    int qtd = 0, aux = 0, i, geneEspecifico;
    
    cout << endl << "Digite o caractere correspondente ao gene: ";
    cin >> gene;
    cout << "Informe o gene especifico que deseja procurar (1 a 8): ";
    cin >> geneEspecifico;

    bitset<8> x(gene);
    cout << endl << "Os genes possuem a seguinte composicao: " << x << endl;

    for (i = 0; i < 8; i++){
        qtd += ((gene & 1<<i) == (1<<i)) ? 1 : 0;
        if(geneEspecifico == 8-i){
            if (aux == qtd){
                cout << "O gene especifico nao esta presente!" << endl;
            }else{
                cout << "O gene especifico esta presente!" << endl;
            }
        }
        aux = qtd;
    }

    cout << "Estao presentes " << qtd << " genes estudados!" << endl << endl;

    return 0;
}