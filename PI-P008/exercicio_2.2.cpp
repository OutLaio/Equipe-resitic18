#include<iostream>
#include<math.h>

using namespace std;

int main(){
    int i;
    float notas1[15], notas2[15], media[15];

    cout << "As notas 1 dos alunos são : " << endl;
    for (i = 0; i < 15; i++){
        notas1[i] = (rand()%101)/10.0;
        cout << notas1[i] << " ";
    }
    cout << endl;    

    cout << "As notas 2 dos alunos são : " << endl;
    for (i = 0; i < 15; i++){
        notas2[i] = (rand()%101)/10.0;
        cout << notas2[i] << " ";
    }
    cout << endl;

    for (i = 0; i < 15; i++){
        cout << "O aluno #" << i+1;
        if (notas2[i] > notas1[i]){
            cout << " melhorou ";
        }else if (notas2[i] < notas1[i]){
            cout << " piorou ";
        }else{
            cout << " manteve ";
        }
        cout << "a nota" << endl;
    }
    

    return 0;
}