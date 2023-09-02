#include<iostream>
#include<math.h>

using namespace std;

int main(){
    char ch1, ch2, ch3;

    cout << endl << "Digite um caractere : ";
    cin >> ch1;
    cout << "Digite outro caractere : ";
    cin >> ch2;

    ch3 = (ch1 <= 32) ? '_' : ch1-1;

    cout << endl << "O caractere antecessor ao primeiro corresponde a: " << dec << (int)ch3 << " (dec) - "
        << oct << (int)ch3 << " (oct) - 0x" << hex << (int)ch3 << " (hex) - '" << ch3 << "'" << endl << endl;

    ch3 = (ch2 >= 126) ? '_' : ch2+1;

    cout << endl << "O caractere precessor ao segundo corresponde a: " << dec << (int)ch3 << " (dec) - "
        << oct << (int)ch3 << " (oct) - 0x" << hex << (int)ch3 << " (hex) - '" << ch3 << "'" << endl << endl;

    return 0;
}