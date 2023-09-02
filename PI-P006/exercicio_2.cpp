#include<iostream>
#include<math.h>

using namespace std;

int main(){
    int a, b, c;

    cout << endl << "Digite um valor inteiro: ";
    cin >> a;
    cout << "Digite outro valor inteiro: ";
    cin >> b;

    //c = 4*(a + b)/(3 - 5);
    /*  Nesta expressão, primeiro é calculado o que está entre parênteses, 
        logo em seguida, calcula-se '*' e '/', na ordem em que aparecem primeiro,
        por fim, calcula-se '+' e '-'. */

    /*  Na expressão anterior, 4*a + b/3 - 5, não há parênteses, logo os valores da multiplicação
        e divisão serão diferentes. */

    c = 4*(a + b/3) - 5;
    /*  Nesta equação, a ordem dos calculos são diferentes das anteriores, gerando um novo resultado. */

    cout << endl << "O resultado da expressao eh: " << c << endl << endl;

    return 0;
}