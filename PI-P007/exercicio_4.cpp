#include<iostream>
#include<math.h>

using namespace std;

bool isPrimo(int num) {
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int i;

    cout << "Numeros primos de 1 a 100:" << endl;
    for (i = 1; i <= 100; ++i) {
        if (isPrimo(i)) {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}
