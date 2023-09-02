#include<iostream>
#include<limits>

using namespace std;

int main(){

    cout << "Menor valor de um float: " << numeric_limits<float>::min() << endl;
    cout << "Maior valor de um float: " << numeric_limits<float>::max() << endl;

    return 0;
}