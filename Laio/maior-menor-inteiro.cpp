#include<iostream>

using namespace std;

int main(){
    
    unsigned long int uli = 0xFFFFFFFFFFFFFFFF;

    cout << "O maior valor de um unsigned long int eh: " << uli << endl;

    uli++;

    cout << "O menor valor de um unsigned long int eh: " << uli << endl;

    return 0;
}