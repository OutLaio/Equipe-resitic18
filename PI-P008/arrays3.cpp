#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    srand(time(NULL));
    float notasA1[15] = {0.0};
    float notasA2[15] = {0.0};
    float media[15] = {0.0};

    for(int i=0; i<15; i++){
        notasA1[i] = ((float)rand()/RAND_MAX)*10;
        notasA2[i] = ((float)rand()/RAND_MAX)*10;
    }

    for(int i=0; i<15; i++){
        cout << "Nota " << i+1 << ": "; // Somando 1 para melhor vizualização
        if(notasA1[i] > notasA2[i]) cout << "Melhorou!" << endl;
        else if(notasA1[i] < notasA2[i]) cout << "Piorou!" << endl;
        else cout << "Manteve a nota!" << endl;
    }

    cout << endl;

    for(int i=0; i<15; i++){
        media[i] = (notasA1[i] + notasA2[i]) / 2;
        cout << setprecision(3) << "Média " << i << ": " << media[i] << endl;
    }
    return 0;
}
