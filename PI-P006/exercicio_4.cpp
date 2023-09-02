#include<iostream>
#include<math.h>

using namespace std;

int main(){
    double x, y, z;

    cout <<endl << "Digite um numero: ";
    cin >> x;
    cout << "Digite outro numero: ";
    cin >> y;

    z = (x>y ? x : y);

    cout << endl << "O maior eh: " << z << endl;

    return 0;
}