# Proposta do Trabalho

O objetivo do trabalho é fazer um jogo na qual consiste que um personagem percorra um labirinto construído por diversas matrizes, das quais possui as seguintes regras:
- O jogo termina quando o personagem perde toda a vida (possui um total de 10 de vida).
- Possui paredes durante o caminho que são representadas por ```#```, que são locais onde o personagem não pode caminhar.
- Possui caminhos chamados de perigo, representados por ```*```, que são locais onde o personagem perde uma vida cada vez que passa por ele.

# O Algoritmo

```INPUT```

A proposta do trabalho consiste na leitura de três matrizes que formam o labirinto que será percorrido. A ideia principal é de que o personagem consiga todas as matrizes até que o jogo acabe. 

Além das regras propostas pelo trabalho, foi incrementado outras regras, das quais são elas: (a) existem um portal do lado esquerdo e direito; (b) o loop só vai parar quando o personagem morrer; (c) o jogo vai acabar quando o personagem percorrer todas as matrizes; (c) o personagem só avançará para a próxima matriz quando avançar pelos portais ou quando bater na parede, que será jogado automaticamente para outra matriz.

A função leitura é responsável pela leitura do arquivo de entrada e pela criação do arquivo de saída. O arquivo de entrada é aberto em modo leitura e o de saída em modo escrita. Após isso, o programa lê cada linha do arquivo de entrada e, a partir da segunda linha, realiza a separação de cada palavra (número) da linha utilizando um separador```" "```. O código converte a palavra lida para um número inteiro e armazena na matriz de entrada. Caso a palavra lida seja igual a ```*``` ou ```#```, o código identifica que se trata de um parede ou perigo, respectivamente. Ao fim da leitura de cada linha, caso a matriz tenha sido totalmente lida, o código chama a função checkpoint para salvar o estado atual da matriz no arquivo de checkpoint e a função fazCopia para salvar uma cópia do arquivo de checkpoint.

Em resumo, o código lê um arquivo de entrada contendo uma matriz e salva o estado atual da matriz em um arquivo de checkpoint. A partir do arquivo de checkpoint, o programa cria uma cópia da matriz para salvar o caminho percorrido pelo usuário, caso exista.

```Exemplo de INPUT```

<center>
<table>
   <tr>
      <td>Input</td>
      <td>Checkpoint</td>
   </tr>
   <tr>
      <td><img src="images/input.png"/></td>
      <td><img src="images/checkpoint.png"/></td>
   </tr>
</table>
</center> 

O personagem ```(@)``` é representado pelas variáveis ```x_atual``` e ```y_atual```, que representam a posição atual do personagem na matriz do jogo. O movimento do personagem é feito aleatoriamente em uma das oito direções possíveis, representadas pela variável posicao, que é gerada pela função ```rand()```.

A função ```Movimentar()``` é responsável por fazer o movimento do personagem de acordo com a direção gerada pela função ```rand()```. Ela recebe como parâmetros as coordenadas atuais do personagem ```(x e y)```, a direção gerada pela função ```rand() (posicao)```, as dimensões da matriz do jogo (linha e coluna) e um ponteiro para a variável teleporte. A função verifica a direção gerada e faz o movimento do personagem de acordo com a direção escolhida. Se o movimento tentar levar o personagem para fora da matriz, o ponteiro teleporte é setado para um valor diferente de zero, indicando que o personagem deve ser teleportado para a outra extremidade da matriz.

Dentro do loop infinito que faz o movimento do personagem e atualiza as informações do jogo enquanto o personagem estiver vivo, a função gera uma nova direção aleatória para o movimento do personagem. As coordenadas atuais do personagem são armazenadas nas variáveis ```x_aux``` e ```y_aux``` para que seja possível verificar se houve uma mudança de posição. Se o movimento não levar o personagem para fora da matriz e não levar o personagem para uma posição com um parede ```(-1)``` ou um perigo ```(-2)```, as informações do jogo são atualizadas. Se a posição atual do personagem contiver um item ```(> 0)```, o item é coletado e a sacola do personagem é incrementada. Se a sacola do personagem chegar a quatro itens, a vida do personagem é incrementada se ela for menor do que dez e a sacola é esvaziada.

Se o movimento do personagem levar para uma posição com um perigo ```(-2)```, a vida do personagem é decrementada, a sacola é esvaziada e a variável perigo é incrementada. Se a vida do personagem chegar a zero, a variável status é setada para zero, indicando que o personagem morreu e a função retorna.

Se o movimento do personagem levar para uma posição com um parede ```(-1)```, as coordenadas do personagem são revertidas para as coordenadas originais armazenadas em ```x_aux``` e ```y_aux```. Se o movimento do personagem levar para uma posição com uma cópia de um checkpoint anterior, a matriz do jogo é atualizada para a matriz armazenada na cópia do checkpoint, e a posição atual do personagem é atualizada para a posição do checkpoint


```OUTPUT```

Ao final do algoritmo, será impresso os resultados através dos arquivos que foram criados ao longo da compilação da matriz percorrida. Para cada resultado, será criado um arquivo, dentre eles estarão o ```output.data```, responsável por imprimir todas as matrizes percorridas pelo menino, o ```relatorio.data```, responsável por imprimir a quantidade de vida do menino, os itens coletados, os perigos enfrentados, a quantidade de matrizes, quantos caminhos foram percorridos e quantos não foram percorridos.

```Exemplo de OUTPUT```

<center>
<table>
   <tr>
      <td>Output</td>
      <td>Relatório</td>
   </tr>
   <tr>
      <td><img src="images/output.png" /></td>
      <td><img src="images/relatorio.png" /></td>
   </tr>
</table>
</center> 

# Custo Computacional

Para avaliar o custo computacional de um algoritmo ou estrutura de dados, é comum usar a notação assintótica, que descreve a complexidade em termos de como ela cresce em relação ao tamanho dos dados de entrada. As notações mais comuns são O (grande O), Ω (ômega) e Θ (teta). Por exemplo, um algoritmo O(n²) significa que o tempo de execução cresce quadráticamente em relação ao tamanho dos dados de entrada (n). Já um algoritmo O(nlogn) significa que o tempo de execução cresce logaritmicamente em relação ao tamanho dos dados de entrada.

Para exemplicar os custos computacionais, será utilizado como base os algoritmos ```MaxMin1, MaxMin2 e MaxMin3```. A proposta de cada um deles é encontrar o valor máximo e mínimo de um conjunto de números.
O algoritmo ```MaxMin1``` faz duas passagens no conjunto de números, uma para encontrar o máximo e outra para encontrar o mínimo. Seu custo computacional é de O(n), onde n é o tamanho do conjunto.
Já o algoritmo ```MaxMin2``` utiliza a técnica de divisão e conquista, onde divide o conjunto em duas partes iguais, encontra o máximo e o mínimo em cada parte e depois compara os resultados para encontrar o máximo e mínimo global. Seu custo computacional é de O(n log n).
Por fim, o algoritmo ```MaxMin3``` utiliza um método de pares, onde os elementos do conjunto são agrupados em pares, o máximo e mínimo de cada par são comparados e o maior e menor valor é comparado com o máximo e mínimo globais. Seu custo computacional também é de O(n).
No melhor caso, todos os algoritmos têm o mesmo desempenho, pois é necessário percorrer todo o conjunto para encontrar o máximo e mínimo. No pior caso, o algoritmo MaxMin2 é o mais eficiente, pois seu custo computacional é menor que o dos outros algoritmos. No caso médio, o algoritmo MaxMin3 é o mais eficiente, pois tem um custo computacional constante em relação ao tamanho do conjunto.

</p>

<p align="center">
<img src="images/maxmin.png" width="600"/>
</p>
<p align="center">
<em>Imagem 2: Tabela dos casos de MinMax1, MinMax2 e MinMax3. </em>

</p>

Outra maneira de identificar os custos computacionais das notações assintóticas, é a representação gráfica, apresentada na imagem 2. 
Em resumo, ```O (grande O)```, no gráfico, representa o pior caso. Isso ocorre porque ele estabelece um limite superior de tempo de execução para o algoritmo. Isso significa que, para entradas maiores, o tempo de execução ou tempo de acesso nunca excederá o limite superior estabelecido por O. Para o ```Ω (ômega)```, é representado o melhor caso. Ele estabelece um limite inferior para o tempo de execução do algoritmo. Isso significa que, para entradas menores, o tempo de execução ou tempo de acesso nunca será menor do que o limite inferior estabelecido por Ω. Por último, o ```Θ (teta)``` representa o caso médio. Ele estabelece um limite justo para o tempo de execução do algoritmo. Isso significa que, para entradas de tamanho moderado, o tempo de execução ou tempo de acesso será igual ao limite estabelecido por Θ. 

</p>

<p align="center">
<img src="images/grafico.png" width="600"/>
</p>
<p align="center">
<em>Imagem 3: Representação gráfica dos três casos. </em>

</p>

Contudo, para este trabalho, o custo computacional não poderá ser previsto. Isso ocorre porque as condições utilizadas são de forma randômica. Isso pode ser explicado pela probabilidade de Bernoulli, um conceito matemático para representar eventos que têm apenas dois resultados possíveis: sucesso ou fracasso. Em outras palavras, é uma medida de probabilidade para eventos que têm uma distribuição binomial, ou seja, eventos que só podem ter dois resultados possíveis. Um exemplo simples dessa probabilidade seria o jogo de cara ou coroa, em que você joga uma moeda e espera que ela caia com a face desejada. Se você apostar em "cara", o sucesso seria a moeda cair com a face para cima, e o fracasso seria a moeda cair com a face para baixo.

<p align="center">
<img src="images/caraecoroa.png" width="300"/>
</p>
<p align="center">
<em>Imagem 4: Jogo cara e coroa. </em>

</p>

# Conclusão

Com este algoritmo, podemos entender melhor sobre os conceitos de alocação dinâmica de matrizes, seu custo computacional, espaço de memória. Diante disso, é observado em como utilizar vários conceitos relacionados à matriz pode aumentar a noção de programação que, futuramente, poderá ser usada em outros projetos, principalmente em relação à área de jogos.

# Compilação e Execução

O algoritmo disponibilizado possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:

<div>

| Comando                |  Função                                                                                           |
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |

</div>
