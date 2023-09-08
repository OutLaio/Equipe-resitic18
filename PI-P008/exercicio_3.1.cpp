#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
    int n = 10, k = 0;
    bool flag;
    vector<string> str;
    string str1, a;

    for (int j = 0; j < n; j++){
        for (int i = 0; i < 10; i++){
            a = 'a' + rand()%('z'-'a');
            str1.replace(str1.begin()+i, str1.end(), a);
        }
        a = toupper(str1.at(0));
        str1.replace(0, 1, a);
        str.insert(str.begin()+j, str1);
    }
    
    do{
        flag = false;
        k++;
        for (int i = 0; i < n-k; i++){
            if (str.at(i).compare(str.at(i+1))>0){
                str.at(i).swap(str.at(i+1));
                flag = true;
            }
        }
    } while (flag);
    

    for (int i = 0; i < n; i++){
        cout << str.at(i) << endl;
    }
    
    return 0;
}