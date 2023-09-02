#include<iostream>
#include<math.h>

using namespace std;

int main(){
    char ch1, ch2, ch3;

    cout << endl << "Digite um caractere : ";
    cin >> ch1;
    cout << "Digite outro caractere : ";
    cin >> ch2;

    ch3 = (ch1 >= 65 && ch1 <= 90) ? 'A' : ' ';

    cout << endl << "O caractere ch3 corresponde a: " << dec << (int)ch3 << " (dec) - "
        << oct << (int)ch3 << " (oct) - 0x" << hex << (int)ch3 << " (hex) - '" << ch3 << "'" << endl << endl;

    return 0;
}