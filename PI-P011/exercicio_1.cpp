#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<math.h>

using namespace std;

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