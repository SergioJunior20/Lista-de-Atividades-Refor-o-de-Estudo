Casos para Listas Grandes:

Em listas grandes, o Exponential Search é eficiente quando o valor a ser buscado está próximo do início da lista. 
A fase exponencial encontra rapidamente um pequeno intervalo onde o valor pode estar, e a Binary Search é usada para localizar o valor com precisão.
A complexidade de tempo no pior caso é O(log n), semelhante à Binary Search, porque a fase exponencial rapidamente reduz a área de busca a um tamanho logarítmico.

Casos para Listas Pequenas:

Em listas pequenas, o Exponential Search tende a ser muito rápido, pois a fase exponencial encontra o valor ou um pequeno intervalo rapidamente, fazendo com que a Binary Search seja aplicada em uma parte muito reduzida da lista.
Para listas menores, o tempo gasto no Exponential Search pode ser comparável ao da Binary Search. 
