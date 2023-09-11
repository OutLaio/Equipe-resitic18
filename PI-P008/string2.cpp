#include <iostream>
#include <string.h>
using namespace std;

void ordemAlpha(string &carac, int n);

int main(){
    srand(time(NULL));

    string A, B;

    // LETRA A
    for(int i=0; i<10; i++){
        A.push_back('a' + rand()%('z' - 'a'));
        B.push_back('a' + rand()%('z' - 'a'));
    }

    // LETRA B
    A.at(0) = toupper(A.at(0));
    B.at(0) = toupper(B.at(0));

    cout << "Sem Ordem Alfabética: " << endl << "A: " << A << endl;
    cout << "B: " << B << endl;

    // LETRA C

    ordemAlpha(A, A.length());
    ordemAlpha(B, B.length());

    cout << endl << "Ordem Alfabética: " << endl << "A: " << A << endl;
    cout << "B: " << B << endl;

    return 0;
}

void ordemAlpha(string &carac, int n){
    bool trocou;
    for (int i=0; i<n-1; i++) {
        trocou = false;
        for (int j=0; j<n-i-1; j++) {
            if (tolower(carac[j]) > tolower(carac[j + 1])) {
                swap(carac[j], carac[j + 1]);
                trocou = true;
            }
        }
        if (trocou == false)
            break;
    }
}