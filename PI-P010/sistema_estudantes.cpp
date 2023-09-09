#include <iostream>
#include <vector>
#include <cstdlib>
#include <iomanip>

#ifdef _WIN32
#include <windows.h>
#define CLEAR_SCREEN "cls"
#else
#include <unistd.h>
#define CLEAR_SCREEN "clear"
#endif

using namespace std;

/**
 * @brief Função estática para ordenar lexicográficamente lista de nomes.
 * @param palavras Vector<string> com nomes.
*/
static void ordenaAbc(vector<string> &palavras);

/**
 * @brief Função estática para imprimir tabela com nomes e notas.
 * @param nomes Vector<string> com nomes.
 * @param notas Vector<float> com duas notas por aluno.
 * @param maiorNome Inteiro com valor do maior nome inserido no vector de nomes.
*/
static void tabelaEstudantes(vector<string> nomes, vector<float> notas, int maiorNome);

/**
 * @brief Função estática para controlar adição de alunos a lista de nomes.
 * @param resposta Booleano com controle sobre o loop do-while.
*/
static void perguntaIncluir(bool &resposta);

/**
 * @brief Função estática para controlar exclusão de estudantes.
 * @param resposta Booleano com controle sobre o loop do-while.
 * @param nomes Vector<string> com nomes.
 * @param notas Vector<float> com duas notas por aluno.
*/
static void perguntaRetirar(bool &resposta, vector<string> &nomesAlunos, vector<float> &notasAlunos);

int main(){

    int maiorNome = 0, qntAlunos;
    bool escolhaUsuario = true;
    vector<string> nomeAlunos;
    vector<float> notasAlunos;

    cout << "Bem vindo ao Sistema de Notas dos Estudantes" << endl << endl;
    cout << "Digite quantos alunos serão cadastrados:" << endl << "> ";
    cin >> qntAlunos;

    // Preenchendo nomes e notas
    do{
        system(CLEAR_SCREEN); // Limpando terminal

        string nomeAluno;
        float notaI, notaII;
        cout << "Digite o nome do aluno:" << endl << "> ";
        cin.ignore();
        getline(cin, nomeAluno);

        cout << endl << "Nota I: ";
        cin >> notaI;
        cout << "Nota II: ";
        cin >> notaII;

        // Obter maior nome inserido
        if(nomeAluno.length() > maiorNome) maiorNome = nomeAluno.length();

        nomeAlunos.push_back(nomeAluno);
        notasAlunos.push_back(notaI);
        notasAlunos.push_back(notaII);

        if(nomeAlunos.size() >= qntAlunos){
            cout << endl << "Quantidade máxima de alunos atingidas!" << endl << endl;
            tabelaEstudantes(nomeAlunos, notasAlunos, maiorNome);
            perguntaRetirar(escolhaUsuario, nomeAlunos, notasAlunos);
        }
        else {
            perguntaIncluir(escolhaUsuario);
            system(CLEAR_SCREEN); // Limpando terminal
            if(!escolhaUsuario){
                tabelaEstudantes(nomeAlunos, notasAlunos, maiorNome);
                perguntaRetirar(escolhaUsuario, nomeAlunos, notasAlunos);
            }
        }

    }while(escolhaUsuario && (nomeAlunos.size() < qntAlunos));

    // Ordenando nomes
    ordenaAbc(nomeAlunos);

    tabelaEstudantes(nomeAlunos, notasAlunos, maiorNome);

    return 0;
}
static void perguntaRetirar(bool &resposta, vector<string> &nomesAlunos, vector<float> &notasAlunos){
    char resp;
    do{
        cout << endl << "Desejan excluir algum aluno (s/n)" << endl << "> ";
        cin.ignore();
        cin >> resp;
    }while(resp != 's' && resp != 'n');
    
    if(resp == 's'){
        
    } else{
        resposta = false;
    }
}
static void perguntaIncluir(bool &resposta){
    char resp;
    do{
        cout << endl << "Desejan incluir mais alunos (s/n)" << endl << "> ";
        cin.ignore();
        cin >> resp;
    }while(resp != 's' && resp != 'n');
    if(resp == 'n') resposta = false;
}
static void tabelaEstudantes(vector<string> nomes, vector<float> notas, int maiorNome){
    int contador = 0;
    
    system(CLEAR_SCREEN); // Limpando terminal

    cout << endl << "** DADOS DOS ALUNOS **";
    cout << endl << "Nomes" << setw(maiorNome + 5) << "Nota I" << setw(10) << "Nota II" << endl;
    for(string nome : nomes){
        cout << nome << setw(maiorNome - nome.length() + 10)
        << notas.at(contador) << setw(10)
        << notas.at(contador + 1) << endl;
        contador += 2;
    }
}
static void ordenaAbc(vector<string> &palavras){
    int n = palavras.size() - 1, cont = 0;
    bool trocou;

    do{
        trocou = false;
        for(int i=0; i<n; i++){
            cont = 0;
            while(palavras.at(i).at(cont) == palavras.at(i+1).at(cont)) cont++;
            
            if(tolower(palavras.at(i).at(cont)) > tolower(palavras.at(i+1).at(cont))){
                swap(palavras.at(i), palavras.at(i+1));
                trocou = true;
            }
        }
        n--;
    }while(trocou);
}