Distribuição nos baldes:

O array buckets armazena os baldes (arrays temporários). A função bucketSort distribui os números entre os baldes com base na multiplicação do número pelo número total de baldes.
Para números no intervalo (0, 1), o índice do balde é obtido multiplicando o número pelo número total de baldes. Por exemplo, para 0.78, se houver 10 baldes, ele vai para o balde 7.

Adaptação do Bucket Sort para Números Inteiros Positivos em Intervalos Maiores

Para adaptar o Bucket Sort a números inteiros positivos em intervalos maiores, é necessário ajustar o cálculo do índice do balde. 
Em vez de números entre 0 e 1, agora trabalhamos com números inteiros positivos que podem variar em uma faixa maior. 
O número de baldes pode ser baseado em uma estimativa do intervalo dos números na lista.
