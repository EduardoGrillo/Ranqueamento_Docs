# Proposta do Trabalho

O objetivo é ranquear os documentos de acordo com a relevância de cada um para uma frase de pesquisa específica, utilizando a métrica TF/IDF para calcular tal relevância.

- Um conjunto de arquivos de texto contendo documentos aleatórios.
- Deverá ser preparado uma lista de frases de pesquisa, onde cada frase deve ser comparada aos documentos fornecidos para determinar a relevância de cada arquivo em relação à frase.


# O Algoritmo

```INPUT```

O projeto começa com a leitura de diversos documentos de texto armazenados na pasta ```dataset/input/```. Cada documento é processado para que seus termos sejam extraídos de maneira limpa e normalizada. Além dos documentos, o programa também lê duas fontes adicionais de entrada: uma lista de frases de pesquisa e um conjunto de stopwords. As frases de pesquisa são carregadas do arquivo ```frases.txt```, e cada linha desse arquivo representa uma frase que será utilizada para avaliar a relevância dos documentos. O objetivo é que o sistema compare essas frases com os documentos e determine quais são mais relevantes.

O arquivo ```stopwords.txt``` contém palavras comuns que não possuem valor significativo para o cálculo da relevância, como artigos e preposições. Essas palavras são eliminadas durante o processamento para evitar que influenciem o ranqueamento. A leitura dos documentos é feita de forma sequencial, abrindo cada arquivo localizado na pasta de entrada. Se algum arquivo não puder ser aberto corretamente, o programa emite uma mensagem de erro e continua com os demais arquivos. A cada palavra lida, o sistema a converte para letras minúsculas e remove pontuações, garantindo uniformidade na comparação entre documentos e frases de pesquisa. Além disso, todas as stopwords presentes nos documentos são removidas.

Ao final desse processo, cada documento é representado por um vetor de termos relevantes, pronto para ser analisado. Esse cuidado na normalização é fundamental para que o cálculo de TF-IDF funcione corretamente e para garantir que apenas palavras significativas sejam consideradas na análise.

Frases utilizadas no INPUT

```
O céu está muito azul hoje  
Acordei de bom humor  
Comprei frutas no mercado  
A tarde foi bem tranquila  
Preciso organizar minha mesa  
O cachorro está brincando no quintal  
A água do rio é cristalina  
Hoje é um bom dia para correr  
A comida ficou salgada demais  
Vamos tomar sorvete mais tarde  
Estou com saudade da praia  
O livro novo é muito interessante  
A cidade está silenciosa à noite  
Gosto de ver o pôr do sol  
A brisa da manhã é refrescante  
O bolo acabou de sair do forno  
Vou assistir uma série hoje  
As crianças estão brincando na praça  
Preciso encontrar meus óculos  
O jantar foi perfeito  
```


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
