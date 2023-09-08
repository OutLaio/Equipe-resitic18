#include<iostream>
#include<sstream>
#include<string>

using namespace std;

int main(){
    string data, temp;
    int dia, mes, ano;

    cout << "Digite uma data: ";
    cin >> data;

    istringstream str(data);

    getline(str, temp, '/');
    dia = stoi(temp);
    getline(str, temp, '/');
    mes = stoi(temp);
    getline(str, temp, '/');
    ano = stoi(temp);

    cout << "Dia: " << dia << endl
         << "Mes: " << mes << endl
         << "Ano: " << ano << endl;

    return 0;
}