#include<iostream>
#include<math.h>

using namespace std;

int main(){
    char a;

    cout << "Digite um caractere: ";
    cin >> a;
    
    cout << "'" << a << "' - " << dec << (int)a << " (dec) - " << oct << (int)a << " (oct) - 0x" << hex << (int)a << " (hex) " << endl;

    return 0;
}