#include<iostream>
#include<math.h>

using namespace std;

int main(){
    int i;
    float estacoes[250];

    for (i = 0; i < 250; i++){
        estacoes[i] = 10.0 + (3.0*(rand()%100))/10.0;
    }

    return 0;
}