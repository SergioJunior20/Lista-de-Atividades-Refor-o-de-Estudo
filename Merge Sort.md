Conceito de "Dividir para Conquistar"

O algoritmo Merge Sort exemplifica o paradigma de dividir para conquistar, em que o problema é dividido em partes menores (divisão do array), cada parte é resolvida independentemente (ordenando os subarrays recursivamente) e os resultados são combinados (mescla dos subarrays) para formar a solução final.
Essa abordagem divide o problema grande em problemas menores até que se tornem suficientemente simples de resolver (listas com um único elemento).

Modificando Merge Sort para ordenar strings em ordem alfabética

Para ordenar strings, podemos modificar a função mergeSort para trabalhar com arrays de strings, e a comparação será feita com a função strcmp() da biblioteca string.h, em vez de <=, que é usada para inteiros. 
