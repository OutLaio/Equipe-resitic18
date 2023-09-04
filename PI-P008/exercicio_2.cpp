#include<iostream>
#include<math.h>

using namespace std;

int main(){
    int i, j, vetor[100], repete[20], qtd = 0;;

    for (i = 0; i < 100; i++){
        vetor[i] = 1 + rand()%20;
    }

    for (i = 0; i < 20; i++){
        repete[i] = 0;
        for (j = 0; j < 100; j++){
            if (vetor[j] == i+1){
                repete[i] += 1; 
            }
        }
        if (qtd < repete[i]){
            qtd = repete[i];
        }
    }
    
    cout << "O(s) numero(s) ";
    for (i = 0; i < 20; i++){
        // cout << "O numero " << i << " se repete " << repete[i] << " vezes." << endl;
        if (repete[i] == qtd){
            cout << i << " ";
        }
    }
    cout << "se repete(m) " << qtd << " vezes." << endl;

    return 0;
}