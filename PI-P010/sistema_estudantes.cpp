#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <iomanip>
#include <cstdlib>

using namespace std;

#ifdef _WIN32
#include <windows.h>
#define CLEAR_SCREEN "cls"
#else
#include <unistd.h>
#define CLEAR_SCREEN "clear"
#endif

// Variáveis globais
size_t qntEstudantes = 0, maiorNome = 0;
bool alteracao = false;
vector<string> nomesEstudantes;
vector<float> notasEstudantes;

/**
 * @brief Função para controlar escolha do usuário em menus.
*/
void inicio();
/**
 * @brief Função para exibir menu incial.
*/
void menuPrincipal();
/**
 * @brief Função para exibir menu de alteração de dados.
*/
void menuAlterar();
/**
 * @brief Função para controlar inserção de estudantes.
*/
void inserirEstudante();
/**
 * @brief Função para controlar exclusão de estudantes.
*/
void excluirEstudante();
/**
 * @brief Função para alterar os dados dos estudantes.
*/
void alterarEstudante();
/**
 * @brief Função para imprimir tabela com nomes e notas.
*/
void tabelaEstudantes();
/**
 * @brief Função para ordenar lexicográficamente lista de nomes.
 * @param nomes Vector<string> com nomes dos estudantes.
 * @param notas Vector<string> com as notas dos estudantes.
*/
void ordenaAbc(vector<string> &nomes, vector<float> &notas);
/**
 * @brief Função para encontrar o maior nome entre os estudantes para ajustar a tabela.
*/
void procuraMaiorNome();

// INICO DO PROGRAMA
int main(){
    inicio();
    return 0;
}

void inicio(){

    int escolhaUsuario;
    system(CLEAR_SCREEN);
    
    do{
        cout << "\t **CADASTRO DE ESTUDANTES **" << endl << endl;
        cout << "Defina um limite de estudantes [1 a X]: ";
        cin >> qntEstudantes;
        if(qntEstudantes < 1) cout << "ERROR: Limite precisa ser poitivo e maior que 0!" << endl << endl;
    }while(qntEstudantes < 1);
    
    system(CLEAR_SCREEN);

    do{
        escolhaUsuario = 0;
        menuPrincipal();
        cin >> escolhaUsuario;    
        
        switch(escolhaUsuario){
            case 1:
                if(nomesEstudantes.size() < qntEstudantes)
                    inserirEstudante();
                else
                    cout << "ERROR: Limite de estudantes atingidos!" << endl;
                break;
            case 2:
                excluirEstudante();                
                break;
            case 3:
                if(nomesEstudantes.size() > 0) alterarEstudante();
                else cout << "Não há dados para alterar! Insira um estudante." << endl;
                break;
            case 4:
                if(nomesEstudantes.size() > 0) tabelaEstudantes();
                else cout << "Tabela vazia! Insira um estudante." << endl;
                break;
            case 5:
                cout << "Encerrando sistema..." << endl;
                break;
            default:
                cout << endl << "ERROR: Nenhuma opção escolhida. Digite novamente!" << endl << endl;
                break;
        }
    }while(escolhaUsuario != 5);

}
void menuPrincipal(){
    cout << endl << "Armazenado/Limite: [" << nomesEstudantes.size() << "/" << qntEstudantes << "]" << endl;
    cout << endl << "Escolha [1 a 4]" << endl;
    cout << "1. Adicionar estudante" << endl;
    cout << "2. Excluir estudante" << endl;
    cout << "3. Alterar estudante" << endl;
    cout << "4. Tabela estudantes" << endl;
    cout << "5. Sair" << endl;
    cout << "> ";
}
void menuAlterar(){
    cout << endl << "Escolha o que deseja alterar:" << endl;
    cout << "1. Nome" << endl;
    cout << "2. Nota I" << endl;
    cout << "3. Nota II" << endl;
    cout << "4. Voltar" << endl;
    cout << "> ";
}
void inserirEstudante(){
    string nome;
    float notaI, notaII;

    system(CLEAR_SCREEN);

    cout << "Digite o nome do aluno:" << endl << "> ";
    cin.ignore();
    getline(cin, nome);

    cout << endl << "Nota I: ";
    cin >> notaI;

    cout << "Nota II: ";
    cin >> notaII;
    
    nomesEstudantes.push_back(nome);
    notasEstudantes.push_back(notaI);
    notasEstudantes.push_back(notaII);
    
    alteracao = true; // Controle de alteração da lista;

    cout << "Estudante cadastrado com sucesso!" << endl;
}
void excluirEstudante(){
    string nome = "";
    bool estudanteEncontrado = false;
    
    system(CLEAR_SCREEN);

    tabelaEstudantes();

    cout << endl << "Obs: Atente-se a escrita do nome." << endl;
    cout << "Digite o nome do estudante que irá deletar:" << endl << "> ";
    cin.ignore();
    cin >> nome;

    for(size_t i=0; i<nomesEstudantes.size(); i++){
        if(nomesEstudantes.at(i) == nome){
            estudanteEncontrado = true;
            nomesEstudantes.erase(nomesEstudantes.begin()+i);
            notasEstudantes.erase(notasEstudantes.begin()+(i*2));
            notasEstudantes.erase(notasEstudantes.begin()+((i*2)+1));
        }
    }

    if(estudanteEncontrado) cout << "Estudante deletado com sucesso!" << endl;
    else cout << "Estudante não encontrado. Verifique se digitou corretamente." << endl;
}
void alterarEstudante(){
    string nomeEscolhido = "", novoNome = "";
    float novaNota = 0.0;
    int escolhaAlterar = 0, indexEstudante = 0;
    bool estudanteEncontrado = false;

    system(CLEAR_SCREEN);

    do{
        tabelaEstudantes();

        cout << endl << "Obs: Atente-se a escrita do nome." << endl;
        cout << "Digite o nome do estudante que irá alterar:" << endl << "> ";
        cin.ignore();
        getline(cin, nomeEscolhido);

        for(size_t i=0; i<nomesEstudantes.size(); i++){
            if(nomesEstudantes.at(i) == nomeEscolhido){
                indexEstudante = i;
                estudanteEncontrado = true;
            }
        }
        if(!estudanteEncontrado) cout << "Estudante não encontrando. Verifique se digitou corretamente." << endl;
    }while(!estudanteEncontrado);

    do{
        escolhaAlterar = 0;
        novoNome = "";
        novaNota = 0.0;

        menuAlterar();
        cin >> escolhaAlterar;

        switch(escolhaAlterar){
            case 1:
                system(CLEAR_SCREEN);
                cout << endl << "Alterar o nome de " << nomesEstudantes.at(indexEstudante) << " para: " << endl << "> ";
                cin.ignore();
                getline(cin, novoNome);
                replace(nomesEstudantes.begin(), nomesEstudantes.end(), nomesEstudantes.at(indexEstudante), novoNome);
                break;
            case 2:
                system(CLEAR_SCREEN);
                cout << endl << "Alterar a nota de " << notasEstudantes.at(indexEstudante*2) << " para: " << endl << "> ";
                cin >> novaNota;
                notasEstudantes[indexEstudante*2] = novaNota;
                break;
            case 3:
                system(CLEAR_SCREEN);
                cout << endl << "Alterar a nota de " << notasEstudantes.at((indexEstudante*2)+1) << " para: " << endl << "> ";
                cin >> novaNota;
                notasEstudantes[(indexEstudante*2)+1] = novaNota;
                break;
            case 4:
                cout << "Voltando para menu principal..." << endl;
                break;
            default:
                cout << endl << "ERROR: Nenhuma opção escolhida. Digite novamente!" << endl << endl;
                break;
        }
    }while(escolhaAlterar != 4);
}
void tabelaEstudantes(){
    int contador = 0;
    float media = 0.0;
    string resultado = "";

    system(CLEAR_SCREEN);

    if(alteracao){
        ordenaAbc(nomesEstudantes, notasEstudantes);
        procuraMaiorNome();
    }
    alteracao = false;

    cout << endl << "** DADOS DOS ALUNOS **";
    cout << endl << "Nomes" << setw(maiorNome + 5) << "Nota I" << setw(10) << "Nota II" << setw(10) << "Média" << endl;
    for(string nome : nomesEstudantes){

        media = (notasEstudantes.at(contador) + notasEstudantes.at(contador + 1)) / 2;
        (media >= 7) ? resultado = "(APROVADO)" : resultado = "(REPROVADO)";

        cout << nome << setw(maiorNome - nome.length() + 10)
        << notasEstudantes.at(contador) << setw(10)
        << notasEstudantes.at(contador + 1) << setw(9)
        << media << " " << resultado << endl;
        
        contador += 2;
    }
}
void ordenaAbc(vector<string> &nomes, vector<float> &notas){
    int n = nomes.size() - 1;
    int contador = 0;
    bool trocou;

    do{
        trocou = false;
        for(int i=0; i<n; i++){
            contador = 0;
            while(nomes.at(i).at(contador) == nomes.at(i+1).at(contador)) contador++;
            
            if(tolower(nomes.at(i).at(contador)) > tolower(nomes.at(i+1).at(contador))){
                swap(nomes.at(i), nomes.at(i+1));
                swap(notas.at(i*2), notas.at((i+1)*2));
                swap(notas.at(i*2+1), notas.at((i+1)*2+1));
                trocou = true;
            }
        }
        n--;
    }while(trocou);
}
void procuraMaiorNome(){
    for(string nome : nomesEstudantes) if(nome.length() > maiorNome) maiorNome = nome.length();
}