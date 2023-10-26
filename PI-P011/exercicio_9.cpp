#include <iostream>
#include <iomanip>
using namespace std;

float calc_serie(int N);

int main(){

    int numero = 10;

    cout << "SOMA: " << calc_serie(numero) << endl;

    return 0;
}
float calc_serie(int N){
    float soma;
    int maximo = N;

    for(int i=1; i<=N; i++){
        soma += (float) i / (float) maximo;
    }
    return soma;

}
