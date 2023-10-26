#include <iostream>
using namespace std;

string caracComum(string p1, string p2);

int main() {
    string palavra1 = "jklmno";
    string palavra2 = "mnopqrstu";

    cout << "Caracteres comum: " << caracComum(palavra1, palavra2) << endl;

    return 0;
}
string caracComum(string p1, string p2) {
    string comums = "";
    
    for (size_t i = 0; i < p1.length(); i++){
        for (size_t j = 0; j < p2.length(); j++){
            if(p2[j] == p1[i]) comums.push_back(p2[j]);
        }
    }
    return comums;
}