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

    a = toupper(str1.at(0));
    str1.replace(str1.begin(), str1.begin()+1, a);
    a = toupper(str2.at(0));
    str2.replace(str2.begin(), str2.begin()+1, a);

    cout << endl << str1 << " - " << str2 << endl;    

    return 0;
}