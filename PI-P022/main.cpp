#include <iostream>
#include <vector>
#include <fstream>
#define PAUSE "read -p \"Pressione ENTER para continuar...\" saindo"
using namespace std;

class Tarefa{
  private:
    string titulo;
    string status;
  public:
    string getTitulo(){
      return this->titulo;
    }
    string getStatus(){
      return this->status;
    }
    void setTitulo(string _titulo){
      this->titulo = _titulo;
    }
    void setStatus(string _status){
      this->status = _status;
    }
};
class GerenciadorTarefas{
  public:
    static void adicionarTarefa(vector<Tarefa> &ToDo){
      Tarefa novaTarefa;
      string titulo;
      system("clear");
      cout << "Adicionando Tarefa" << endl;
      cout << "Digite o titulo da tarefa: ";
      cin.ignore();
      getline(cin, titulo);
      novaTarefa.setTitulo(titulo);
      novaTarefa.setStatus("NAO CONCLUIDA");
      ToDo.push_back(novaTarefa);
    }
    static void concluirTarefa(vector<Tarefa> &ToDo){
      int contador = 0, id = 0;
      cout << "Escolha a tarefa e digite o ID" << endl;
      for(Tarefa t : ToDo){
        if(t.getStatus() == "NAO CONCLUIDA") cout << "[" << contador << "] - " << t.getTitulo() << endl;
        contador++;
      }
      cout << endl << "> ";
      cin >> id;
      ToDo[id].setStatus("CONCLUIDA");
      cout << "Tarefa concluída!" << endl;
    }
    static void listarTarefasPendentes(vector<Tarefa> &ToDo){
      system("clear");
      cout << "Tarefas Pendentes" << endl;
      for(Tarefa t : ToDo){
        if(t.getStatus() == "NAO CONCLUIDA") cout << "- " << t.getTitulo() << endl;
      }
    }
};
class BancoDeDados{
  public:
    static void salvaTarefas(vector<Tarefa> &ToDo){
      ofstream arquivo;
      arquivo.open("tarefas.txt", ios_base::out);
      if(arquivo.is_open()){
        for(Tarefa t : ToDo){
          arquivo << t.getTitulo() << "|" << t.getStatus() << endl;
        }
        arquivo.close();
        cout << "AVISO: Tarefa guardada!" << endl;
      } else {
        cout << "AVISO: Erro ao abrir arquivo!" << endl;
      }
    }
    static vector<Tarefa> carregarTarefas(){
      vector<Tarefa> ToDo;
      ifstream arquivo;
      arquivo.open("tarefas.txt");
      if(arquivo.is_open()){
        string linha;
        while(getline(arquivo, linha)){
          string titulo;
          string status;
          int pos = linha.find("|");
          titulo = linha.substr(0, pos);
          status = linha.substr(pos+1);
          Tarefa novaTarefa;
          novaTarefa.setTitulo(titulo);
          novaTarefa.setStatus(status);
          ToDo.push_back(novaTarefa);
        }
        arquivo.close();
      } else {
        cout << "AVISO: Erro ao abrir arquivo!" << endl;
      }
      if(ToDo.size() > 0) return ToDo;
      else return vector<Tarefa>();
    }
};

int main(){
  vector<Tarefa> ToDo = BancoDeDados::carregarTarefas();
  int op;
  do{
    system("clear");
    cout << "1 - Adiciona Tarefa" << endl;
    cout << "2 - Marcar tarefas como concluídas" << endl;
    cout << "3 - Listar todas as tarefas pendentes" << endl;
    cout << "0 - Sair" << endl;
    cout << "> ";
    cin >> op;
    if(op < 0 || op > 3){
      cout << "Opção inválida!" << endl;
      system(PAUSE);
    }
    switch(op){
      case 1:{
        GerenciadorTarefas::adicionarTarefa(ToDo);
        BancoDeDados::salvaTarefas(ToDo);
        system(PAUSE);
        break;
      }
      case 2:
        GerenciadorTarefas::concluirTarefa(ToDo);
        BancoDeDados::salvaTarefas(ToDo);
        system(PAUSE);
        break;
      case 3:
        GerenciadorTarefas::listarTarefasPendentes(ToDo);
        system(PAUSE);
        break;
      default:
        break;
    }
  }while(op != 0);
  return 0;
}
