#include<iostream>
#include<string>

using namespace std;

int main(){
    string str1, str2, a;

    for (int i = 0; i < 10; i++){
        a = 'a' + rand()%('z'-'a');
        str1.insert(i, a);
        a = 'a' + rand()%('z'-'a');
        str2.insert(i, a);
    }

    cout << endl << str1 << " - " << str2 << endl;    

    return 0;
}