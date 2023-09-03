#include <iostream>
using namespace std;

int main(){

    // LETRA A
    char ch1, ch2, ch3;

    // LETRA B
    cout << "Digite um caractere: ";
    cin >> ch1;
    cout << "Digite um caractere: ";
    cin >> ch2;

    // LETRA C
    int(ch1) - 1 >= 0 && int(ch1) - 1 <= 254 ? ch3 = int(ch1) - 1 : ch3='_';
    cout << "CH3 CARAC: " << ch3 << endl;
    cout << "CH3 DEC: " << dec << int(ch3) << endl;
    cout << "CH3 OCT: " << oct << int(ch3) << endl;
    cout << "CH3 HEX: " << hex << int(ch3) << endl;

    // LETRA D
    int(ch2) - 1 >= 0 && int(ch2) - 1 <= 254 ? ch3 = int(ch2) - 1 : ch3='_';
    printf("CH3 CARAC %c", ch3);
    printf("CH3 DEC %d\n", ch3);
    printf("CH3 OCT %o\n", ch3);
    printf("CH3 HEX %x\n", ch3);

    // LETRA E
    isupper(ch1) ? ch3 = 'A' : ch3 = ' ';

    // LETRA f
    islower(ch2) ? ch3 = 'a' : ch3 = ' ';

    // LETRA G
    isdigit(ch1) && isdigit(ch2) ? ch3 = '1' : ch3 = ' ';

    return 0;
}
