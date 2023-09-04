#include <iostream>
#include <stdlib.h>
#include <iomanip>
using namespace std;

int main(){

    srand(time(NULL));
    float temperaturas[250];
    float maxTemp, minTemp, mediaTemp;

    for(int i=0; i<250; i++){
        temperaturas[i] = 1 + 30.0*(rand()%100)/3000.0;
        mediaTemp += temperaturas[i];
        cout << temperaturas[i] << " ";
    }
    cout << endl << "Temperaturas captadas!" << endl;

    maxTemp = minTemp = temperaturas[0];
    for(float i : temperaturas){
        if(i > maxTemp) maxTemp = i;
        else if(i < minTemp) minTemp = i; 
    }
    cout << setprecision(3) << "Maior temperatura: " << maxTemp << endl << "Menor temperatura: " << minTemp << endl;

    mediaTemp /= 250;
    cout << "Média das temperaturas: " << mediaTemp << endl;

    for(int i=0; i<250; i++){
        if(temperaturas[i] > mediaTemp) temperaturas[i] += 1;
        else if(temperaturas[i] < mediaTemp) temperaturas[i] += 2.0;
    }

    return 0;
}
