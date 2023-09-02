#include<iostream>
#include<math.h>

using namespace std;

int main(){

    double x, y, z;
    int a;

    cout << "Digite um numero real: ";
    cin >> x;
    cout << "Digite outro numero real: ";
    cin >> y;

    z = sqrt(pow(x,2)+pow(y,2));

    cout << "A distancia euclidiana do ponto (" << x << ", " << y << ") eh: " << z << endl;

    return 0;
}