#include <iostream>
#include <set>

using namespace std;

class Conjunto {
private:
    set<int> elementos;
public:
    Conjunto(){}
    Conjunto(set<int> &outros) {
        elementos = outros;
    }
    Conjunto &operator=(Conjunto &c) {
        elementos = c.elementos;
        return *this;
    }
    Conjunto operator+(Conjunto &c){
        Conjunto resultado(this->elementos);
        for(int elemento : c.elementos) {
            resultado.elementos.insert(elemento);
        }
        return resultado;
    }
    Conjunto operator*(Conjunto &c){
        Conjunto resultado;
        for(int elemento : elementos) {
            if (c.elementos.count(elemento) > 0) {
                resultado.elementos.insert(elemento);
            }
        }
        return resultado;
    }
    Conjunto operator-(Conjunto &c){
        Conjunto resultado(this->elementos);
        for(int elemento : c.elementos) {
            resultado.elementos.erase(elemento);
        }
        return resultado;
    }
    bool operator==(Conjunto &c){
        return elementos == c.elementos;
    }
    void adicionar(int elemento) {
        elementos.insert(elemento);
    }
    void imprimir(){
        for(int elemento : elementos) {
            cout << elemento << " ";
        }
        cout << endl;
    }
};

int main() {
    set<int> conjunto1 = {1, 2, 3};
    set<int> conjunto2 = {3, 4, 5};

    Conjunto A(conjunto1);
    Conjunto B(conjunto2);

    // Testando as sobrecargas dos operadores
    Conjunto C = A + B;
    Conjunto D = A * B;
    Conjunto E = A - B;

    cout << "C = A + B: ";
    C.imprimir();
    cout << "D = A * B: ";
    D.imprimir();
    cout << "E = A - B: ";
    E.imprimir();

    if(A == B) {
        cout << "A == B: true" << endl;
    }else{
        cout << "A == B: false" << endl;
    }

    return 0;
}
