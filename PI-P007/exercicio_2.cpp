#include<iostream>
#include<math.h>

using namespace std;

int main(){
    int num, ori, rev = 0, dig;

    cout << "Digite um numero: ";
    cin >> num;

    ori = num;

    while (num > 0){
        dig = num%10;
        rev = rev*10 + dig;
        num /= 10;
    }
    
    cout << "O numero " << ori << (ori==rev ? " " : " nao ") << "eh palidromo" << endl;

    return 0;
}
