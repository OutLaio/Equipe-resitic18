#include <iostream>
using namespace std;

void ordenaFloat(float &var1, float &var2, float &var3, float &var4);

int main(){

    float n1, n2, n3, n4;

    cout << "Digite os valores [x y z w]: ";
    cin >> n1 >> n2 >> n3 >> n4;

    cout << "Valores antigos" << endl;
    cout << "N1: " << n1 << endl;
    cout << "N2: " << n2 << endl;
    cout << "N3: " << n3 << endl;
    cout << "N4: " << n4 << endl;

    ordenaFloat(n1, n2, n3, n4);

    cout << endl << "Valores novos" << endl;
    cout << "N1: " << n1 << endl;
    cout << "N2: " << n2 << endl;
    cout << "N3: " << n3 << endl;
    cout << "N4: " << n4 << endl;

    return 0;
}
void ordenaFloat(float &var1, float &var2, float &var3, float &var4){
    float vetorFloats[4] = {var1, var2, var3, var4};
    bool troca;

    do {
        troca = false;
        for (int i = 0; i < 4; i++) {
            if (vetorFloats[i] > vetorFloats[i + 1]) {
                swap(vetorFloats[i], vetorFloats[i+1]);
                troca = true;
            }
        }
    } while (troca);

    var1 = vetorFloats[0];
    var2 = vetorFloats[1];
    var3 = vetorFloats[2];
    var4 = vetorFloats[3];
}