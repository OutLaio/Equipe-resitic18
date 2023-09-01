#include<iostream>
#include<math.h>

using namespace std;

int main(){
    wchar_t a = 'ã';
    
    cout << "'" << a << "' - " << dec << (int)a << " (dec) - " << oct << (int)a << " (oct) - 0x" << hex << (int)a << " (hex) " << endl;

    return 0;
}