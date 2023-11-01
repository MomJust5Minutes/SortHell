# SortHell
Projeto para teste de runtime para os mais diversos sorts

Sorts decrescentes para vetores crescentes ou aleatórios

Os vetores deverão ser ordenados na ordem DECRESCENTE. O Time deverá trabalhar com as alterações necessárias
nos algoritmos apresentados em sala de aula.
Para cada método serão consideradas estruturas de 5 tamanhos diferentes (no mínimo, se o Time desejar pode inserir
mais alguns tamanhos diferentes).
Métodos a serem implementados:
- InsertionSort
-  BubleSort
-  ShellSort
-  MergeSort
-  QuickSort
-  Um método diferente a ser pesquisado, escolhido e apresentado pelo Time
  
A ordenação será realizada num vetor de estruturas, de diferentes tamanhos. A estrutura é constituída de 2 campos:
- Um valor inteiro - será a chave da ordenação
- Um valor real com valor superior a 100
  
Os valores, para preenchimento do vetor, deverão ser gerados de duas diferentes formas:

  1. Aleatoriamente – chave e número real. 
 Como os casos têm que ser os mesmos para todos os métodos será necessário trabalhar com o conceito de sementes para a geração de números aleatórios
  2. Chave em ORDEM CRESCENTE e número real ALEATORIAMENTE
     
O Time irá gerar para cada tamanho n do vetor, 10 casos de valores do tipo 1 e 10 casos de valores do tipo 2. Os métodos de ordenação, definidos acima, serão executados para cada caso e cada tamanho, obtendo o tempo de
execução.
A finalidade é realizar uma análise comparativa entre os métodos.

Tamanhos do Vetor (n):
- 10^4
- 5*10^4
- 10^5
- 5*10^5
- 10^6

Para a obtenção do tempo de execução de cada método, a contagem do tempo deve ser iniciada imediatamente
antes da execução do Método de Ordenação e imediatamente encerrada no término da execução do método

A implementação de alguns métodos necessita de considerações:
1. ShellSort - regra para obtenção de h:
- h(i)=1, para i=1
- h(i)=3h(i-1) +1, para i > 1
  
2. QuickSort
Este método terá um estudo/análise extra com o objevo de avaliar a escolha do pivô. As seguintes
escolhas de pivô deverão ser avaliadas:
- Valor da posição do Limite Inferior do sub-vetor
- Valor da posição do Limite Superior do sub-vetor
- Valor da posição do Limite Meio do sub-vetor

  Obs: Os diferentes tamanhos do vetor a ser considerado são:
  Para cada Tamanho n serão gerados 10 casos, no MÍNIMO
