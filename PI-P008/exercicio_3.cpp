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
        case 1:
            temp = "janeiro";
            if(dia > 31)
                erro = true;
            break;
        case 2:
            temp = "fevereiro";
            if(dia > 29)
                erro = true;
            break;
        case 3:
            temp = "marco";
            if(dia > 31)
                erro = true;
            break;
        case 4:
            temp = "abril";
            if(dia > 30)
                erro = true;
            break;
        case 5:
            temp = "maio";
            if(dia > 31)
                erro = true;
            break;
        case 6:
            temp = "junho";
            if(dia > 30)
                erro = true;
            break;
        case 7:
            temp = "julho";
            if(dia > 31)
                erro = true;
            break;
        case 8:
            temp = "agosto";
            if(dia > 31)
                erro = true;
            break;
        case 9:
            temp = "setembro";
            if(dia > 30)
                erro = true;
            break;
        case 10:
            temp = "outubro";
            if(dia > 31)
                erro = true;
            break;
        case 11:
            temp = "novembro";
            if(dia > 30)
                erro = true;
            break;
        case 12:
            temp = "dezembro";
            if(dia > 31)
                erro = true;
            break;
        default:
            erro = true;
            break;
    }
    
    if (erro){
        cout << "Data invalida!!" << endl;
    }else{
        cout << endl << dia << " de " << temp << " de " << ano << endl;
    }


    return 0;
}