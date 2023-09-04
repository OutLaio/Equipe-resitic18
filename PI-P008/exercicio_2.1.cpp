#include<iostream>
#include<math.h>

using namespace std;

int main(){
    int i;
    float estacoes[250], max = 0, min = 40, media;

    for (i = 0; i < 250; i++){
        estacoes[i] = 10.0 + (3.0*(rand()%100))/10.0;
        max += estacoes[i];
    }
    media = max/250;
    cout << "A temperatura media era " << media << "°C" << endl;
    max = 0;
    for (i = 0; i < 250; i++){
        if (estacoes[i] > media){
            estacoes[i] += 1.0;
        }else if (estacoes[i] < media){
            estacoes[i] -= 2.0;
        }
        max += estacoes[i];
    }
    media = max/250;
    cout << "A temperatura media agora eh " << media << "°C" << endl;




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