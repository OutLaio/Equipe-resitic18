#include <iostream>

using namespace std;

int main() {
    int altura;
    char ch = 'A';

    cout << "Digite a altura do padrao: ";
    cin >> altura;

    for (int i = 1; i <= altura; i++) {
        for (int j = 1; j <= i; j++) {
            cout << ch;
            ch++;
        }
        cout << endl;
    }

    return 0;
}