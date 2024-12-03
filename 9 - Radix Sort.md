Base 10:

No exemplo acima, o Radix Sort é implementado usando a base 10. Ou seja, ele processa cada número dígito por dígito (0 a 9). 
A base 10 é comum, pois reflete o sistema de numeração decimal.

Base 2:

O Radix Sort também pode ser adaptado para funcionar na base 2 (binária). Neste caso, ele processaria bit por bit (em vez de dígito por dígito). 
Isso significa que o Counting Sort seria aplicado aos bits, e cada número seria tratado em termos de 0s e 1s.
Para modificar o algoritmo para base 2, o expoente (exp) seria 1, 2, 4, 8, etc. (ou seja, potências de 2). Cada passo do Counting Sort lidaria com um bit de cada número. 
