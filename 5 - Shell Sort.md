Sequências e Eficiência:

A escolha da sequência de intervalos no Shell Sort afeta diretamente o desempenho do algoritmo:

Sequência de Shell (original):

A sequência original, que reduz o intervalo pela metade, é a mais simples, mas também a menos eficiente, especialmente em listas grandes. 
Essa sequência não explora de forma ideal o espaço de busca, causando mais comparações e trocas do que necessário.
A complexidade de tempo costuma variar entre O(n^2) e O(n^(3/2)).

Sequência de Knuth:

A sequência de Knuth é mais eficiente que a de Shell porque ela usa intervalos maiores inicialmente, o que reduz o número de trocas nos estágios iniciais. 
Isso leva a uma ordenação parcial mais eficiente, permitindo que a fase final de ordenação com intervalo 1 seja mais rápida.
A complexidade de tempo esperada é cerca de O(n^(3/2)).

Sequência de Hibbard:

A sequência de Hibbard é baseada em potências de dois e tem um desempenho muito bom em prática. Ela tende a ser mais eficiente que a sequência de Shell e, em muitos casos, tão eficiente quanto a de Knuth.
Sua complexidade de tempo é em torno de O(n^(3/2)). 
