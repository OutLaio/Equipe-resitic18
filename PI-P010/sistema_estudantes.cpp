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
/**
 * 
*/
size_t qntEstudantes = 0, maiorNome = 0;
bool alteracao = false;
vector<string> nomesEstudantes;
vector<float> notasEstudantes;

/**
 * @brief Função para controlar escolha do usuário em menus.
*/
static void inicio();
/**
 * @brief Função para exibir menu incial.
*/
static void menuPrincipal();
/**
 * @brief Função para controlar inserção de estudantes.
 * @param qntEstudantes Inteiro com a quantidade máxima de estudantes permitida.
*/
static void inserirEstudante();
/**
 * @brief Função para controlar exclusão de estudantes.
 * @param qntEstudantes Inteiro com a quantidade máxima de estudantes permitida.
*/
static void excluirEstudante();
/**
 * @brief Função estática para imprimir tabela com nomes e notas.
 * @param nomes Vector<string> com nomes.
 * @param notas Vector<float> com duas notas por aluno.
 * @param maiorNome Inteiro com valor do maior nome inserido no vector de nomes.
*/
static void tabelaEstudantes();
/**
 * @brief Função estática para ordenar lexicográficamente lista de nomes.
 * @param palavras Vector<string> com nomes dos estudantes.
*/
static void ordenaAbc(vector<string> &nomes);

// INICO DO PROGRAMA
int main(){
    inicio();
    return 0;
}

static void inicio(){

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
                if(nomesEstudantes.size() > 0) tabelaEstudantes();
                else cout << "Tabela vazia! Insira um estudante." << endl;
                break;
            case 4:
                cout << "Encerrando sistema..." << endl;
                break;
            default:
                cout << endl << "ERROR: Nenhuma opção escolhida. Digite novamente!" << endl << endl;
                break;
        }
    }while(escolhaUsuario != 4);

}
static void menuPrincipal(){
    cout << endl << "Armazenado/Limite: [" << nomesEstudantes.size() << "/" << qntEstudantes << "]" << endl;
    cout << endl << "Escolha [1 a 4]" << endl;
    cout << "1. Adicionar estudante" << endl;
    cout << "2. Excluir estudante" << endl;
    cout << "3. Tabela estudantes" << endl;
    cout << "4. Sair" << endl;
    cout << "> ";
}
static void inserirEstudante(){
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

    // Obter maior nome inserido
    if(nome.length() > maiorNome) maiorNome = nome.length();
    
    nomesEstudantes.push_back(nome);
    notasEstudantes.push_back(notaI);
    notasEstudantes.push_back(notaII);
    
    alteracao = true; // Controle de alteração da lista;

    cout << "Estudante cadastrado com sucesso!" << endl;
}
static void excluirEstudante(){
    string nome = "";
    bool estudanteEncontrado = false;
    vector<string>::iterator itNomes;
    vector<float>::iterator itNotas;
    
    system(CLEAR_SCREEN);

    tabelaEstudantes();

    cout << endl << "Obs: Atente-se a escrita do nome." << endl;
    cout << "Digite o nome do aluno que irá deletar:" << endl << "> ";
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

    if(estudanteEncontrado) cout << "Aluno deletado com sucesso!" << endl;
    else cout << "Aluno não encontrado. Verifique se digitou corretamente." << endl;
}
static void tabelaEstudantes(){
    int contador = 0;

    system(CLEAR_SCREEN);

    if(alteracao) ordenaAbc(nomesEstudantes);

    cout << endl << "** DADOS DOS ALUNOS **";
    cout << endl << "Nomes" << setw(maiorNome + 5) << "Nota I" << setw(10) << "Nota II" << endl;
    for(string nome : nomesEstudantes){
        cout << nome << setw(maiorNome - nome.length() + 10)
        << notasEstudantes.at(contador) << setw(10)
        << notasEstudantes.at(contador + 1) << endl;
        contador += 2;
    }
}
static void ordenaAbc(vector<string> &nomes){
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
                trocou = true;
            }
        }
        n--;
    }while(trocou);
}