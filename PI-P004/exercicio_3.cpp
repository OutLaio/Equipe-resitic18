#include<iostream>

using namespace std;

int main(){
    unsigned long int uli = 0x7FFFFFFF; 
    long int li = uli;
    // O unsigned long int abrange todos os valores positivos de um long int

    cout << "O valor de li eh: " << li << endl;

    cout << "O valor de uli eh: " << uli << endl;

    return 0;
}