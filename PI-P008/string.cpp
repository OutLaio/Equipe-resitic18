#include <iostream>
#include <string.h>
using namespace std;

int main(){
    
    // LETRA A
    string data = "20/05/1999";
    //cout << "Digite uma data: ";
    //cin >> data;

    char dataChar[data.length()];
    strcpy(dataChar, data.c_str());

    int dia = atoi(strtok(dataChar, "/"));
    int mes = atoi(strtok(NULL, "/"));
    int ano = atoi(strtok(NULL, "/"));

    cout << "Dia: " << dia << endl << "Mes: " << mes << endl << "Ano: " << ano << endl;
    
    // LETRA B
    if(ano < 0){
        cout << "Ano inválido!" << endl;
    } else {
        if(mes > 12 || mes < 1){
            cout << "Mês inválido!" << endl;
        } else {
            if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){
                if(dia < 1 || dia > 31){
                    cout << "Dia inválido!" << endl;
                }
            } else if(mes == 4 || mes == 6 || mes == 9 || mes == 11){
                if(dia < 1 || dia > 30){
                    cout << "Dia inválido!" << endl;
                }
            } else {
                if(ano % 400 == 0){
                    if(dia < 1 || dia > 29){
                        cout << "Dia inválido!" << endl;
                    }
                } else if(ano % 4 == 0 && ano % 100 != 0){
                    if(dia < 1 || dia > 29){
                        cout << "Dia inválido!" << endl;
                    }
                } else {
                    if(dia < 1 || dia > 28){
                        cout << "Dia inválido!" << endl;
                    }
                }
            }
        }
    }

    // LETRA C
    string meses[12] = {"Janeiro", "Fevereiro", "Março", "Abril", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};

    cout << endl << dia << " de " << meses[mes - 1] << " de " << ano << endl;

    return 0;
}