+# Proposta do Trabalho

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

O método TF-IDF (Term Frequency-Inverse Document Frequency) é uma técnica bastante utilizada em mineração de textos e recuperação de informações para avaliar a importância de um termo específico em um documento dentro de um conjunto de documentos. A importância é determinada pela frequência do termo no documento e pela raridade do termo nos demais documentos do corpus.

A fórmula do TF (Term Frequency) apresentada é:

</p>

<p align="center">
<img src="images/tfidf.png" width="400"/>
</p>
<p align="center">
<em>Imagem 1: Fórmula do método TF-IDF </em>

</p>

O valor de TF quantifica a frequência de um termo t em um documento d. Ele é utilizado para medir a relevância local de um termo dentro de um documento específico, dando maior peso aos termos que aparecem com maior frequência.

O IDF (Inverse Document Frequency) é definido por:

</p>

<p align="center">
<img src="images/tfidf.png" width="400"/>
</p>
<p align="center">
<em>Imagem 1: Fórmula do método TF-IDF </em>

</p>

Nesta fórmula, N representa o número total de documentos no corpus e df é a quantidade de documentos que contêm o termo t. A adição de 1 no denominador serve para evitar divisões por zero. O IDF mede a relevância global do termo, atribuindo maior peso a termos que aparecem em menos documentos.

A combinação dessas duas métricas resulta no cálculo do TF-IDF, conforme mostrado na equação:

</p>

<p align="center">
<img src="images/tfidf.png" width="400"/>
</p>
<p align="center">
<em>Imagem 1: Fórmula do método TF-IDF </em>

</p>

O valor de TF-IDF é, portanto, um produto da frequência do termo no documento e sua raridade no conjunto de documentos. Essa métrica é útil para destacar termos que são frequentes em um determinado documento, mas incomuns no restante do corpus, o que pode indicar uma maior relevância na diferenciação de conteúdos.

Entre as principais estruturas empregadas, destacam-se os vetores (```std::vector```), os conjuntos não ordenados (```std::unordered_set```), as tabelas de espalhamento (```std::unordered_map```) e o uso da função ```sort```. 

</p>

<p align="center">
<img src="images/mergesort.png" width="400"/>
</p>
<p align="center">
<em>Imagem 5: MergeSort </em>

</p>

Os vetores foram utilizados para armazenar documentos, frases de pesquisa e rankings. Essa escolha se deve à eficiência no acesso direto aos elementos, que ocorre em tempo constante, O(1). Como as operações mais frequentes neste projeto envolvem iteração e acesso sequencial, os vetores foram uma escolha mais apropriada em relação a outras estruturas, como listas ligadas (std::list). Listas ligadas seriam mais vantajosas em cenários com necessidade de inserções e remoções frequentes em posições arbitrárias, mas no contexto deste projeto, a simplicidade e a eficiência de acesso dos vetores oferecem uma solução melhor.

Os conjuntos não ordenados (std::unordered_set) foram empregados para armazenar as stopwords. Essa escolha foi feita devido à necessidade de realizar buscas rápidas para identificar e remover palavras irrelevantes dos documentos. A estrutura unordered_set oferece buscas em tempo constante, O(1), o que é crucial para manter a eficiência na normalização dos textos. Como alternativa, seria possível utilizar vetores para armazenar as stopwords e realizar buscas lineares, O(n), mas isso tornaria o sistema significativamente mais lento para grandes conjuntos de dados.

As tabelas de espalhamento (std::unordered_map) desempenharam um papel essencial no cálculo e armazenamento dos pesos TF-IDF para os termos presentes nos documentos. Essa estrutura foi escolhida por sua capacidade de inserir e acessar elementos em tempo constante. Alternativas como árvores balanceadas (std::map) oferecem ordenação dos dados, mas como a ordenação não é um requisito no cálculo de TF-IDF, as unordered_map proporcionam um desempenho superior. A eficiência no cálculo dos pesos TF-IDF é essencial para garantir que a busca e o ranqueamento dos documentos sejam rápidos e responsivos.

A função sort, utilizada para ordenar os documentos com base em sua relevância, é uma implementação eficiente do algoritmo de ordenação QuickSort na biblioteca padrão do C++. Essa função apresenta complexidade O(n log n), sendo adequada para ordenar grandes quantidades de dados de forma rápida. No contexto deste projeto, a função foi utilizada tanto no ranqueamento dos documentos por frequência quanto no cálculo da relevância baseada em TF-IDF. Embora existam outras abordagens de ordenação, como MergeSort, a implementação de sort é otimizada e aproveita as características do hardware moderno, sendo uma escolha robusta e eficiente para o problema proposto.

Em termos de desempenho, o sistema se mostrou eficiente tanto em relação ao tempo de execução quanto ao uso de memória. A leitura e processamento dos documentos são proporcionais ao número de palavras, O(n), e a normalização dos textos se beneficia da escolha da estrutura unordered_set para as stopwords. O cálculo dos pesos TF-IDF, embora tenha uma complexidade O(n * d), onde n é o número de termos e d é o número de documentos, é otimizado pelo uso de unordered_map, o que permite acesso rápido aos dados durante o processo de ranqueamento. O uso de memória é moderado, uma vez que as tabelas de espalhamento e vetores consomem mais espaço do que listas simples, mas essa sobrecarga é justificada pela necessidade de acesso rápido e eficiente.

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
