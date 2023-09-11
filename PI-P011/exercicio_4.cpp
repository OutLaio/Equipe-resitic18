#include <iostream>
using namespace std;

void calcula(int &x, int &y);

int main(){

    int x, y;

    cout << "Digite dois numeros [x y]: ";
    cin >> x >> y;

    calcula(x, y);

    cout << "Valor de x: " << x << endl;
    cout << "Valor de y: " << y << endl;

    return 0;
}
void calcula(int &x, int &y){
    int temp = x;
    x = x + y;
    y = y - temp;
}