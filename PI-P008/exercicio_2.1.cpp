#include<iostream>
#include<math.h>

using namespace std;

int main(){
    int i;
    float estacoes[250], max = 0, min = 40;

    for (i = 0; i < 250; i++){
        estacoes[i] = 10.0 + (3.0*(rand()%100))/10.0;
    }

    for (i = 0; i < 250; i++){
        max += estacoes[i];
    }

    cout << "A temperatura media foi " << max/250 << "°C" << endl;
    




    /*
    Letra b)
    for (i = 0; i < 250; i++){
        if (estacoes[i] > max){
            max = estacoes[i];
        }
        if (estacoes[i] < min){
            min = estacoes[i];
        }
    }
    cout << "A maxima temperatura reportada foi " << max << "°C" << endl;
    cout << "A minima temperatura reportada foi " << min << "°C" << endl;
    */

    return 0;
}