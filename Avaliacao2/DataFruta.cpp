#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Data {
	int dia, mes, ano;
	public:
	Data (int _dia, int _mes, int _ano) {
		dia = _dia;
		mes = _mes;
		ano = _ano;
	}
	Data(){}
	/*
	O metodo abaixo retornara -1 se d1 eh anterior a d2
	Retornara 0 se d1 = d2
	Retornara +1 se d1 eh posterior a d2
	*/
	static int compara(Data d1, Data d2) {
		if (d1.ano < d2.ano) { // ANO
			return -1;
		} else if (d1.ano > d2.ano) {
			return 1;
		}

		if (d1.mes < d2.mes) { // MES
			return -1;
		} else if (d1.mes > d2.mes) {
			return 1;
		}

		if (d1.dia < d2.dia) { // DIA
			return -1;
		} else if (d1.dia > d2.dia) {
			return 1;
		}

		return 0; // SE FOR IGUAIS
	}
	static void ordenaDatas(vector<Data> *lista){
		bool flag;
		int c = 1;
		do{
			flag = false;
			for(size_t i=0; i<lista->size() - c; i++){
				if(Data::compara((*lista)[i], (*lista)[i+1]) == 1){
					swap((*lista)[i], (*lista)[i+1]);
					flag = true;
				}
			}
			c++;
		} while (flag);
		
	}
	void setDia(int _dia){
		this->dia = _dia;
	}
	void setMes(int _mes){
		this->mes = _mes;
	}
	void setAno(int _ano){
		this->ano = _ano;
	}
	/**
	 * @brief O metodo abaixo retorna a data em formato de string
	*/
	string toString() {
		string ret = "";
		ret.append(to_string(dia));
		ret.append("/");
		ret.append(to_string(mes));
		ret.append("/");
		ret.append(to_string(ano));
		return ret;
	}
};
class Lista {
	public:
	virtual void entradaDeDados() = 0;
	virtual void mostraMediana() = 0;
	virtual void mostraMenor() = 0;
	virtual void mostraMaior() = 0;
  	virtual void listarEmOrdem() = 0;
  	virtual void listarLimite(size_t) = 0;
};
class ListaNomes : public Lista {
	vector<string> lista;
	public:
	/**
	 * @brief O metodo abaixo pergunta ao usuarios quantos elementos vao existir na lista e depois solicita a digitacao de cada um deles.
	*/
	void entradaDeDados() {
		int qntNomes = 0;
		cout << "== NOMES ==" << endl;
		cout << "Quantos nomes deseja inserir?" << endl;
		cout << "> ";
		cin >> qntNomes;
		cin.ignore();
		system("clear||cls");
		for(int i = 0; i < qntNomes; i++){
			string nome;
			cout << i+1 << "º nome: ";
			getline(cin, nome);
			lista.push_back(nome);
		}
		system("clear||cls");
		sort(lista.begin(), lista.end());
	}
	/**
	 * @brief O metodo abaixo exibe a mediana do nomes da lista.
	*/
	void mostraMediana() {
		if(lista.size() > 0){
			cout << "Mediana dos nomes: ";
			if(lista.size() % 2 == 0){
				cout << lista[(lista.size() / 2) - 1] << endl;
			} else {
				cout << lista[(lista.size() / 2)] << endl;
			}
		} else cout << "Nenhum nome inserido" << endl;
	}
	/**
	 * @brief O metodo abaixo exibe o primeiro nome da lista em ordem alfabetica.
	*/
	void mostraMenor() {
		if(lista.size() > 0) cout << "Primeiro nome: " << lista[0] << endl;
		else cout << "Nenhum nome inserido" << endl;
	}
	/**
	 * @brief O metodo abaixo exibe o ultimo nome da lista em ordem alfabetica.
	*/
	void mostraMaior() {
		if(lista.size() > 0) cout << "Último nome: " << lista[lista.size()-1] << endl;
		else cout << "Nenhum nome inserido" << endl;
	}
	/**
	 * @brief O metodo abaixo exibe a lista em ordem alfabetica.
	*/
  void listarEmOrdem(){
		cout << "Lista completa:" << endl;
		for(size_t i=0; i<lista.size(); i++){
		cout << lista[i] << endl;
		}
  }
  /**
  * @brief O metodo abaixo exibe os N primeiros itens da lista em ordem alfabetica.
  */
  void listarLimite(size_t n){
    if(lista.size()==0){
      cout << "A lista de nomes esta vazia!" << endl;
      return;
    }
    if(lista.size() < n)
      n = lista.size();

    for(size_t i=0; i<n; i++){
      cout << lista[i] << endl;
    }
  }
};
class ListaDatas : public Lista {
	vector<Data> lista;
	public:
	/**
	 * @brief O metodo abaixo pergunta ao usuarios quantos elementos vao existir na lista e depois solicita a digitacao de cada um deles
	*/
	void entradaDeDados() {
		int qntDatas = 0;
		cout << "== DATAS ==" << endl;
		cout << "Quantas datas deseja inserir?" << endl;
		cout << "> ";
		cin >> qntDatas;
		cin.ignore();
		system("clear||cls");
		for(int i = 0; i < qntDatas; i++){
			Data novaData;
			int d, m, a;
			cout << i+1 << "º Data: " << endl;
			cout << "Dia: ";
			cin >> d;
			cout << "Mes: ";
			cin >> m;
			cout << "Ano: ";
			cin >> a;
			novaData.setDia(d);
			novaData.setMes(m);
			novaData.setAno(a);
			lista.push_back(novaData);
		}
		Data::ordenaDatas(&lista);
		system("clear||cls");
	}
	/**
	 * @brief O metodo abaixo exibe a mediana da lista de datas
	*/
	void mostraMediana() {
		if(lista.size() > 0){
			cout << "Mediana das datas: ";
			if(lista.size() % 2 == 0){
				cout << lista[(lista.size() / 2) - 1].toString() << endl;
			} else {
				cout << lista[lista.size() / 2].toString() << endl;
			}
		} else cout << "Nenhuma data inserida" << endl;
	}
	/**
	 * @brief O metodo abaixo exibe a menor data da lista
	*/
	void mostraMenor() {
		if(lista.size() > 0) cout << "Primeira data: " << lista[lista.size() - 1].toString() << endl;
		else cout << "Nenhuma data inserida" << endl;
	}
	/**
	 * @brief O metodo abaixo exibe a maior data da lista
	*/
	void mostraMaior() {
		if(lista.size() > 0) cout << "Ultima data: " << lista[0].toString() << endl;
		else cout << "Nenhuma data inserida" << endl;
	}
	/**
	 * @brief O metodo abaixo exibe a lista em ordem cronológica.
	*/
    void listarEmOrdem(){
			cout << "Lista completa:" << endl;
			for(size_t i=0; i<lista.size(); i++){
				cout << lista[i].toString() << endl;
			}
    }
  /**
  * @brief O metodo abaixo exibe os N primeiros itens da lista em ordem cronológica.
  */
  void listarLimite(size_t n){
      if(lista.size()==0){
          cout << "A lista de datas esta vazia!" << endl;
          return;
      }
      if(lista.size() < n)
          n = lista.size();

      for(size_t i=0; i<n; i++){
          cout << lista[i].toString() << endl;
      }
  }
};
class ListaSalarios : public Lista {
	vector<float> lista;
	public:
	/*
	O metodo abaixo pergunta ao usuarios quantos
	elementos vao existir na lista e depois
	solicita a digitacao de cada um deles
	*/	
	void entradaDeDados() {
		int qntSalarios = 0;
		cout << "== SALARIOS ==" << endl;
		cout << "Quantos salarios deseja inserir?" << endl;
		cout << "> ";
		cin >> qntSalarios;
		cin.ignore();
		system("clear||cls");
		for(int i = 0; i < qntSalarios; i++){
			float salario;
			cout << i+1 << "º Salario: ";
			cin >> salario;
			lista.push_back(salario);
		}
		system("clear||cls");
		sort(lista.begin(), lista.end());
	}		
	/**
	 * @brief O metodo abaixo exibe a mediana da lista de salarios
	*/
	void mostraMediana() {
		if(lista.size() > 0){
			cout << "Mediana dos salarios: ";
			if(lista.size() % 2 == 0){
				cout << ((lista[(lista.size() / 2) - 1] + lista[(lista.size() / 2)]) / 2) << endl;
			} else cout << lista[lista.size() / 2] << endl;
		}
	}
	/**
	 * @brief O metodo abaixo exibe o menor salario da lista
	*/
	void mostraMenor() {
		if(lista.size() > 0) cout << "Menor salario: " << lista[lista.size() - 1] << endl;
		else cout << "Nenhum salario inserido" << endl;
	}
	/**
	 * @brief O metodo abaixo exibe o maior salario da lista
	*/
	void mostraMaior() {
		if(lista.size() > 0) cout << "Maior salario: " << lista[0] << endl;
		else cout << "Nenhum salario inserido" << endl;
	}
  /**
  * @brief O metodo abaixo exibe a lista em ordem crescente.
  */
  void listarEmOrdem(){
		cout << "Lista completa:" << endl;
		for(size_t i=0; i<lista.size(); i++){
			cout << lista[i] << endl;
		}
  }
  /**
  * @brief O metodo abaixo exibe os N primeiros itens da lista em ordem crescente.
  */
  void listarLimite(size_t n){
      if(lista.size()==0){
          cout << "A lista de salarios esta vazia!" << endl;
          return;
      }
      if(lista.size() < n)
          n = lista.size();

      for(size_t i=0; i<n; i++){
          cout << lista[i] << endl;
      }
  }
};
class ListaIdades : public Lista {
	vector<int> lista;
	public:
	/**
	 * @brief O metodo abaixo pergunta ao usuarios quantos elementos vao existir na lista e depois solicita a digitacao de cada um deles
	*/
	void entradaDeDados() {
		int qntIdades = 0;
		cout << "== IDADES ==" << endl;
		cout << "Quantas idades deseja inserir?" << endl;
		cout << "> ";
		cin >> qntIdades;
		cin.ignore();
		system("clear||cls");
		for(int i = 0; i < qntIdades; i++){
			int idade;
			cout << i+1 << "º Idade: ";
			cin >> idade;
			lista.push_back(idade);
		}
		system("clear||cls");
		sort(lista.begin(), lista.end());
	}
	/**
	 * @brief O metodo abaixo exibe a mediana da lista de idades.
	*/
	void mostraMediana() {
		if(lista.size() > 0){
			cout << "Mediana das idades: ";
			if(lista.size() % 2 == 0){
				cout << (lista[(lista.size() / 2) - 1] + lista[(lista.size() / 2)]) / 2 << endl;
			} else cout << lista[lista.size() / 2] << endl;
		}
	}
	/**
	 * @brief O metodo abaixo exibe a menor idade da lista
	*/
	void mostraMenor() {
		if(lista.size() > 0) cout << "Menor idade: " << lista[0] << endl;
		else cout << "Nenhuma idade inserida" << endl;
	}
	/**
	 * @brief O metodo abaixo exibe a maior idade da lista
	*/
	void mostraMaior() {
		if(lista.size() > 0) cout << "Maior idade: " << lista[lista.size() - 1] << endl;
		else cout << "Nenhuma idade inserida" << endl;
	}
  /**
  * @brief O metodo abaixo exibe a lista em ordem crescente.
  */
  void listarEmOrdem(){
		cout << "Lista completa:" << endl;
		for(size_t i=0; i<lista.size(); i++){
			cout << lista[i] << endl;
		}
  }
  /**
  * @brief O metodo abaixo exibe os N primeiros itens da lista em ordem crescente.
  */
  void listarLimite(size_t n){
      if(lista.size()==0){
          cout << "A lista de idades esta vazia!" << endl;
          return;
      }
      if(lista.size() < n)
          n = lista.size();

      for(size_t i=0; i<n; i++){
          cout << lista[i] << endl;
      }
  }
};
int main () {
	vector<Lista*> listaDeListas;
	
	ListaNomes listaNomes;
	listaNomes.entradaDeDados();
	listaDeListas.push_back(&listaNomes);
	
	ListaDatas listaDatas;
	listaDatas.entradaDeDados();
	listaDeListas.push_back(&listaDatas);
	
	ListaSalarios listaSalarios;
	listaSalarios.entradaDeDados();
	listaDeListas.push_back(&listaSalarios);
	
	ListaIdades listaIdades;
	listaIdades.entradaDeDados();
	listaDeListas.push_back(&listaIdades);
	
	for (Lista* l : listaDeListas) {
		l->listarEmOrdem();
	}
}