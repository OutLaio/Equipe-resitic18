#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<math.h>

using namespace std;

typedef struct T_passagem{
    string nome, cpf, data, hora;
    int idade, linha, acento;
} Passagem;

void dispLinhas(int posicao){
    system("cls");
    cout << "======= Viacao Residencia =======" << endl << endl;
    cout << "== Selecione a linha da viagem ==" << endl << endl;
    for (int i = 0; i < 10; i++){
        if (i == posicao)
            cout << "-> ";
        switch (i){
            case 0:
                cout << "IDA ---- 08:00h -- RJ x SP" << endl;
                break;
            case 1:
                cout << "VOLTA -- 09:00h -- SP x RJ" << endl;
                break;
            case 2:
                cout << "IDA ---- 10:00h -- RJ x SP" << endl;
                break;
            case 3:
                cout << "VOLTA -- 11:00h -- SP x RJ" << endl;
                break;
            case 4:
                cout << "IDA ---- 12:00h -- RJ x SP" << endl;
                break;
            case 5:
                cout << "VOLTA -- 13:00h -- SP x RJ" << endl;
                break;
            case 6:
                cout << "IDA ---- 14:00h -- RJ x SP" << endl;
                break;
            case 7:
                cout << "VOLTA -- 15:00h -- SP x RJ" << endl;
                break;
            case 8:
                cout << "IDA ---- 16:00h -- RJ x SP" << endl;
                break;
            case 9:
                cout << "VOLTA -- 17:00h -- SP x RJ" << endl;
                break;
        default:
            break;
        }
    }
}

int linhaOpcoes(void){
    int seta, posicao = 0;
    do{
        if(seta==80)
            posicao++;
        if(seta==72)
            posicao--;
        if(posicao>9)
            posicao=0;
        if(posicao<0)
            posicao=9;

        dispLinhas(posicao);
        seta = _getch();

        if(seta == 13){
            return posicao+1;
        }
    } while (seta!=27);
    return 0;
}

string getData(){
    string temp, data;
    int dia, mes;
    bool erro;

    system("cls");
    cout << "Informe a data da viagem:" << endl << "> ";
    cin >> data;

    do{
        erro = false;
        istringstream str(data);

        getline(str, temp, '/');
        dia = stoi(temp);
        getline(str, temp, '/');
        mes = stoi(temp);

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
        if(erro){
            system("cls");
            cout << "Por favor, digite uma data valida:" << endl << "> ";
            cin >> data;
        }
    } while (erro);
    
    return data;
}

string getHora(int linha){
    string hora;
    switch (linha){
        case 0:
            hora = "08:00";
            break;
        case 1:
            hora = "09:00";
            break;
        case 2:
            hora = "10:00";
            break;
        case 3:
            hora = "11:00";
            break;
        case 4:
            hora = "12:00";
            break;
        case 5:
            hora = "13:00";
            break;
        case 6:
            hora = "14:00";
            break;
        case 7:
            hora = "15:00";
            break;
        case 8:
            hora = "16:00";
            break;
        case 9:
            hora = "17:00";
            break;
        default:
            break;
    }
    return hora;
}

void dispAcento(void){
    system("cls");
    int vet[40] = {0};
    vet[0] = 1;
    vet[9] = 1;
    vet[15] = 1;


    for (int i = 1; i <= 4; i++){
        cout << "\t\t";
        for (int j = 0; j < 10; j++){
            if (vet[4*j + i - 1] == 1){
                cout << "--" << "  ";
            }else{
                if(j*4 + i < 10)
                    cout << " ";
                cout << (j*4 + i) << "  ";
            }
        }
        cout << endl;
        if(i == 2){
            cout << endl;
        }
    }
    
}

int getAcento(void){
    int acento;

    dispAcento();


    return acento;
}

void getDados(Passagem* passageiro){
    
    passageiro->data = getData();
    passageiro->linha = linhaOpcoes();
    passageiro->hora = getHora(passageiro->linha);
    passageiro->acento = getAcento();
    passageiro->nome = 
    passageiro->cpf = 
    passageiro->idade = 
    
    return;
}

void incluirPassagem(vector<vector<Passagem>> viagens){
    Passagem passageiro;

    getDados(&passageiro);
}

void dispMenu(int posicao){
    system("cls");
    cout << "======= Viacao Residencia =======" << endl << endl;
    for (int i = 0; i < 5; i++){
        if (i == posicao)
            cout << "-> ";
        switch (i){
            case 0:
                cout << "Registrar passagem" << endl;
                break;
            case 1:
                cout << "Exibir informacoes sobre passageiros" << endl;
                break;
            case 2:
                cout << "Arrecadacoes" << endl;
                break;
            case 3:
                cout << "Medias de idade dos passageiros" << endl << endl;
                break;
            case 4:
                cout << "Sair" << endl;
                break;
        default:
            break;
        }
    }
}

void menuOpcoes(void){
    int seta, posicao = 0;
    vector<vector<Passagem>> viagens;
    do{
        if(seta==80)
            posicao++;
        if(seta==72)
            posicao--;
        if(posicao>4)
            posicao=0;
        if(posicao<0)
            posicao=4;

        dispMenu(posicao);
        seta = _getch();

        if(seta == 13){
            switch (posicao){
            case 0:
                incluirPassagem(viagens);
                break;
            case 1:
                buscarInfo(viagens);
                break;
            case 2:
                arrecadacoes(viagens);
                break;
            case 3:
                mediaIdade(viagens);
                break;
            case 4:
                seta = 27;
                break;
            default:
                break;
            }
        }
    } while (seta!=27);
    
}

int main(){

    menuOpcoes();
    system("cls");
    
    return 0;
}