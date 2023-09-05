#include <iostream>
#include <string.h>
using namespace std;

int main(){
    string data = "20/05/1999";
    char dataChar[] = "20/05/1999";
    int dia = atoi(strtok(dataChar, "/"));
    int mes = atoi(strtok(NULL, "/"));
    int ano = atoi(strtok(NULL, "/"));

    cout << dia << endl << mes << endl << ano << endl;
    
    return 0;
}