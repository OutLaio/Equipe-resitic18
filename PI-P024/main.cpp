#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#define PAUSE "read -p \"Pressione ENTER para continuar...\" saindo"
using namespace std;
// Variavel Global
static int eventosContadorID = 0;
static int pacotesContadorID = 0;
// Cabeçalho de Classe
class Pacote;
class Evento;
class Cliente;
class PacoteCliente;
// Cabeçalho de Função
static void salvarEvento(string rotulo, string nome, int duracao);
static void salvarPacote(Pacote novo);
static void salvarCliente(Cliente novo);
static void salvarVenda(string cpf, int idPacote);
static void eventosContadorId();
static void pacotesContadorId();
static vector<Evento> listaDeEventos();
static vector<Pacote> listaDePacotes();
static vector<Cliente> listaDeClientes();
static void listarClientes();
static Evento eventoEncontrado(string idEvento);
static Pacote pacoteEncontrado(string idPacote);
static Cliente clienteEncontrado(string cpfCliente);
static void mostrarPacotesCpf(string cpfCliente);
static void mostrarClientesPacote(int idPacote);
// Classes
class Dependente{
  private:
    string nome;
  public:
    Dependente(string _nome){
      this->nome = _nome;
    }
    Dependente(){}
    string getNome(){
      return this->nome;
    }
    void setNome(string _nome){
      this->nome = _nome;
    }
};
class Cliente{
  protected:
    string cpf;
    string nome;
    vector<Dependente> dependentes;
  public:
    Cliente(string _cpf, string _nome){
      this->cpf = _cpf;
      this->nome = _nome;
    }
    Cliente(){}
    string getCpf(){
      return this->cpf;
    }
    string getNome(){
      return this->nome;
    }
    vector<Dependente> getDependentes(){
      return dependentes;
    }
    void setCpf(string _cpf){
      this->cpf = _cpf;
    }
    void setNome(string _nome){
      this->nome = _nome;
    }
    void adicionarDependente(string _nome){
      Dependente d(_nome);
      this->dependentes.push_back(d);
    }
    void criarCliente(){
      string cpf, nome;
      int op = 0;
      system("clear");
      cout << "Digite o CPF: ";
      cin >> cpf;
      cout << "Digite o nome: ";
      cin.ignore();
      getline(cin, nome);

      setNome(nome);
      setCpf(cpf);

      cout << "Deseja adicionar dependentes? (1-sim/0-não)" << endl << "> ";
      cin >> op;
      if(op == 1){
        int op2 = 0;
        do{
          system("clear");
          string nome;
          cout << "Digite o nome: ";
          cin.ignore();
          getline(cin, nome);
          this->adicionarDependente(nome);
          cout << "Deseja adicionar mais dependentes? (1-sim/0-não)" << endl << "> ";
          cin >> op2;
        }while(op2 != 0);
      }
    }
};
class Evento{
  protected:
    int id;
    int horaDuracao;
    string nome;
    string rotulo;
  public:
    Evento(int _id, int _horaDuracao, string _nome){
      this->id = _id;
      this->horaDuracao = _horaDuracao;
      this->nome = _nome;
    }
    Evento(){}
    string getRotulo(){
      return this->rotulo;
    }
    void setRotulo(string _rotulo){
      this->rotulo = _rotulo;
    }
    string getNome(){
      return this->nome;
    }
    void setNome(string _nome){
      this->nome = _nome;
    }
    int getId(){
      return this->id;
    }
    int getHoraDuracao(){
      return this->horaDuracao;
    }
    void setId(int _id){
      this->id = _id;
    }
    void setHoraDuracao(int _horaDuracao){
      this->horaDuracao = _horaDuracao;
    }
};
class Roteiro : public Evento{
  public:
    Roteiro(){}
    static void inserirRoteiro(){
      string nome, rotulo;
      int duracao;
      cout << "OBS: Nome vazio e duração 0 para cancelar." << endl;
      cout << "Digite o nome do roteiro: ";
      cin.ignore();
      getline(cin, nome);
      cout << "Digite a duração: ";
      cin >> duracao;
      if(nome != "" && duracao != 0) salvarEvento("R", nome, duracao);
    }
};
class Deslocamento : public Evento{
  public:
    Deslocamento(){}
    static void inserirDeslocamento(){
      string nome, nomeP, nomeD, rotulo;
      int duracao;
      cout << "OBS: Pontos vazios e duração 0 para cancelar." << endl;
      cout << "Digite o ponto de partida: ";
      cin.ignore();
      getline(cin, nomeP);
      cout << "Digite o ponto de destino: ";
      getline(cin, nomeD);
      cout << "Digite a duração: ";
      cin >> duracao;
      if(nomeP != "" && nomeD != "" && duracao != 0){
        nome.append(nomeP);
        nome.append("-");
        nome.append(nomeD);
        salvarEvento("D", nome, duracao);
      }
    }
};
class Pernoite : public Evento{
  public:
    Pernoite(){}
    static void inserirPernoite(){
      string rotulo;
      int duracao;
      cout << "Duração 0 para cancelar." << endl;
      cout << "Digite a duração: ";
      cin >> duracao;
      if(duracao != 0) salvarEvento("P", "Pernoite", duracao);
    }
};
class Pacote{
  private:
    int id;
    string nome;
    int quantidadeEventos;
    vector<string> idEventos;
  public:
    Pacote(int _id, string _nome, int _quantidadeEventos){
      this->id = _id;
      this->nome = _nome;
      this->quantidadeEventos = _quantidadeEventos;
    }
    Pacote(){
      this->quantidadeEventos = 0;
    }
    int getId(){
      return this->id;
    }
    string getNome(){
      return this->nome;
    }
    void setId(int _id){
      this->id = _id;
    }
    void setNome(string _nome){
      this->nome = _nome;
    }
    int getQuantidadeEventos(){
      return this->quantidadeEventos;
    }
    void setQuantidadeEventos(int _quantidadeEventos){
      this->quantidadeEventos = _quantidadeEventos;
    }
    vector<string> getEventos(){
      return idEventos;
    }
    bool pacoteVazio(){
      return this->idEventos.size() == 0;
    }
    static void menuEvento(){
      int op = 0;
      do{
        system("clear");
        cout << " == INSERIR EVENTOS ==" << endl;
        cout << "1 - Roteiro" << endl;
        cout << "2 - Deslocamento" << endl;
        cout << "3 - Pernoite" << endl;
        cout << "0 - Voltar" << endl << "> ";
        cin >> op;
        switch(op){
          case 1:
            Roteiro::inserirRoteiro();
            break;
          case 2:
            Deslocamento::inserirDeslocamento();
            break;
          case 3:
            Pernoite::inserirPernoite();
            break;
          case 0:
            break;
          default:
            break;
        }
        if(op > 3 || op < 0) {
          cout << "Opcao invalida!" << endl;
          system(PAUSE);
        }
      }while(op != 0);
    }
    void adicionaEvento(string id){
      this->idEventos.push_back(id);
    }
    void criarPacote(){
      int op;
      vector<Evento> dadosEventos = listaDeEventos();
      cout << "Digite o nome do pacote: ";
      cin.ignore();
      getline(cin, this->nome);
      do{
        op = 0;
        system("clear");
        cout << "Escolha os eventos 1 por 1" << endl;
        for(Evento e : dadosEventos){
          cout << "(" << e.getId() << ") " << e.getRotulo() << " - " << e.getNome() << " [" << e.getHoraDuracao() << "h]" << endl;
        }
        cout << endl << "Digite o ID: ";
        cin >> op;
        if(op > eventosContadorID || op < 1) {
          cout << "Opcao invalida!" << endl;
          system(PAUSE);
        } else {
          adicionaEvento(to_string(dadosEventos[op-1].getId()));
          quantidadeEventos++;
        }
        cout << "Adicionar mais eventos (1=sim / 0=não): ";
        cin >> op;
      }while(op != 0);
    }
};
class PacoteCliente{
  public:
    PacoteCliente(){}
    void venderPacote(){
      string cpf;
      int op = 0;
      vector<Pacote> pacotes = listaDePacotes();
      if(pacotes.size() > 0){
        cout << "Digite o CPF do cliente: ";
        cin >> cpf;
        do{
          int idPacote = 0;
          system("clear");
          cout << "Escolha os pacotes abaixo:" << endl;
          for(Pacote p : pacotes){
            cout << "[" << p.getId() << "] " << p.getNome() << " com " << p.getQuantidadeEventos() << " eventos" << endl;
          }
          cout << endl << "Opção: ";
          cin >> idPacote;
          salvarVenda(cpf, idPacote);
          cout << "Vender mais pacotes (1=sim / 0=não): ";
          cin >> op;
        }while(op != 0);
      } else {
        cout << "Não existem pacotes cadastrados!" << endl;
        system(PAUSE);
      }
    }
};

// Inicio
int main(){
  int op = 0;
  eventosContadorId();
  pacotesContadorId();
  do{
    system("clear");
    cout << "TURISMO" << endl;
    cout << "1 - Cadastrar Eventos" << endl;
    cout << "2 - Criar Pacotes" << endl;
    cout << "3 - Cadastrar Clientes" << endl;
    cout << "4 - Vender Pacotes" << endl;
    cout << "5 - Lista de Clientes" << endl;
    cout << "6 - Lista de Pacotes" << endl;
    cout << "7 - Consultar pacotes por cliente" << endl;
    cout << "8 - Consultar clientes por pacote" << endl;
    cout << "0 - Sair" << endl << "> ";
    cin >> op;
    switch(op){
      case 1:{
        Pacote::menuEvento();
        break;
      }
      case 2:{
        Pacote novoPacote;
        novoPacote.criarPacote();
        if(!novoPacote.pacoteVazio()) salvarPacote(novoPacote);
        break;
      }
      case 3:{
        Cliente novoCliente;
        novoCliente.criarCliente();
        salvarCliente(novoCliente);
        break;
      }
      case 4:{
        PacoteCliente novaVenda;
        novaVenda.venderPacote();
        break;
      }
      case 5:{
        listarClientes();
        system(PAUSE);
        break;
      }
      case 6:{
        vector<Pacote> pacotes = listaDePacotes();
        size_t op = 0;
        system("clear");
        cout << "Pacotes" << endl;
        for(Pacote p : pacotes){
          cout << "[" << p.getId() << "] " << p.getNome() << " com " << p.getQuantidadeEventos() << " eventos" << endl;
        }
        cout << endl << "Digite o ID do pacote para ver mais detalhes ou 0 para voltar: ";
        cin >> op;
        if(op <= pacotes.size() && op > 0){
          Pacote* pacote = &pacotes[op - 1];
          system("clear");
          cout << "Eventos do pacote " << pacote->getNome() << endl;
          for(string s : pacote->getEventos()){
            Evento e = eventoEncontrado(s);
            cout << "- " << e.getNome() << " [" << e.getHoraDuracao() << "h]" << endl;
          }
        }
        system(PAUSE);
        break;
      }
      case 7:{
        string cpfCliente;
        system("clear");
        cout << "Digite o CPF do cliete: ";
        cin >> cpfCliente;
        mostrarPacotesCpf(cpfCliente);
        system(PAUSE);
        break;
      }
      case 8:{
        vector<Pacote> pacotes = listaDePacotes();
        int op = 0;
        system("clear");
        cout << "Escolha o [ID] de um pacote abaixo:" << endl;
        for(Pacote p : pacotes){
          cout << "[" << p.getId() << "] " << p.getNome() << " com " << p.getQuantidadeEventos() << " eventos" << endl;
        }
        cout << "> ";
        cin >> op;
        mostrarClientesPacote(op);
        system(PAUSE);
        break;
      }
      case 0:
        break;
    }
    if(op > 8 || op < 0){
      cout << "Opção Inválida" << endl;
      system(PAUSE);
      system("clear");
    }
  }while(op != 0);
  return 0;
}

// Funções
static void salvarEvento(string rotulo, string nome, int duracao){
  ofstream arquivo;
  arquivo.open("eventos.txt", ios_base::app);
  if(arquivo.is_open()){
      eventosContadorID++;
      arquivo << eventosContadorID << "|";
      arquivo << rotulo << "|";
      arquivo << nome << "|";
      arquivo << duracao << endl;
      arquivo.close();
      cout << "Evento cadastrado com sucesso!" << endl;
  } else {
      cout << "Erro ao abrir arquivo!" << endl;
  }
}
static void salvarPacote(Pacote novo){
  ofstream arquivo;
  arquivo.open("pacotes.txt", ios_base::app);
  if(arquivo.is_open()){
    pacotesContadorID++;
    arquivo << pacotesContadorID << "|";
    arquivo << novo.getNome() << "|";
    arquivo << novo.getQuantidadeEventos() << "|";
    for(string e : novo.getEventos()){
      arquivo << e << "|";
    }
    arquivo << endl;
    arquivo.close();
    cout << "Pacote cadastrado com sucesso!" << endl;
  }
}
static void salvarCliente(Cliente novo){
  ofstream arquivo;
  arquivo.open("clientes.txt", ios_base::app);
  if(arquivo.is_open()){
      arquivo << novo.getCpf() << "|";
      arquivo << novo.getNome() << "|";
      for(Dependente e : novo.getDependentes()){
        arquivo << e.getNome() << "|";
      }
      arquivo << endl;
      arquivo.close();
      cout << "Cliente cadastrado com sucesso!" << endl;
  } else {
      cout << "Erro ao abrir arquivo!" << endl;
  }
}
static void salvarVenda(string cpf, int idPacote){
  ofstream arquivo;
  arquivo.open("vendas.txt", ios_base::app);
  if(arquivo.is_open()){
      arquivo << cpf << "|";
      arquivo << idPacote << endl;
      arquivo.close();
      cout << "Venda feita com sucesso!" << endl;
  } else {
      cout << "Erro ao abrir arquivo!" << endl;
  }
}
static void eventosContadorId(){
  ifstream arquivo;
  arquivo.open("eventos.txt", ios_base::in);
  if(arquivo.is_open()){
    string id, rotulo, nome, duracao;
    while(arquivo.eof() == false){
      getline(arquivo, id, '|');
      getline(arquivo, rotulo, '|');
      getline(arquivo, nome, '|');
      getline(arquivo, duracao);
      if(id != "\n" && id != "") eventosContadorID = stoi(id);
    }
    arquivo.close();
  } else {
    cout << "Erro ao abrir arquivo!" << endl;
  }
}
static void pacotesContadorId(){
  ifstream arquivo;
  arquivo.open("pacotes.txt", ios_base::in);
  if(arquivo.is_open()){
    string linha;
    while (getline(arquivo, linha)) {
        istringstream stream(linha);
        string primeiroItem;
        if(getline(stream, primeiroItem, '|')) {
          pacotesContadorID = stoi(primeiroItem);
        }
    }
  } else {
    cout << "Erro ao abrir arquivo!" << endl;
  }
}
static vector<Evento> listaDeEventos(){
  vector<Evento> eventos;
  ifstream arquivo;
  arquivo.open("eventos.txt", ios_base::in);
  if(arquivo.is_open()){
    while (arquivo.eof()==false){
      Evento* evento = new Evento();
      string dadosEvento;
      getline(arquivo, dadosEvento);
      vector<string> dadosSeparado{};
      string delimiter = "|";
      size_t pos;
      while ((pos = dadosEvento.find(delimiter)) != string::npos) {
          dadosSeparado.push_back(dadosEvento.substr(0, pos));
          dadosEvento.erase(0, pos + delimiter.length());
      }
      if(dadosEvento != "\n" && dadosEvento != ""){
        dadosSeparado.push_back(dadosEvento);
        evento->setId(stoi(dadosSeparado[0]));
        evento->setRotulo(dadosSeparado[1]);
        evento->setNome(dadosSeparado[2]);
        evento->setHoraDuracao(stoi(dadosSeparado[3]));
        eventos.push_back(*evento);
      }
    }
    arquivo.close();
  }
  return eventos;
}
static vector<Pacote> listaDePacotes(){
  vector<Pacote> pacotes;
  ifstream arquivo("pacotes.txt");

  if (arquivo.is_open()) {
    string linha;
    while (getline(arquivo, linha)) {
      vector<string> dadosSeparados{};
      string token;
      stringstream stream(linha);
    
      while (getline(stream, token, '|')) {
        dadosSeparados.push_back(token);
      }
      if (dadosSeparados.size() >= 3) {
        int id = stoi(dadosSeparados[0]);
        string nome = dadosSeparados[1];
        int quantidadeEventos = stoi(dadosSeparados[2]);
        Pacote pacote(id, nome, quantidadeEventos);
        for(size_t i = 3; i < dadosSeparados.size(); i++) {
            pacote.adicionaEvento(dadosSeparados[i]);
        }
        pacotes.push_back(pacote);
      }
    }
    arquivo.close();
  }
  return pacotes;
}
static vector<Cliente> listaDeClientes(){
  vector<Cliente> clientes;
  ifstream arquivo("clientes.txt");

  if(arquivo.is_open()){
    string linha;
    while(getline(arquivo, linha)){
      vector<string> dadosSeparados{};
      string token;
      stringstream stream(linha);
      while(getline(arquivo, token, '|')){
        dadosSeparados.push_back(token);
      }
      if(dadosSeparados.size() >= 2){
        string cpf = dadosSeparados[0];
        string nome = dadosSeparados[1];
        Cliente cliente(cpf, nome);
        for(size_t i = 2; i < dadosSeparados.size(); i++){
          cliente.adicionarDependente(dadosSeparados[i]);
        }
        clientes.push_back(cliente);
      }
    }
    arquivo.close();
  }
  return clientes;
}
static void listarClientes(){
  ifstream arquivo("clientes.txt");
  if (!arquivo.is_open()) {
    cerr << "Erro ao abrir o arquivo." << endl;
    return;
  }
  string linha;
  system("clear");
  cout << "Lista de Clientes" << endl;
  while (getline(arquivo, linha)) {
    istringstream stream(linha);
    vector<string> tokens;
    string token;
    while (getline(stream, token, '|')) {
        tokens.push_back(token);
    }
    int contador = 0;
    for(string& dado : tokens) {
      if(tokens.size() > 2){
        if(contador == 0) cout << "[" << dado << "] ";
        else if(contador == 1) cout << dado << endl << "Dependentes:";
        else if(contador == 2) cout << "\t" << dado << endl;
        else cout << "\t\t" << dado << endl;
      } else {
        if(contador == 0) cout << "[" << dado << "] ";
        else if(contador == 1) cout << dado << endl;
      }
      contador++;
    }
    cout << endl;
  }
  arquivo.close();
}
static Evento eventoEncontrado(string idEvento){
  vector<Evento> eventos = listaDeEventos();
  for(Evento e : eventos){
    if(e.getId() == stoi(idEvento)){
      return e;
    }
  }
  return Evento();
}
static Pacote pacoteEncontrado(string idPacote){
    vector<Pacote> pacotes = listaDePacotes();
    for(Pacote p : pacotes){
      if(p.getId() == stoi(idPacote)){
        return p;
      }
    }
    return Pacote();
}
static Cliente clienteEncontrado(string cpfCliente){
  vector<Cliente> clientes = listaDeClientes();
  for(size_t i=0; i<clientes.size(); i++){
   if(clientes[i].getCpf() == cpfCliente){
    return clientes[i];
   }
  }
  return Cliente();
}
static void mostrarPacotesCpf(string cpfCliente){
    vector<string> idPacotesCliente;

    ifstream arquivo("vendas.txt");
    if (!arquivo.is_open()) cerr << "Erro ao abrir o arquivo." << endl;
    string linha;
    while (getline(arquivo, linha)) {
        size_t pos = linha.find("|");
        if (pos != string::npos) {
            string cpfLido = linha.substr(0, pos);
            string nomeLido = linha.substr(pos + 1);
            if (cpfLido == cpfCliente) {
                idPacotesCliente.push_back(nomeLido);
            }
        }
    }
    arquivo.close();
    system("clear");
    cout << "Pacotes do Cliente:" << endl;
    for(string s : idPacotesCliente){
      Pacote p = pacoteEncontrado(s);
      cout << p.getNome() << " com " << p.getQuantidadeEventos() << " eventos." << endl;
    }
    cout << endl;
}
static void mostrarClientesPacote(int idPacote){
  vector<string> cpfClientes;

  ifstream arquivo("vendas.txt");
  if(!arquivo.is_open()) cerr << "Erro ao abrir o arquivo." << endl;
  string linha;
  while (getline(arquivo, linha)) {
    size_t pos = linha.find("|");
    if (pos != string::npos) {
        string cpfLido = linha.substr(0, pos);
        string nomeLido = linha.substr(pos + 1);
        if (to_string(idPacote) == nomeLido) {
          cpfClientes.push_back(cpfLido);
        }
    }
  }
  arquivo.close();
  system("clear");
  cout << "Clientes com o pacote:" << endl;
  if(cpfClientes.size() > 0){
    for(string s : cpfClientes){
      Cliente c = clienteEncontrado(s);
      cout << c.getNome() << endl;
    }
  } else cout << "Nenhum cliente adiquiriu esse pacote." << endl;
  cout << endl;
}