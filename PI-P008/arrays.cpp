#include <iostream>
using namespace std;

int main(){

    int array[100];
    int arrayContagem[20] = {0};
    srand(time(NULL));

    // LETRA A
    for(int i=0; i<100; i++){
        array[i] = 1 + rand() % 20;
        // LETRA B
        if(array[i] == 1) arrayContagem[0]++;
        else if(array[i] == 2) arrayContagem[1]++;
        else if(array[i] == 3) arrayContagem[2]++;
        else if(array[i] == 4) arrayContagem[3]++;
        else if(array[i] == 5) arrayContagem[4]++;
        else if(array[i] == 6) arrayContagem[5]++;
        else if(array[i] == 7) arrayContagem[6]++;
        else if(array[i] == 8) arrayContagem[7]++;
        else if(array[i] == 9) arrayContagem[8]++;
        else if(array[i] == 10) arrayContagem[9]++;
        else if(array[i] == 11) arrayContagem[10]++;
        else if(array[i] == 12) arrayContagem[11]++;
        else if(array[i] == 13) arrayContagem[12]++;
        else if(array[i] == 14) arrayContagem[13]++;
        else if(array[i] == 15) arrayContagem[14]++;
        else if(array[i] == 16) arrayContagem[15]++;
        else if(array[i] == 17) arrayContagem[16]++;
        else if(array[i] == 18) arrayContagem[17]++;
        else if(array[i] == 19) arrayContagem[18]++;
        else if(array[i] == 20) arrayContagem[19]++;
    }

    // LETRA C
    int maior = arrayContagem[0];
    int numeroRepetido = 1;
    for(int i : arrayContagem){
        if(i > maior){
            maior = i;
            numeroRepetido++;
        }
    }

    for(int i=0; i<sizeof(arrayContagem)/4; i++){
        cout << "POS[" << i << "] = " << arrayContagem[i] << endl; 
    }

    cout << "O numero " << numeroRepetido << " se repetiu " << maior << " vezes." << endl;

    return 0;
}