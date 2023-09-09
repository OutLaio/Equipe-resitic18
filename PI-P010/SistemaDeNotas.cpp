#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<conio.h>
#include <algorithm>
#include<math.h>

using namespace std;

int qtdAlunos(void){
    int n;
    system("cls");
    cout << "Digite a quantidade limite de alunos: ";
    cin >> n;
    return n;
}

void dispMenu(int posicao){
    system("cls");
    cout << "Ola, o que deseja?" << endl << endl;
    for (int i = 0; i < 5; i++){
        if (i == posicao)
            cout << "-> ";
        switch (i){
            case 0:
                cout << "Inserir um aluno" << endl;
                break;
            case 1:
                cout << "Excluir um aluno" << endl;
                break;
            case 2:
                cout << "Alterar nota" << endl;
                break;
            case 3:
                cout << "Visualizar notas" << endl;
                break;
            case 4:
                cout << "Sair" << endl;
                break;
        default:
            break;
        }
    }
}

void insere(vector<string> &alunos, vector<float> &notas, int n){
    string aluno;
    float n1, n2, media;

    if(alunos.size() == n){
        system("cls");
        cout << "Limite de alunos cadastrados atingido!" << endl;
        cout << endl << "(Pressione qualquer tecla para continuar...)";
        _getch();
        return;
    }

    system("cls");
    cout << "Digite o nome do aluno:" << endl << ">";
    cin >> aluno;
    cout << "Digite a nota #1 do aluno:" << endl << ">";
    cin >> n1;
    cout << "Digite a nota #2 do aluno:" << endl << ">";
    cin >> n2;
    media = (n1+n2)/2;

    if (alunos.empty()){
        alunos.insert(alunos.begin(), aluno);
        notas.insert(notas.begin(), n1);
        notas.insert(notas.begin()+1, n2);
        notas.insert(notas.begin()+2, media);
    }else if(aluno.compare(alunos.back()) >= 0){
        alunos.insert(alunos.end(), aluno);
        notas.insert((notas.end()), n1);
        notas.insert((notas.end()), n2);
        notas.insert((notas.end()), media);
    }else{
        for (size_t i = 0; i < alunos.size(); i++){
            if(aluno.compare(alunos.at(i)) < 0){
                alunos.insert(alunos.begin()+i, aluno);
                notas.insert(notas.begin()+(i*3), n1);
                notas.insert(notas.begin()+(i*3+1), n2);
                notas.insert(notas.begin()+(i*3+2), media);
                break;
            }
        }
    }
    return;
}

void excluir(vector<string> &alunos, vector<float> &notas){
    string aluno;
    
    if(alunos.size() == 0){
        system("cls");
        cout << "Nao ha alunos cadastrados!" << endl;
        cout << endl << "(Pressione qualquer tecla para continuar...)";
        _getch();
        return;
    }

    system("cls");
    cout << "Digite o nome do aluno:" << endl << ">";
    cin >> aluno;

    auto it = find(alunos.begin(), alunos.end(), aluno);
    if(it == alunos.end()){
        cout << endl << "Aluno nao encontrado!" << endl
             << "(Pressione qualquer tecla para continuar...)";
        system("pause");
    }else{
        size_t pos = distance(alunos.begin(), it);
        alunos.erase(alunos.begin()+pos);
        notas.erase(notas.begin()+pos*3, notas.begin()+(pos*3+3));
    }
}

void altera(vector<string> &alunos, vector<float> &notas){
    string aluno;
    float nota;
    size_t id;
    
    if(alunos.size() == 0){
        system("cls");
        cout << "Nao ha alunos cadastrados!" << endl;
        cout << endl << "(Pressione qualquer tecla para continuar...)";
        _getch();
        return;
    }

    system("cls");
    cout << "Digite o nome do aluno:" << endl << ">";
    cin >> aluno;

    auto it = find(alunos.begin(), alunos.end(), aluno);
    if(it == alunos.end()){
        cout << endl << "Aluno nao encontrado!" << endl
             << "(Pressione qualquer tecla para continuar...)";
        system("pause");
    }else{
        size_t pos = distance(alunos.begin(), it);
        system("cls");
        cout << "O aluno " << alunos.at(pos) << " possui as notas:" << endl << endl
             << "Nota #1: " << notas.at(pos*3) << endl << "Nota #2: " << notas.at(pos*3+1)
             << endl << "Media = " << notas.at(pos*3+2) << endl;
        cout << endl << "Qual nota deseja alterar? (Digite 0 para voltar)" << endl << "#";
        cin >> id;
        
        while (id != 1 && id != 2){
            if(id == 0)
                return;
            system("cls");
            cout << "O aluno " << alunos.at(pos) << " possui as notas:" << endl << endl
                 << "Nota #1 " << notas.at(pos*3) << endl << "Nota #2 " << notas.at(pos*3+1)
                 << endl << "media = " << notas.at(pos*3+2) << endl;
            cout << endl << "Digite um id valido (#1, #2 ou #0 para sair):" << endl << "#";
            cin >> id;
        }
        cout << "Digite a nova nota:" << endl << ">";
        cin >> nota;

        notas[pos*3+id-1] = nota;
        notas[pos*3+2] = (notas[pos*3]+notas[pos*3+1])/2;
    }
    return;
}

void imprime(vector<string> &alunos, vector<float> &notas){
    if(alunos.size() == 0){
        system("cls");
        cout << "Nao ha alunos cadastrados!" << endl;
        cout << endl << "(Pressione qualquer tecla para continuar...)";
        _getch();
        return;
    }
    system("cls");
    cout << "Aluno\tNota #1\tNota #2\tMedia\tSituacao" << endl << endl;
    for (size_t i = 0; i < alunos.size(); i++){
        cout << alunos[i] << "\t"
             << notas[i*3] << "\t"
             << notas[i*3+1] << "\t"
             << notas[i*3+2] << "\t"
             << (notas[i*3+2] >= 7 ? "APROVADO" : "REPROVADO") << endl;
    }
    
}

void menuOpcoes(void){
    int seta, posicao = 0, n = qtdAlunos();
    vector<string> alunos;
    vector<float> notas;
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
                insere(alunos, notas, n);
                break;
            case 1:
                excluir(alunos, notas);
                break;
            case 2:
                altera(alunos, notas);
                break;
            case 3:
                imprime(alunos, notas);
                system("pause");
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