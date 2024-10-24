# Proposta do Trabalho

O objetivo é ranquear os documentos de acordo com a relevância de cada um para uma frase de pesquisa específica, utilizando a métrica TF/IDF para calcular tal relevância.

- Um conjunto de arquivos de texto contendo documentos aleatórios.
- Deverá ser preparado uma lista de frases de pesquisa, onde cada frase deve ser comparada aos documentos fornecidos para determinar a relevância de cada arquivo em relação à frase.


# O Algoritmo

```INPUT```

O projeto utiliza três tipos de arquivos de entrada essenciais para o processamento: frases de pesquisa, documentos e uma lista de stopwords. Esses arquivos desempenham funções específicas na preparação dos dados para a análise e o ranqueamento dos documentos.

O arquivo de frases de pesquisa contém, em cada linha, uma frase utilizada como critério de busca para ranquear os documentos. Essas frases são carregadas por meio da função ```lerFrasesDePesquisa```, que lê cada linha do arquivo e as armazena em uma lista, implementada como um vetor do tipo ```vector<string>```. As frases servem como consultas, sendo comparadas com o conteúdo dos documentos após o processamento.

Os documentos são lidos a partir de uma pasta específica, onde cada arquivo representa um documento individual. A função ```lerDocumentos``` percorre todos os arquivos da pasta fornecida e extrai as palavras de cada um, armazenando-as em um vetor de vetores, no formato ```vector<vector<string>>```, em que cada subvetor corresponde a um documento completo. 

O arquivo de stopwords contém uma lista de palavras comuns que não agregam valor significativo à análise semântica, como artigos e preposições, e que precisam ser removidas do conteúdo dos documentos. A função ```lerStopwords``` carrega essas palavras e as armazena em uma estrutura de conjunto, implementada como ```unordered_set<string>```, permitindo buscas rápidas e eficientes. Durante o processo de normalização dos documentos, essas stopwords são eliminadas, de forma a garantir que apenas termos relevantes sejam utilizados na comparação.

Após a leitura dos documentos e das stopwords, é realizada uma normalização do conteúdo textual. Esse processo converte todas as palavras para letras minúsculas e remove caracteres não alfabéticos. Em seguida, a função ```normalizarDocumentos``` aplica a remoção das stopwords, eliminando termos irrelevantes e deixando apenas palavras significativas para serem utilizadas nos cálculos de relevância e ranqueamento.

Esse fluxo de preparação dos dados de entrada é essencial para assegurar que o sistema funcione de forma correta, possibilitando que os documentos sejam comparados corretamente às frases de pesquisa fornecidas e que os resultados sejam ranqueados de acordo com a relevância calculada.

```Frases utilizadas no INPUT```

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

O objetivo é mostrar quais documentos são mais relevantes para cada frase de pesquisa utilizando duas abordagens distintas: a frequência de termos e o cálculo do TF-IDF.

A função principal que coordena a saída de dados é o output, localizada no arquivo ```print.cpp```. Nessa função, após a leitura e normalização dos documentos, são realizados os cálculos de relevância para cada frase de pesquisa. Esses cálculos utilizam as duas abordagens implementadas: frequência de termos, por meio da função ```ranquearDocsFrequencia```, e TF-IDF, através da função ```ranquearDocsTFIDF```. Ambos os métodos analisam como cada termo da frase de pesquisa ocorre nos documentos e geram um ranking baseado na relevância desses termos.

No caso da abordagem por frequência de termos, o output exibe os documentos ordenados com base na quantidade de vezes que os termos da frase de pesquisa aparecem em cada documento. A função ```ranquearDocsFrequencia``` exibe o ranking no terminal, indicando para cada documento o termo mais frequente e sua contagem, ordenando os documentos de forma decrescente pela frequência. 

A segunda abordagem, baseada no TF-IDF (Term Frequency-Inverse Document Frequency), é gerada pela função ```ranquearDocsTFIDF```. Essa função calcula o peso dos termos em cada documento, considerando não apenas a frequência, mas também a raridade dos termos nos demais documentos. O output desse método é exibido no terminal com precisão de seis casas decimais, mostrando para cada frase de pesquisa os documentos mais relevantes em ordem decrescente de relevância.

Cada ranking gerado contém um cabeçalho indicando a frase de pesquisa correspondente, seguido pela lista de documentos, seus termos mais relevantes e, no caso do TF-IDF, o peso calculado para cada documento. 



```Alguns exemplos de OUTPUT```

```

Ranqueamento dos Documentos para a Frase: "O bolo acabou de sair do forno  "
Documento 2 - Relevância: 0.036639
Documento 3 - Relevância: 0.032949
Documento 5 - Relevância: 0.030802
Documento 6 - Relevância: 0.027848
Documento 1 - Relevância: 0.027803
Documento 4 - Relevância: 0.025803
---

Ranqueamento dos Documentos para a Frase: "Vou assistir uma série hoje  "
Documento 3 - Relevância: 0.005010
Documento 6 - Relevância: 0.004826
Documento 1 - Relevância: 0.004563
Documento 4 - Relevância: 0.004264
Documento 5 - Relevância: 0.001964
Documento 2 - Relevância: 0.000273
---

Ranqueamento dos Documentos para a Frase: "As crianças estão brincando na praça  "
Documento 2 - Relevância: 0.003828
Documento 4 - Relevância: 0.003514
Documento 3 - Relevância: 0.003339
Documento 5 - Relevância: 0.003244
Documento 1 - Relevância: 0.002980
Documento 6 - Relevância: 0.002937
---

```

# Estruturas

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
