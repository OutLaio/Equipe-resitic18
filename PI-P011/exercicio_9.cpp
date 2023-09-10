#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<math.h>

using namespace std;

float calc_serie(int N){
    float serie = 0.0;
    for (float i = 0.0; i < N; i += 1.0){
        serie += (i+1)/(N-i);
    }
    return serie;
}

int main(){
    
    cout << calc_serie(5) << endl;
    
    return 0;
}