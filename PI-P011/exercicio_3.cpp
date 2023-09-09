#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<math.h>

using namespace std;

void ordena(float* a, float* b, float* c, float* d){
    bool trocou;
    do{
        trocou = false;
        if(*a > *b){
            *a += *b;
            *b = *a - *b;
            *a -= *b;
            trocou = true;
        }
        if(*b > *c){
            *b += *c;
            *c = *b - *c;
            *b -= *c;
            trocou = true;
        }
        if(*c > *d){
            *c += *d;
            *d = *c - *d;
            *c -= *d;
            trocou = true;
        }
    }while(trocou);
}

int main(){
    float a = 9, b = 8, c = 3, d = 1;
    
    cout << a << " " << b << " " << c << " " << d << endl;

    ordena(&a, &b, &c, &d);

    cout << a << " " << b << " " << c << " " << d << endl;
    
    return 0;
}