
#include<iostream>
#include<math.h>

using namespace std;

int main(){
    int i;

    for (i = 1; i <= 100; i++){
        cout << i << " - ";
        cout << (i%3==0 ? "Fizz" : "");
        cout << (i%5==0 ? "Buzz" : "");
        cout << endl;

    }
    return 0;
}