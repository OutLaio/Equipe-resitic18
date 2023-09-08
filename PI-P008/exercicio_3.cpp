#include<iostream>
#include<sstream>
#include<string>

using namespace std;

int main(){
    string data, temp;
    int dia, mes, ano;
    bool erro = false;

    cout << "Digite uma data: ";
    cin >> data;

    istringstream str(data);

    getline(str, temp, '/');
    dia = stoi(temp);
    getline(str, temp, '/');
    mes = stoi(temp);
    getline(str, temp, '/');
    ano = stoi(temp);

    if (dia < 1){
        erro = true;
    }

    switch (mes){
        case 2:
            if (dia > 29)
                erro = true;
            break;
        case 4:
            if (dia > 30)
                erro = true;
            break;
        case 6:
            if (dia > 30)
                erro = true;
            break;
        case 9:
            if (dia > 30)
                erro = true;
            break;
        case 11:
            if (dia > 30)
                erro = true;
            break;
        default:
            if (dia > 31 || mes > 12)
                erro = true;
            break;
    }
    
    if (erro){
        cout << "Data invalida!!" << endl;
    }else{
        cout << "Dia: " << dia << endl
            << "Mes: " << mes << endl
            << "Ano: " << ano << endl;
    }


    return 0;
}