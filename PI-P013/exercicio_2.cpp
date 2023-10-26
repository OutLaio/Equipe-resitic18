#include <iostream>
#include <vector>
using namespace std;

struct EMPREGADO {
    string nome;
    string sobrenome;
    string anoNascimento;
    string Rg;
    string anoAdmissao;
    double salario;
};

vector<EMPREGADO> empregados;
size_t quantidadeMaxima = 50;

void reajusta_dez_porcent(){
    for(size_t i=0; i<empregados.size(); i++){
        empregados.at(i).salario += empregados.at(i).salario * 0.10;
    }
}
void cadastraEmpregado(){
    system("clear");
    if(empregados.size() < quantidadeMaxima){
        EMPREGADO e;
        cout << "Digite o primeiro nome: ";
        cin >> e.nome;
        cout << "Digite o ultimo sobrenome: ";
        cin >> e.sobrenome;
        cout << "Digite a data de nascimento: ";
        cin >> e.anoNascimento;
        cout << "Digite seu RG: ";
        cin >> e.Rg;
        cout << "Digite o ano de Admissão: ";
        cin >> e.anoAdmissao;
        cout << "Digite seu salario (ex: 2560.00): ";
        cin >> e.salario;
        empregados.push_back(e);
        cout << endl << "Empregado cadastrado!" << endl << endl;
    } else cout << "Limite máximo de empregados atingidos" << endl;
}
void exibeEmpregados(){
    cout << "NOME\t\t\t" << "NOVO SALÁRIO" << endl;
    for(EMPREGADO e : empregados){
        cout << e.nome << " " << e.sobrenome;
        if((e.nome.length() + e.sobrenome.length()) < 10) cout << "\t\t\t";
        else if((e.nome.length() + e.sobrenome.length()) < 15) cout << "\t\t";
        else cout << "\t";
        cout << e.salario << endl;
    }
}

int main(){

    cadastraEmpregado();
    cadastraEmpregado();

    cout << endl << "Antes do reajuste:" << endl;
    exibeEmpregados();

    reajusta_dez_porcent();

    cout << endl << "Após o reajuste: " << endl;
    exibeEmpregados();

    return 0;
}
