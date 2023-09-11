#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<math.h>

using namespace std;

/*

Exercício 2:
Qual o tipo de coesão e acoplamento da função do exercício 1?

A função maxmin tem coesão funcional, pois tem uma única funcionalidade clara que é encontrar os valores máximos e mínimos.
Além disso, essa função recebe todos os dados que precisa como parâmetros, o que a torna fracamente acoplada.

*/

void maxmin(int vetor[], int n, int* maximo, int* minimo){
    *maximo = 0;
    *minimo = 0x7FFFFFFF;
    for (int i = 0; i < n; i++){
        if(vetor[i] > *maximo)
            *maximo = vetor[i];
        if(vetor[i] < *minimo)
            *minimo = vetor[i];
    }
    return;
}

int main(){
    int max, min;
    int vetor[10] = {5,6,8,2,-5,6,1,0,8,4};

    maxmin(vetor, 10, &max, &min);

    cout << max << " " << min << endl;
    
    return 0;
}