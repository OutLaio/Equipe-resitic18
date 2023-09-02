#include<iostream>
#include<math.h>

using namespace std;

int main(){
    int a;
    short int b;
    bool flag;

    cout << "Digite um numero: ";
    cin >> a;

    flag = ((a < (pow(2,8*sizeof(b))/2)) && (a >= -(pow(2,8*sizeof(b))/2)));

    if (flag){
        cout << a << " este valor pertence ao intervalo dos short int" << endl;
    }else{
        cout << a << " e maior que um short int" << endl;
    }
    
    return 0;
}