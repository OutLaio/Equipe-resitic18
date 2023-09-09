#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<math.h>

using namespace std;

void calcula(int* x, int* y){
    int a = *x, b = *y;
    *x = a + b;
    *y = a - b;
}

int main(){
    int a = 5, b = 3;

    calcula(&a, &b);

    cout << a << " " << b << endl;
    
    return 0;
}