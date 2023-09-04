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

    return 0;
}