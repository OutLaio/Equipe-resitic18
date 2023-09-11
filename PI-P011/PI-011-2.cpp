//A coesão refere-se ao grau em que as responsabilidades de uma função estão relacionadas internamente.
// Em outras palavras, a coesão mede o quanto uma função faz um único conjunto bem-definido de tarefas. 
//No caso da função maxmin, podemos identificar que ela tem uma alta coesão, porque realiza uma única tarefa bem definida: encontrar o valor máximo e mínimo em um vetor de números inteiros. Não está misturando responsabilidades diferentes, o que é um sinal de alta coesão.

// Acoplamento

//O acoplamento refere-se à medida em que uma função está interligada com outras partes do código, ou seja, quão dependente uma função é de outras partes do programa. No caso da função maxmin, ela não é altamente acoplada a outras partes do programa. Ela recebe os dados necessários (o vetor e seu tamanho) como parâmetros e retorna os resultados por meio das variáveis maximo e minimo. Não depende de estados globais ou variáveis globais, o que é um sinal de baixo acoplamento. Além disso, não chama outras funções internamente, o que também ajuda a manter o acoplamento baixo.

//Portanto, a função maxmin possui alta coesão e baixo acoplamento, o que é geralmente considerado uma boa prática de programação, pois torna a função mais fácil de entender, reutilizar e mante