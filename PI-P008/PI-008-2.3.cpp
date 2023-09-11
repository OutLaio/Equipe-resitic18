#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Inicializa o gerador de números aleatórios
    srand(time(NULL));

    // Número de alunos na turma
    int numAlunos = 15;

    // Declara dois arrays para armazenar as notas dos alunos, um para cada avaliação
    float notasAvaliacao1[numAlunos];
    float notasAvaliacao2[numAlunos];
    float medias [numAlunos];

    // Preenche os arrays com notas aleatórias entre 0 e 10 para a primeira e segunda avaliações
    for (int i = 0; i < numAlunos; i++) {
        notasAvaliacao1[i] = ((float)rand() / RAND_MAX) * 10;
        notasAvaliacao2[i] = ((float)rand() / RAND_MAX) * 10;
    }

    // Imprime as notas dos alunos para a primeira avaliação
    printf("Notas da primeira avaliação:\n");
    for (int i = 0; i < numAlunos; i++) {
        printf("Aluno %d: %.2f\n", i + 1, notasAvaliacao1[i]);
    }

    // Imprime as notas dos alunos para a segunda avaliação e compara com a primeira avaliação
    printf("\nNotas da segunda avaliação:\n");
    for (int i = 0; i < numAlunos; i++) {
        printf("Aluno %d: %.2f\n", i + 1, notasAvaliacao2[i]);

        // Comparação das notas e impressão das mensagens
        if (notasAvaliacao2[i] > notasAvaliacao1[i]) {
            printf("Melhorou\n");
        } else if (notasAvaliacao2[i] < notasAvaliacao1[i]) {
            printf("Piorou\n");
        } else {
            printf("Manteve a nota\n");
        }
    }
     // Calcula as médias das notas dos alunos e as armazena no terceiro array
    for (int i = 0; i < numAlunos; i++) {
        medias[i] = (notasAvaliacao1[i] + notasAvaliacao2[i]) / 2.0;
    }

    // Imprime as médias das notas dos alunos
    printf("Médias das notas dos alunos:\n");
    for (int i = 0; i < numAlunos; i++) {
        printf("Aluno %d: %.2f\n", i + 1, medias[i]);
    }
    return 0;
}
