Analisando o Desempenho do Quick Sort

O desempenho do Quick Sort depende do tipo de entrada (lista quase ordenada ou completamente desordenada) e da escolha do pivô.

Lista quase ordenada:

Se o array já está quase ordenado, o Quick Sort pode ter um desempenho ruim, especialmente se o pivô for escolhido de maneira ineficiente. 
Isso ocorre porque o algoritmo pode dividir o array de forma desigual, resultando em recursões profundas e tempo de execução O(n²) no pior caso.

Lista completamente desordenada:

Em listas desordenadas, o Quick Sort geralmente tem desempenho O(n log n), o que o torna eficiente para grandes volumes de dados, se a escolha do pivô for boa.
