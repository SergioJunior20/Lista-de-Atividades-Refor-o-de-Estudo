Estrutura e Comparação

Binary Search: Divide o array em duas partes. A cada iteração, a busca compara o elemento com o meio do array e decide em qual metade a busca continuará.

Ternary Search: Divide o array em três partes. Em vez de uma comparação com o ponto médio, são feitas duas comparações, o que pode reduzir a área de busca mais rapidamente.

Desempenho:

O Ternary Search realiza um número maior de comparações a cada iteração do que o Binary Search, mas cada iteração reduz o intervalo de busca em um fator maior (divisão em três partes, em vez de duas).

Eficiência:

Ternary Search pode ser ligeiramente mais lento em termos de número de comparações por iteração, mas pode ser mais eficiente em termos de redução do intervalo de busca em alguns casos. 
No entanto, para a maioria dos cenários, Binary Search tende a ser mais eficiente em prática devido ao menor número de comparações.

Cenários de Uso:

Ternary Search pode ser mais eficiente em listas muito grandes e quando a redução do intervalo de busca em três partes for vantajosa, mas, geralmente, Binary Search é preferido devido à sua simplicidade e menor número de comparações.
