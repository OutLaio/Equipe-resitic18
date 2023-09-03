#include <iostream>
using namespace std;

int main(){

    // Se o valor for maior que 0, será declarado 1.
    bool boolInt = 10;
    // Se o valor for maior que 0.0, será declarado 1.
    bool boolDouble = static_cast<bool>(1.2);
    // Se o valor for maior que 0.0, será declarado 1.
    bool boolFloat = static_cast<bool>(1.5f);
    // Se o caractere for diferente de \0, será declarado 1.
    bool boolChar = static_cast<bool>('\0');

    cout << "Valor convertido para bool (true ou false):" << endl;
    cout << "int: " << boolInt << endl;
    cout << "double: " << boolDouble << endl;
    cout << "float: " << boolFloat << endl;
    cout << "char: " << boolChar << endl;

    return 0;
}
