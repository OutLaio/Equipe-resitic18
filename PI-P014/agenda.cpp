#include<iostream>
#include<sstream>
#include<string>
#include<vector>
//#include<conio.h>
#include<math.h>

using namespace std;

typedef struct T_contato{
    string nome;
    string telefone;
} Contato;

void adicionarContato(vector<Contato> *contatos) {
    Contato novoContato;
    string nome, telefone;

    system("cls");
    cout << "Digite o nome do contato: ";
    cin.ignore();
    getline(cin, nome);
    cout << "Digite o telefone do contato: ";
    getline(cin, telefone);

    novoContato.nome = nome;
    novoContato.telefone = telefone;

    (*contatos).push_back(novoContato);

    cout << "Contato adicionado com sucesso." << endl;
    system("pause");
    return;
}

void removerContato(vector<Contato> *contatos){
    string nomeDelete;
    
    system("cls");
    cout << "Digite o nome do contato para deletar: ";
    cin.ignore();
    getline(cin, nomeDelete);

    for(size_t i=0; i<contatos->size(); i++){
        if(contatos->at(i).nome == nomeDelete){
            contatos->erase(contatos->begin()+i);
            cout << "Contato deletado com sucesso!" << endl;
            return;
        }
    }
}

void dispMenu(int posicao){
    system("cls");
    cout << "======= Agenda Simples =======" << endl << endl;
    for (int i = 0; i < 4; i++){
        if (i == posicao)
            cout << "-> ";
        switch (i){
            case 0:
                cout << "Adicionar Contato" << endl;
                break;
            case 1:
                cout << "Remover Contato" << endl;
                break;
            case 2:
                cout << "Listar Contatos" << endl;
                break;
            case 3:
                cout << "Sair" << endl;
                break;
        default:
            break;
        }
    }
}

void menuOpcoes(void){
    int seta, posicao = 0;
    vector<Contato> contatos;
    do{
        if(seta==80)
            posicao++;
        if(seta==72)
            posicao--;
        if(posicao>3)
            posicao=0;
        if(posicao<0)
            posicao=3;

        dispMenu(posicao);
        //seta = _getch();

        if(seta == 13){
            switch (posicao){
            case 0:
                adicionarContato(&contatos);
                break;
            case 1:
                removerContato(&contatos);
                break;
            case 2:
                // listarContatos(&contatos);
                break;
            case 3:
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