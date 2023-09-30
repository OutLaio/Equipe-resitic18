#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class ItemSet {
private:
    std::vector<std::string> items;

public:
    void inserir(std::string s) {
        // Verifica se o item já está no conjunto
        if (std::find(items.begin(), items.end(), s) == items.end()) {
            items.push_back(s); // Insere o item no conjunto
            std::cout << "Item \"" << s << "\" inserido com sucesso." << std::endl;
        } else {
            std::cout << "Item \"" << s << "\" ja existe no conjunto." << std::endl;
        }
    }

    void excluir(std::string s) {
        // Encontra o item no conjunto
        auto it = std::find(items.begin(), items.end(), s);

        // Verifica se o item existe e o remove
        if (it != items.end()) {
            items.erase(it);
            std::cout << "Item \"" << s << "\" excluido com sucesso." << std::endl;
        } else {
            std::cout << "Item \"" << s << "\" nao encontrado no conjunto." << std::endl;
        }
    }

    void imprimirItens() {
        std::cout << "Itens no conjunto:";
        for (const std::string& item : items) {
            std::cout << " " << item;
        }
        std::cout << std::endl;
    }
};

int main() {
    ItemSet conjunto;

    conjunto.inserir("Item1");
    conjunto.inserir("Item2");
    conjunto.inserir("Item3");
    conjunto.inserir("Item2"); // Este não será inserido novamente

    conjunto.imprimirItens();

    conjunto.excluir("Item2");
    conjunto.excluir("Item4"); // Este não será excluído

    conjunto.imprimirItens();

    return 0;
}
