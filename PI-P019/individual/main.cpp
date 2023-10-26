#include <iostream>
#include <vector>
using namespace std;

class ItemSet{
    private:
        vector<string> items;
    public:
        void inserir(string s){
            bool existe = false;
            for(size_t i=0; i<this->items.size(); i++){
                if(this->items[i] == s){
                    existe = true;
                }
            }
            if(existe){
                cout << "Já existe!" << endl;
            } else this->items.push_back(s);
        }
        void excluir(string s){
            for(size_t i=0; i<this->items.size(); i++){
                if(this->items[i] == s){
                    this->items[i].erase(this->items[i].begin() + i);
                }
            }
        }
};

int main(){

    ItemSet itemsTeste;

    itemsTeste.inserir("mundo");
    itemsTeste.inserir("golias");
    itemsTeste.inserir("mundo");
    itemsTeste.excluir("golias");
    return 0;
}
