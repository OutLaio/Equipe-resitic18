#include <iostream>
#include <set>

class Conjunto {
private:
    std::set<int> elementos;

public:
    // Construtor que aceita outro conjunto como parâmetro
    Conjunto(const std::set<int>& outrosElementos) : elementos(outrosElementos) {}
    Conjunto resultado();

    // Sobrecarga do operador de atribuição (=)
    Conjunto& operator=(const Conjunto& outro) {
        if (this != &outro) {
            this->elementos = outro.elementos;
        }
        return *this;
    }

    // Sobrecarga do operador de união (+)
    Conjunto operator+(const Conjunto& outro) const {
        Conjunto resultado(this->elementos);
        for (int elemento : outro.elementos) {
            resultado.elementos.insert(elemento);
        }
        return resultado;
    }

    // Sobrecarga do operador de intersecção (*)
    Conjunto operator*(const Conjunto& outro) const {
        Conjunto resultado();
        for (int elemento : this->elementos) {
            if (outro.elementos.count(elemento) > 0) {
                resultado.elementos.insert(elemento);
            }
        }
        return resultado;
    }

    // Sobrecarga do operador de diferença (-)
    Conjunto operator-(const Conjunto& outro) const {
        Conjunto resultado(this->elementos);
        for (int elemento : outro.elementos) {
            resultado.elementos.erase(elemento);
        }
        return resultado;
    }

    // Sobrecarga do operador de delta (<>)
    Conjunto operator<>(const Conjunto& outro) const {
        Conjunto resultado;

        for (int elemento : this->elementos) {
            if (outro.elementos.count(elemento) == 0) {
                resultado.elementos.insert(elemento);
            }
        }

        for (int elemento : outro.elementos) {
            if (this->elementos.count(elemento) == 0) {
                resultado.elementos.insert(elemento);
            }
        }

        return resultado;
    }

    // Sobrecarga do operador de igualdade (==)
    bool operator==(const Conjunto& outro) const {
        return this->elementos == outro.elementos;
    }

    // Função para adicionar elementos ao conjunto
    void adicionar(int elemento) {
        elementos.insert(elemento);
    }

    // Função para imprimir o conjunto
    void imprimir() const {
        for (int elemento : elementos) {
            std::cout << elemento << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    std::set<int> elementosA = {1, 2, 3};
    std::set<int> elementosB = {3, 4, 5};
    std::set<int> elementosC = {5, 6, 7};

    Conjunto A(elementosA);
    Conjunto B(elementosB);
    Conjunto C(elementosC);

    // Atribuição
    Conjunto D = B;

    // União
    Conjunto E = B + C;

    // Intersecção
    Conjunto F = B * C;

    // Diferença
    Conjunto G = B - C;

    // Delta
    Conjunto H = B <> C;

    // Igualdade
    bool igual = A == B;

    A.imprimir();
    B.imprimir();
    C.imprimir();
    D.imprimir();
    E.imprimir();
    F.imprimir();
    G.imprimir();
    H.imprimir();

    std::cout << "A == B: " << igual << std::endl;

    return 0;
}
