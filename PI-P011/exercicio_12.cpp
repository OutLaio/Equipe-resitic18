#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<math.h>

using namespace std;

string intersecao(const string &A, const string &B) {
    string resultado;
    
    for (size_t i = 0; i < A.length(); i++){
        for (size_t j = 0; j < B.length(); j++){
            if(B[j] == A[i]){
                resultado.push_back(B[j]);
            }
        }
    }

    return resultado;
}

int main() {
    string A = "abcdef";
    string B = "defghijk";

    string C = intersecao(A, B);

    cout << "Intersecao das strings A e B: " << C << endl;

    return 0;
}