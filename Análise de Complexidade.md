|Algoritmo|	Complexidade de Tempo|	Complexidade de Espaço|	Observações|
|:---------:|:----------------------:|:------------------------:|:------------:|
|Binary Search        | O(logn)      | O(1) | Funciona apenas em arrays ordenados. Divide a busca pela metade a cada iteração. |
|Interpolation Search | O(loglogn) no melhor caso, O(n) no pior caso | O(1) | Útil para dados uniformemente distribuídos, mas pode ser lento em dados não uniformes. |
|Jump Search          | O(√n)​ | O(1)  | Divide o array em blocos, fazendo saltos de tamanho √n​. Após o salto, realiza busca linear no bloco. |                         
|Exponential Search   | O(logn) | O(1) | Rápido para encontrar o intervalo, mas requer que o array esteja ordenado. Utiliza Binary Search no intervalo encontrado.|
|Shell Sort           | O(n3/2) no caso médio, O(n2) no pior caso | O(1) | Usa gaps para comparações, melhorando a eficiência para listas parcialmente ordenadas. |
|Merge Sort           | O(nlogn) em todos os casos | O(n) | Divide e conquista. Efetivamente lida com listas grandes, mas requer espaço adicional para armazenar subarrays. |
|Selection Sort       | O(n2) em todos os casos | O(1) | Simples de implementar, mas ineficiente para listas grandes devido ao grande número de comparações. |
|Quick Sort           | O(nlogn) no melhor/médio caso, O(n2) no pior caso | O(logn) | Divide e conquista. O caso pior pode ser evitado com pivôs escolhidos aleatoriamente ou pelo método de mediana de três. |
|Bucket Sort          | O(n+k) | O(n+k) | Útil para dados uniformemente distribuídos em um intervalo pequeno. Requer k buckets adicionais, onde k é o número de buckets. |
|Radix Sort           | O(nk), onde k é o número de dígitos | O(n+k) | Especializado para inteiros. Rápido para listas com inteiros de tamanho fixo, mas não é comparativo. |
