<a name="readme-topo"></a>

<h1 align='center'>
  📊 PROBLEMA 1 - Árvores Binárias e AVL
</h1>

<div align='center'>

[![SO][Ubuntu-badge]][Ubuntu-url]
[![IDE][vscode-badge]][vscode-url]
[![Make][make-badge]][make-url]
[![Linguagem][cpp-badge]][cpp-url]

Algoritmos e Estruturas de Dados II <br>
Engenharia de Computação <br>
Prof. Michel Pires da Silva <br>
CEFET-MG Campus V <br>
2024/2
</div>

<details>
  <summary>
    <b style='font-size: 15px'>
      📑 Sumário
    </b>
  </summary>
  <ol>
    <li><a href="#-introdução">🔍 Introdução</a></li>
    <li>
      <a href="#-objetivos">🎯 Objetivos</a>
      <ul>
        <li><a href="#objetivo-geral">Objetivo Geral</a></li>
        <li><a href="#objetivos-específicos">Objetivos Específicos</a></li>
      </ul>
    </li>
    <li>
      <a href="#-modelagem-de-aplicação">🔬 Modelagem de Aplicação</a>
      <ul>
        <li><a href="#leitura-dos-dados">Leitura dos Dados</a></li>
        <li>
          <a href="#inserção-de-valores">Inserção de Valores</a>
          <ul>
            <li><a href="#inserção-em-árvores-binárias-de-busca">Inserção em Árvores Binárias de Busca</a></li>
            <li><a href="#inserção-em-árvores-avl">Inserção em Árvores AVL</a></li>
          </ul>
        </li>
        <li>
          <a href="#remoção-de-valores">Remoção de Valores</a>
          <ul>
            <li><a href="#remoção-em-árvores-binárias-de-busca">Remoção em Árvores Binárias de Busca</a></li>
            <li><a href="#remoção-em-árvores-avl">Remoção em Árvores AVL</a></li>
          </ul>
        </li>
        <li><a href="#caminhamentos">Caminhamentos</a></li>
        <li><a href="#desafio-adicional-análise-de-rotações">Desafio Adicional: Análise de Rotações</a></li>
      </ul>
    </li>
    <li>
      <a href="#%EF%B8%8F-metodologia">🗳️ Metodologia</a>
      <ul>
        <li><a href="#-arquivos">Arquivos</a></li>
        <li><a href="#-bibliotecas">Bibliotecas</a></li>
        <li>
          <a href="#definições-e-estruturas-usadas">Definições e Estruturas Usadas</a>
          <ul>
            <li><a href="#arquivo-nodehpp">Arquivo Node.hpp</a></li>
            <li><a href="#arquivo-problema1hpp">Arquivo problema1.hpp</a></li>
            <li><a href="#arquivo-binarytreehpp">Arquivo BinaryTree.hpp</a></li>
            <li><a href="#arquivo-avltreehpp">Arquivo AVLTree.hpp</a></li>
          </ul>
        </li>
        <li>
          <a href="#-funções-implementadas">Funções Implementadas</a>
          <ul>
            <li><a href="#arquivo-maincpp">Arquivo main.cpp</a></li>
            <li><a href="#arquivo-problema1cpp">Arquivo problema1.cpp</a></li>
            <li><a href="#arquivo-binarytreecpp">Arquivo BinaryTree.cpp</a></li>
            <li><a href="#arquivo-avltreecpp">Arquivo AVLTree.cpp</a></li>
          </ul>
        </li>
      </ul>
    </li>
    <li><a href="#-conclusão">🏁 Conclusão</a></li>
    <li>
      <a href="#-começando">🔨 Começando</a>
      <ul>
        <li><a href="#pré-requisitos">Pré-requisitos</a></li>
        <li><a href="#instalando">Instalando</a></li>
      </ul>
    </li>
    <li><a href="#-ambiente-de-compilação-e-execução">🧪 Ambiente de Compilação e Execução</a></li>
    <li><a href="#-contato">📨 Contato</a></li>
    <li><a href="#-referências">📚 Referências</a></li>
  </ol>
</details>


<details> 
  <summary>
    <b style='font-size: 12px'> Abstract </b> 
  </summary>

  O problema abordado neste projeto consiste na implementação e análise de **Árvores Binárias de Busca e Árvores AVL**, com foco na execução de operações fundamentais, como inserção, remoção e busca. Além disso, o projeto propõe um desafio adicional: identificar subconjuntos de valores cujas remoções em uma árvore AVL resultem no maior número de rotações necessárias para manter o balanceamento.

  A solução foi desenvolvida utilizando a linguagem C++, devido à sua eficiência em manipulação de memória e estruturas de dados complexas. O programa apresenta uma interface interativa para explorar os comportamentos das árvores em diferentes cenários, bem como a visualização gráfica das estruturas geradas.

  🔑 <b>Keywords:</b> Árvores Binárias, Árvores AVL, Estruturas de Dados, Balanceamento de Árvores, Rotações, Algoritmos, C++
<br>
</details>

## 🔍 Introdução

<div align='justify'>

  Este [trabalho][trabalho-url] tem como base o **Problema 1** da lista de exercícios de **Árvores Binárias e AVL**, proposto na disciplina de **Algoritmos e Estruturas de Dados II**. O problema consiste na implementação de Árvores Binárias de Busca e Árvores AVL, abordando as operações fundamentais dessas estruturas: inserção, remoção e busca.

  As Árvores Binárias, embora eficientes em cenários balanceados, podem apresentar degradação de desempenho em casos específicos. Para resolver essa limitação, as Árvores AVL introduzem balanceamento automático por meio de rotações, garantindo que a altura da árvore seja mantida em $O(log n)$. Esse comportamento reduz o custo das operações em relação às árvores não balanceadas, que podem atingir complexidade $O(n)$ no pior caso.

  Além das operações básicas, o problema propõe um desafio adicional: identificar subconjuntos de valores que, quando removidos de uma árvore AVL, geram o maior número de rotações. Esse desafio permite explorar o impacto prático do balanceamento nas Árvores AVL, proporcionando uma compreensão mais profunda de seu funcionamento.

  O programa desenvolvido oferece uma interface interativa para a criação, manipulação e análise dessas estruturas, permitindo a visualização gráfica das árvores após cada operação e a execução do desafio adicional com base nos dados fornecidos.
</div>

<p align="right">(<a href="#readme-topo">voltar ao topo</a>)</p>


## 🎯 Objetivos

<div align="justify">

### Objetivo Geral
O objetivo deste trabalho é implementar e analisar o comportamento de Árvores Binárias de Busca e Árvores AVL, destacando suas operações fundamentais e explorando um desafio adicional relacionado ao número de rotações em árvores AVL.

### Objetivos Específicos
- Implementar as operações básicas de inserção, remoção e busca em Árvores Binárias de Busca e AVL.
- Analisar o impacto do balanceamento automático no desempenho das Árvores AVL.
- Propor e resolver o desafio de identificar subconjuntos de valores que maximizem o número de rotações em árvores AVL.
- Oferecer uma interface interativa para manipulação e análise das estruturas.
- Fornecer representações gráficas das árvores para facilitar a compreensão de suas alterações após cada operação.

</div>

<p align="right">(<a href="#readme-topo">voltar ao topo</a>)</p>

## 🔬 Modelagem de Aplicação

<div align="justify">

O desenvolvimento deste projeto foi estruturado com base no **Problema 1** da lista de exercícios, que propõe a implementação de Árvores Binárias de Busca e Árvores AVL. As funcionalidades incluem a inserção, remoção e busca de valores, bem como a resolução de um desafio adicional para identificar subconjuntos de valores que maximizam o número de rotações em Árvores AVL. Nesta seção, detalhamos o funcionamento de cada parte da aplicação, explorando as características das árvores, as operações implementadas e suas diferenças.

### Leitura dos Dados
A aplicação inicia com a leitura dos valores iniciais das árvores, que são armazenados em vetores. Esses valores são utilizados para criar as árvores binárias e AVL, permitindo a execução das operações e a análise do desafio adicional. A leitura dos valores é feita por meio de um menu interativo, que permite ao usuário inserir manualmente os valores ou utilizar conjuntos predefinidos. Os conjuntos predefinidos são os colocados pelo professor no [trabalho][trabalho-url]. Sendo eles:

- **Árvore 1**: {`88, 22, 45, 33, 22, 90, 27, 59, 13`}
- **Árvore 2**: {`65, 47, 21, 11, 72, 23, 05, 34, 28`}
- **Árvore 3**: {`65, 34, 89, 23, 60, 54, 81, 95, 39`}
- **Árvore 4**: {`15, 10, 20, 05, 12, 18, 25, 98, 44`}

Para as remoções também pode ser escolhido um conjunto que o usuário desejar ou um conjunto predefinido, também colocado pelo professor no [trabalho][trabalho-url]. Sendo eles:

- **Árvore 1**: {`33, 90, 33, 45`}
- **Árvore 2**: {`11, 72, 65, 23`}
- **Árvore 3**: {`34, 89, 81, 95`}
- **Árvore 4**: {`20, 05, 18, 44`}

### Inserção de Valores

#### Inserção em Árvores Binárias de Busca
A inserção em uma árvore binária de busca segue a seguinte lógica:
1. Se a árvore estiver vazia, o novo valor é inserido como a raiz.
2. Caso contrário:
   - Se o valor a ser inserido for menor que o nó atual, a inserção continua na subárvore esquerda.
   - Se for maior, a inserção continua na subárvore direita.

Por exemplo, ao inserir os valores `10, 5, 15` nesta ordem, a árvore resultante será:

</div>

<div align='center'>

```
    10
   /  \
    5     15
```
</div>

<div align="justify">

Essa abordagem, embora simples, pode levar a árvores desequilibradas, especialmente se os valores forem inseridos em ordem crescente ou decrescente.

#### Inserção em Árvores AVL
Nas Árvores AVL, a lógica básica de inserção é semelhante à das Árvores Binárias de Busca. Contudo, após cada inserção, a altura da árvore é recalculada, e o balanceamento é ajustado caso seja necessário. Isso é feito por meio das seguintes rotações:
1. **Rotação Simples à Direita**: Corrige desequilíbrios em que o nó da subárvore esquerda está "pesado".
2. **Rotação Simples à Esquerda**: Corrige desequilíbrios em que o nó da subárvore direita está "pesado".
3. **Rotação Dupla Esquerda-Direita**: Corrige desequilíbrios na subárvore esquerda com um nó direito pesado.
4. **Rotação Dupla Direita-Esquerda**: Corrige desequilíbrios na subárvore direita com um nó esquerdo pesado.

Por exemplo, ao inserir os valores `10, 5, 15, 4`:
- Após a inserção de `4`, o nó `10` fica desequilibrado.
- Uma **Rotação Simples à Direita** é aplicada, resultando em:

</div>

<div align='center'>

```
    10
   /  \
    5     15
        /
     4
```

</div>


<div align="justify">


### Remoção de Valores

#### Remoção em Árvores Binárias de Busca
A remoção em uma árvore binária de busca pode ser dividida em três casos:
1. **Nó folha**: O nó é simplesmente removido.
2. **Nó com um filho**: O nó é substituído por seu único filho.
3. **Nó com dois filhos**: O nó é substituído pelo **predecessor in-ordem** (o maior valor na subárvore esquerda).

Por exemplo, ao remover o valor `10` da árvore:

</div>

<div align='center'>

```
    10
   /  \
    5     15
```

</div>

<div align="justify">

- O predecessor in-ordem é `5`.
- A árvore resultante será:

</div>

<div align='center'>

```
    5
       \
        15
```

</div>

<div align="justify">

#### Remoção em Árvores AVL
Nas Árvores AVL, a remoção segue a mesma lógica das Árvores Binárias de Busca, com um passo adicional: após cada remoção, o balanceamento é verificado, e as rotações são aplicadas, caso necessário, para manter a altura proporcional a \(O(\log n)\).

Por exemplo, ao remover `15` da árvore:

</div>

<div align='center'>

```
    10
   /  \
    5     15
```

</div>

<div align="justify">

- A remoção de `15` deixa a árvore desequilibrada, exigindo uma **Rotação Simples à Direita**.

### Caminhamentos
Os caminhamentos determinam a ordem em que os nós da árvore são visitados. Usando a seguinte árvore como exemplo, onde explicitamos os ponteiros `null`:

</div>

<div align='center'>

```
10
/      \
5         15
/ \        / \
/   \      /   \
null  null  null  null
```

</div>

<div align="justify">

Os caminhamentos percorrem a árvore de formas diferentes, considerando inclusive os ponteiros `null`:

1. **Pré-ordem**: Visita o nó atual, seguido pela subárvore esquerda e depois pela direita. Neste caso:
   - Ordem de visita: `10 -> 5 -> null (esquerda de 5) -> null (direita de 5) -> 15 -> null (esquerda de 15) -> null (direita de 15)`.

2. **In-ordem**: Visita a subárvore esquerda, o nó atual e, em seguida, a subárvore direita:
   - Ordem de visita: `null (esquerda de 5), 5, null (direita de 5), 10, null (esquerda de 15), 15, null (direita de 15)`.

3. **Pós-ordem**: Visita a subárvore esquerda, depois a direita, e por último o nó atual:
   - Ordem de visita: `null (esquerda de 5), null (direita de 5), 5, null (esquerda de 15), null (direita de 15), 15, 10`.

4. **Em largura**: Visita os nós nível por nível, da raiz até os nós mais profundos, e para cada nível da esquerda para a direita:
   - Ordem de visita: `10, 5, 15, null (esquerda de 5), null (direita de 5), null (esquerda de 15), null (direita de 15)`.

Cada método de caminhamento é útil em diferentes contextos:
- O caminhamento **in-ordem**, por exemplo, é ideal para gerar uma lista de valores em ordem crescente.
- O **pré-ordem** é amplamente utilizado para clonar ou copiar árvores.
- O **pós-ordem** é útil para apagar árvores, garantindo que os filhos sejam apagados antes do pai.
- O **em nível** é preferido quando o objetivo é percorrer a árvore como uma estrutura de largura.

### Desafio Adicional: Análise de Rotações

O desafio adicional consiste em identificar subconjuntos de valores que maximizem o número de rotações ao serem removidos de uma árvore AVL. Isso foi implementado por meio das seguintes etapas:

1. **Geração de Subconjuntos**:
   - Todos os subconjuntos possíveis do conjunto de valores da árvore são gerados utilizando **bitmasks**. Para $n$ valores, há $2^n - 1$ subconjuntos não vazios.

2. **Teste de Cada Subconjunto**:
   - Para cada subconjunto, a árvore original é copiada e os valores do subconjunto são removidos.
   - Durante cada remoção, o número de rotações é registrado.

3. **Identificação do Melhor Subconjunto**:
   - O subconjunto que gera o maior número de rotações é armazenado, juntamente com o número total de rotações.

Por exemplo:
- Para a árvore com valores `10, 5, 15`:
  - Subconjuntos gerados: `{10}`, `{5}`, `{15}`, `{10, 5}`, etc.
  - Para cada subconjunto, as remoções são simuladas em uma cópia da árvore.

Esse processo permite analisar o impacto das remoções no balanceamento da árvore e reforça o entendimento do comportamento das rotações em Árvores AVL.

</div>

<p align="right">(<a href="#readme-topo">voltar ao topo</a>)</p>

## 🗳️ Metodologia

<div align="justify">

  O projeto foi implementado em **C++**, utilizando a IDE **Visual Studio Code** para o desenvolvimento do código-fonte e a organização modular dos arquivos. A estrutura foi dividida em diferentes classes e arquivos de cabeçalho, responsáveis pela implementação de árvores binárias e árvores AVL, bem como pela interação com o usuário por meio de um menu dinâmico. Essa abordagem permitiu a separação de responsabilidades, maior clareza do código e flexibilidade para futuras expansões.

  ### 📁 Arquivos 

  O projeto está estruturado no diretório `src/`, que contém os arquivos de código-fonte e cabeçalhos. A seguir, descrevemos os arquivos principais e suas responsabilidades:

  - **[main.cpp](src/main.cpp)**: Arquivo principal que contém a função `main()` e gerencia o fluxo do programa. Ele implementa um menu interativo que permite ao usuário realizar operações como inserções, remoções, buscas e resolver o desafio adicional.

  - **[problema1.hpp](src/problema1.hpp)** e **[problema1.cpp](src/problema1.cpp)**: Arquivos que contêm funções auxiliares utilizadas no programa, como gerenciamento das operações principais (inserções, remoções e buscas) e o desafio adicional.

  - **[BinaryTree.hpp](src/BinaryTree.hpp)** e **[BinaryTree.cpp](src/BinaryTree.cpp)**: Implementam a classe `BinaryTree`, que define as operações básicas de uma árvore binária, incluindo caminhamentos (pré-ordem, in-ordem, pós-ordem e em nível).

  - **[AVLTree.hpp](src/AVLTree.hpp)** e **[AVLTree.cpp](src/AVLTree.cpp)**: Implementam a classe `AVLTree`, que estende a `BinaryTree` para adicionar funcionalidade de balanceamento, incluindo rotações simples e duplas.

  - **[Node.hpp](src/Node.hpp)**: Define a estrutura `Node`, utilizada para representar os nós das árvores binárias e AVL, contendo o valor do nó, ponteiros para os filhos esquerdo e direito, e a altura do nó (para árvores AVL).

  - **[makefile](makefile)**: Arquivo para automação da compilação do projeto, definindo regras para gerar os arquivos binários a partir do código-fonte.

  A estrutura do projeto está organizada da seguinte forma:

  ```.
  ├── build
  │ ├── objects/src
  │ │ ├── AVLTree.o
  │ │ ├── BinaryTree.o
  │ │ ├── main.o
  │ │ └── problema1.o
  | └── app
  ├── src
  │ ├── AVLTree.cpp
  │ ├── AVLTree.hpp
  │ ├── BinaryTree.cpp
  │ ├── BinaryTree.hpp
  │ ├── Node.hpp
  │ ├── main.cpp
  │ ├── problema1.cpp
  │ └── problema1.hpp
  ├── make.sh
  ├── makefile
  └── README.md
  ```

</div>

<p align="right">(<a href="#readme-topo">voltar ao topo</a>)</p>

### 📚 Bibliotecas

<div align="justify">

  As bibliotecas utilizadas na implementação do **Problema 1** são as seguintes:

  - [bits/stdc++.h](https://www.geeksforgeeks.org/bitsstdc-h-c-include/): biblioteca que inclui todas as bibliotecas padrão da linguagem C++. Veja abaixo as bibliotecas que usamos da bits/stdc++.h:
    - **[iostream](https://www.cplusplus.com/reference/iostream/)**: Para operações de entrada e saída no console.
    - **[vector](https://www.cplusplus.com/reference/vector/)**: Para manipulação de vetores dinâmicos.
    - **[string](https://www.cplusplus.com/reference/string/)**: Para manipulação de cadeias de caracteres.
    - **[sstream](https://www.cplusplus.com/reference/sstream/)**: Para processamento de strings e conversão entre tipos.
    - **[algorithm](https://www.cplusplus.com/reference/algorithm/)**: Para algoritmos padrão como `std::find`, `std::remove_if`, entre outros.
    - **[utility](https://www.cplusplus.com/reference/utility/)**: Para a utilização de estruturas como `std::pair`.
    - **[memory](https://cplusplus.com/reference/memory/)**: Para gerência de ponteiros inteligentes, como `std::shared_ptr`.

  Essas bibliotecas foram escolhidas para simplificar e modularizar o desenvolvimento do projeto, aproveitando os recursos oferecidos pela biblioteca padrão do C++.

</div>

<p align="right">(<a href="#readme-topo">voltar ao topo</a>)</p>

### Definições e Estruturas Usadas

<div align="justify">

Para a implementação do problema, utilizamos quatro arquivos de cabeçalho principais, responsáveis por definir as classes e estruturas utilizadas no projeto. Cada arquivo foi projetado para modularizar as funcionalidades, promovendo a reutilização de código e a clareza na organização. A seguir, detalharemos todos os métodos e atributos de cada arquivo de cabeçalho.


#### Arquivo [Node.hpp](src/Node.hpp)

O arquivo `Node.hpp` define a estrutura básica para os nós das árvores. Ele utiliza **ponteiros inteligentes (`std::shared_ptr`)** para facilitar o gerenciamento de memória, eliminando a necessidade de desalocar manualmente.
- [`class Node`](src/Node.hpp): Define a estrutura de um nó da árvore.
    - [`int value;`](src/Node.hpp): Valor armazenado no nó. Público, pois será acessado diretamente por outras classes.
    - [`std::shared_ptr<Node> left;`](src/Node.hpp): Ponteiro para o nó filho esquerdo.
    - [`std::shared_ptr<Node> right;`](src/Node.hpp): Ponteiro para o nó filho direito.
    - [`int height;`](src/Node.hpp): Altura do nó, utilizada principalmente para balanceamento em árvores AVL.

#### Arquivo [problema1.hpp](src/problema1.hpp)

O arquivo `problema1.hpp` contém funções auxiliares que lidam com as operações envolvendo árvores binárias e AVL, bem como análise de subconjuntos. Ele herda as classes `BinaryTree` e `AVLTree` e implementa métodos para interagir com as árvores e resolver o desafio adicional.

- [`#include "BinaryTree.hpp"`](#): Inclui o arquivo de cabeçalho da classe `BinaryTree`.
- [`#include "AVLTree.hpp"`](#): Inclui o arquivo de cabeçalho da classe `AVLTree`.

- [`class Problema1`](src/problema1.hpp): Define a classe principal do problema, responsável por gerenciar as operações e interações com as árvores.
    - [`public:`](src/problema1.hpp): Define os métodos e atributos públicos da classe.
        - [`std::vector<int> arvore1, arvore2, arvore3, arvore4;`](src/problema1.hpp): Vetores de valores para inicializar as árvores.
        - [`BinaryTree treeBinary1, treeBinary2, treeBinary3, treeBinary4, treeBinary;`](src/problema1.hpp): Árvores binárias para os valores iniciais.
        - [`std::vector<BinaryTree*> treesBinary;`](src/problema1.hpp): Vetor de ponteiros para as árvores binárias.
        - [`AVLTree treeAVL1, treeAVL2, treeAVL3, treeAVL4, treeAVL;`](src/problema1.hpp): Árvores AVL para os valores iniciais.
        - [`std::vector<AVLTree*> treesAVL;`](src/problema1.hpp): Vetor de ponteiros para as árvores AVL.
        - [`std::vector<int> treeValuesBinary, treeValuesAVL;`](src/problema1.hpp): Vetores para armazenar os valores das árvores binárias e AVL.
        - [`int menu();`](src/problema1.hpp): Exibe o menu interativo e retorna a opção escolhida pelo usuário.
        - [`bool verificarArvoresCriadas(int choice);`](src/problema1.hpp): Verifica se as árvores foram criadas antes de executar operações.
        - [`void inserirValoresProblema();`](src/problema1.hpp): Insere valores nas árvores binárias e AVL.
        - [`void removerValoresProblema();`](src/problema1.hpp): Remove valores das árvores binárias e AVL.
        - [`void buscarElementosProblema();`](src/problema1.hpp): Busca elementos nas árvores binárias e AVL.
        - [`void inserirValores();`](src/problema1.hpp): Insere valores nas árvores binárias e AVL.
        - [`void removerValores();`](src/problema1.hpp): Remove valores das árvores binárias e AVL.
        - [`void buscarElemento();`](src/problema1.hpp): Busca um elemento nas árvores binárias e AVL.
        - [`void desafioAdicional();`](src/problema1.hpp): Resolve o desafio adicional de identificar subconjuntos que maximizam o número de rotações.
        - [`void printordem (std::vector<std::string> order);`](src/problema1.hpp): Imprime os valores das árvores em ordem.
        - [`void buscas(BinaryTree *tree, int target);`](src/problema1.hpp): Realiza buscas nas árvores binárias.
        - [`void criandoArvoresAVLProblema();`](src/problema1.hpp): Cria as árvores AVL para os valores iniciais.
        - [`void criandoArvoreAVL();`](src/problema1.hpp): Cria uma árvore AVL com valores inseridos pelo usuário.
        - [`std::vector<std::vector<int>> gerarSubconjuntos(const std::vector<int>& valores);`](src/problema1.hpp): Gera todos os subconjuntos de um conjunto de valores.
        - [`std::pair<std::vector<int>, int> analisarRotacoesArvore(AVLTree arvore, const std::vector<int>& valores);`](src/problema1.hpp): Analisa as rotações necessárias para manter o balanceamento de uma árvore AVL após a remoção de valores.

#### Arquivo [BinaryTree.hpp](src/BinaryTree.hpp)

A classe `BinaryTree` é a implementação de uma árvore binária de busca genérica. Ela encapsula operações básicas, mantendo os detalhes de inserção e remoção recursiva protegidos, enquanto os métodos de interação são públicos. Ela herda a estrutura `Node` para representar os nós da árvore.

- [`#include "Node.hpp"`](src/Node.hpp): Inclui o arquivo de cabeçalho da estrutura `Node`.
- [`void prettyPrintTree(const std::shared_ptr<Node>& root);`](src/BinaryTree.hpp): Exibe a árvore de forma hierárquica.
- [`void printTreeHelper(const std::shared_ptr<Node>& node, const std::string& prefix, bool isLeft);`](src/BinaryTree.hpp): Auxiliar para exibir a árvore de forma hierárquica.

- [`class BinaryTree`](src/BinaryTree.hpp): Define a classe principal da árvore binária.
    - [`public:`](src/BinaryTree.hpp): Define os métodos e atributos públicos da classe.
        - [`BinaryTree();`](src/BinaryTree.hpp): Construtor da árvore binária.
        - [`void insert(const std::vector<int>& values);`](src/BinaryTree.hpp): Insere múltiplos valores na árvore.
        - [`void remove(const std::vector<int>& values);`](src/BinaryTree.hpp): Remove múltiplos valores da árvore.
        - [`int search_pre_order(const std::shared_ptr<Node>& node, int target, std::vector<std::string>& order, const std::string& direction);`](src/BinaryTree.hpp): Realiza a busca em pré-ordem.
        - [`int search_post_order(const std::shared_ptr<Node>& node, int target, std::vector<std::string>& order, const std::string& direction);`](src/BinaryTree.hpp): Realiza a busca em pós-ordem.
        - [`int search_in_order(const std::shared_ptr<Node>& node, int target, std::vector<std::string>& order, const std::string& direction);`](src/BinaryTree.hpp): Realiza a busca em ordem.
        - [`void search_level_order(int target, int &visits, std::vector<std::string>& order);`](src/BinaryTree.hpp): Realiza a busca em largura.
        - [`std::shared_ptr<Node> getRoot() const;`](src/BinaryTree.hpp): Retorna o nó raiz da árvore.
    - [`protected:`](src/BinaryTree.hpp): Define os métodos e atributos protegidos da classe.
        - [`std::shared_ptr<Node> root;`](src/BinaryTree.hpp): Ponteiro para o nó raiz da árvore.
        - [`std::shared_ptr<Node> insert_recursive(std::shared_ptr<Node> node, int value);`](src/BinaryTree.hpp): Insere valores recursivamente.
        - [`std::shared_ptr<Node> remove_recursive(std::shared_ptr<Node> node, int value);`](src/BinaryTree.hpp): Remove valores recursivamente.
        - [`std::shared_ptr<Node> get_min_value_node(std::shared_ptr<Node> node);`](src/BinaryTree.hpp): Retorna o nó com o menor valor da subárvore.

#### Arquivo [AVLTree.hpp](src/AVLTree.hpp)

A classe `AVLTree` é derivada de `BinaryTree`, estendendo-a com balanceamento automático por meio de rotações. Ela também herda a estrutura `Node` e mantém os métodos de inserção e remoção protegidos, garantindo a manutenção do balanceamento.

- [`#include "BinaryTree.hpp"`](src/BinaryTree.hpp): Inclui o arquivo de cabeçalho da classe `BinaryTree`.
- [`#include "Node.hpp"`](src/Node.hpp): Inclui o arquivo de cabeçalho da estrutura `Node`.

- [`class AVLTree : public BinaryTree`](src/AVLTree.hpp): Define a classe principal da árvore AVL.
    - [`public:`](src/AVLTree.hpp): Define os métodos e atributos públicos da classe.
        - [`AVLTree();`](src/AVLTree.hpp): Construtor da árvore AVL.
        - [`void insert(const std::vector<int>& values);`](src/AVLTree.hpp): Insere valores na árvore, ajustando o balanceamento.
        - [`void remove(const std::vector<int>& values);`](src/AVLTree.hpp): Remove valores e mantém o balanceamento.
        - [`int getRotationCount() const;`](src/AVLTree.hpp): Retorna o número total de rotações realizadas.
        - [`void resetRotationCount();`](src/AVLTree.hpp): Reseta o contador de rotações.
        - [`std::shared_ptr<Node> getRoot() const;`](src/AVLTree.hpp): Retorna o nó raiz da árvore.
        - [`std::shared_ptr<Node> copyNode(const std::shared_ptr<Node>& node) const;`](src/AVLTree.hpp): Copia um nó da árvore.
        - [`AVLTree copy() const;`](src/AVLTree.hpp): Copia a árvore AVL.
    - [`protected:`](src/AVLTree.hpp): Define os métodos e atributos protegidos da classe.
        - [`std::shared_ptr<Node> root;`](src/AVLTree.hpp): Ponteiro para o nó raiz da árvore.
        - [`int rotationCount;`](src/AVLTree.hpp): Contador de rotações realizadas.
        - [`std::shared_ptr<Node> insert_avl_recursive(std::shared_ptr<Node> node, int value);`](src/AVLTree.hpp): Insere valores recursivamente, ajustando o balanceamento.
        - [`std::shared_ptr<Node> remove_avl_recursive(std::shared_ptr<Node> node, int value);`](src/AVLTree.hpp): Remove valores recursivamente.
        - [`std::shared_ptr<Node> rotate_left(std::shared_ptr<Node> z);`](src/AVLTree.hpp): Realiza rotação simples à esquerda.
        - [`std::shared_ptr<Node> rotate_right(std::shared_ptr<Node> z);`](src/AVLTree.hpp): Realiza rotação simples à direita.
        - [`int get_balance(const std::shared_ptr<Node>& node);`](src/AVLTree.hpp): Calcula o fator de balanceamento.
        - [`int height(const std::shared_ptr<Node>& node);`](src/AVLTree.hpp): Retorna a altura de um nó.
        - [`std::shared_ptr<Node> get_min_value_node(std::shared_ptr<Node> node);`](src/AVLTree.hpp): Localiza o menor valor em uma subárvore.
</div>

<p align="right">(<a href="#readme-topo">voltar ao topo</a>)</p>



### 📝 Funções Implementadas

<div align="justify">
  
As funções implementadas no projeto são responsáveis por realizar a manipulação das árvores binárias e AVL, incluindo inserção, remoção, buscas e análise de rotações para otimização de balanceamento. A seguir, são apresentadas as funções implementadas no projeto, organizadas por arquivo fonte.

</div>

#### Arquivo [main.cpp](src/main.cpp)

O arquivo principal `main.cpp` é responsável por inicializar o programa e gerenciar o fluxo de execução por meio de um menu interativo. Ele utiliza a classe `Problema1` para realizar operações nas árvores.

- **Método [`main()`](src/main.cpp)**:
  1. Inicializa um objeto `Problema1`.
  2. Exibe um menu para o usuário com opções relacionadas às operações nas árvores.
  3. Verifica se as árvores foram criadas antes de executar operações específicas.
  4. Gerencia chamadas para funções de inserção, remoção, busca e desafio adicional, conforme a escolha do usuário.
  5. Finaliza o programa quando o usuário opta por sair.


#### Arquivo [problema1.cpp](src/problema1.cpp)

O arquivo `problema1.cpp` contém as implementações dos métodos da classe `Problema1`, que é responsável por gerenciar as operações nas árvores e realizar o desafio adicional.

- **Método [`int menu()`](src/problema1.cpp)**:
  - Exibe o menu de opções para o usuário e retorna a escolha selecionada.

- **Método [`bool verificarArvoresCriadas(int choice)`](src/problema1.cpp)**:
  - Verifica se as árvores necessárias para uma operação foram criadas, retornando `true` caso contrário.

- **Método [`void inserirValoresProblema()`](src/problema1.cpp)**:
  - Insere os valores predefinidos do problema nas árvores binárias.
  - Exibe os resultados das inserções de forma hierárquica.

- **Método [`void removerValoresProblema()`](src/problema1.cpp)**:
  - Remove valores predefinidos das árvores binárias.
  - Exibe os resultados das remoções de forma hierárquica.

- **Método [`void buscarElementosProblema()`](src/problema1.cpp)**:
  - Realiza buscas nos valores predefinidos nas árvores binárias.
  - Exibe o número de visitações e a ordem dos nós para cada tipo de caminhamento.

- **Método [`void inserirValores()`](src/problema1.cpp)**:
  - Permite ao usuário inserir valores personalizados em uma árvore binária.

- **Método [`void removerValores()`](src/problema1.cpp)**:
  - Permite ao usuário remover valores personalizados de uma árvore binária.

- **Método [`void buscarElemento()`](src/problema1.cpp)**:
  - Realiza buscas em uma árvore binária com um valor inserido pelo usuário.

- **Método [`void desafioAdicional()`](src/problema1.cpp)**:
  - Analisa subconjuntos de valores que maximizam o número de rotações em uma árvore AVL.
  - Exibe o melhor subconjunto e o número de rotações geradas.

- **Método [`void printordem(std::vector<std::string> order)`](src/problema1.cpp)**:
  - Exibe a ordem dos valores de um vetor formatado.

- **Método [`void buscas(BinaryTree *tree, int target)`](src/problema1.cpp)**:
  - Realiza buscas em pré-ordem, in-ordem, pós-ordem e largura.
  - Exibe os resultados e o número de visitações para cada tipo de busca.

- **Método [`void criandoArvoresAVLProblema()`](src/problema1.cpp)**:
  - Cria árvores AVL com os valores predefinidos do problema.
  - Exibe os resultados das inserções.

- **Método [`void criandoArvoreAVL()`](src/problema1.cpp)**:
  - Permite ao usuário criar uma árvore AVL com valores personalizados.

- **Método [`std::vector<std::vector<int>> gerarSubconjuntos(const std::vector<int>& valores)`](src/problema1.cpp)**:
  - Gera todos os subconjuntos possíveis de um conjunto de valores.

- **Método [`std::pair<std::vector<int>, int> analisarRotacoesArvore(AVLTree arvore, const std::vector<int>& valores)`](src/problema1.cpp)**:
  - Analisa os subconjuntos de valores que maximizam o número de rotações em uma árvore AVL.

#### Arquivo [BinaryTree.cpp](src/BinaryTree.cpp)

O arquivo `BinaryTree.cpp` contém a implementação das operações fundamentais da árvore binária, incluindo inserção, remoção, busca e impressão da árvore.

- **Construtor [`BinaryTree::BinaryTree()`](src/BinaryTree.cpp)**: Inicializa a árvore com a raiz como `nullptr`.

- **Método [`std::shared_ptr<Node> getRoot() const`](src/BinaryTree.cpp)**: Retorna o nó raiz da árvore.

- **Método [`void insert(const std::vector<int>& values)`](src/BinaryTree.cpp)**: 
  - Insere um vetor de valores na árvore.
  - Imprime a árvore atualizada após cada inserção.

- **Método [`std::shared_ptr<Node> insert_recursive(std::shared_ptr<Node> node, int value)`](src/BinaryTree.cpp)**:
  - Insere valores recursivamente.
  - Retorna o novo nó atualizado.

- **Método [`void remove(const std::vector<int>& values)`](src/BinaryTree.cpp)**:
  - Remove um vetor de valores da árvore.
  - Imprime a árvore atualizada após cada remoção.

- **Método [`std::shared_ptr<Node> remove_recursive(std::shared_ptr<Node> node, int value)`](src/BinaryTree.cpp)**:
  - Realiza a remoção recursivamente considerando os três casos possíveis:
    1. Nó folha.
    2. Nó com um filho.
    3. Nó com dois filhos (utiliza o predecessor).

- **Método [`std::shared_ptr<Node> get_min_value_node(std::shared_ptr<Node> node)`](src/BinaryTree.cpp)**:
  - Localiza o nó com o menor valor em uma subárvore.

- **Método [`void prettyPrintTree(const std::shared_ptr<Node>& root)`](src/BinaryTree.cpp)**:
  - Imprime a árvore de forma hierárquica utilizando conectores visuais.

- **Método [`void printTreeHelper(const std::shared_ptr<Node>& node, const std::string& prefix, bool isLeft)`](src/BinaryTree.cpp)**:
  - Função auxiliar recursiva para suportar a impressão hierárquica.

- **Métodos de Busca**:
  - **[`int search_pre_order`](src/BinaryTree.cpp)**:
    - Realiza a busca em pré-ordem (nó, esquerda, direita).
    - Adiciona "nulo" na ordem se o nó atual for nulo.
  - **[`int search_post_order`](src/BinaryTree.cpp)**:
    - Realiza a busca em pós-ordem (esquerda, direita, nó).
    - Adiciona "(nulo)" na ordem se o nó atual for nulo.
  - **[`int search_in_order`](src/BinaryTree.cpp)**:
    - Realiza a busca em ordem (esquerda, nó, direita).
    - Adiciona "nulo" na ordem se o nó atual for nulo.
  - **[`void search_level_order`](src/BinaryTree.cpp)**:
    - Realiza a busca em largura.
    - Utiliza uma fila para percorrer os níveis da árvore.

#### Arquivo [AVLTree.cpp](src/AVLTree.cpp)

O arquivo `AVLTree.cpp` estende as operações de uma árvore binária para incluir balanceamento automático utilizando rotações. Ele contém métodos especializados para balancear a árvore durante a inserção e remoção.

- **Construtor [`AVLTree::AVLTree()`](src/AVLTree.cpp)**: Inicializa a árvore AVL, definindo a raiz como `nullptr` e o contador de rotações como zero.

- **Método [`void insert(const std::vector<int>& values)`](src/AVLTree.cpp)**:
  - Insere um vetor de valores na árvore AVL.
  - Reseta o contador de rotações antes de cada inserção.
  - Imprime a árvore após cada inserção.

- **Método [`std::shared_ptr<Node> insert_avl_recursive(std::shared_ptr<Node> node, int value)`](src/AVLTree.cpp)**:
  - Realiza a inserção recursivamente e ajusta o balanceamento.
  - Executa rotações (simples e duplas) conforme necessário:
    1. Rotação simples direita.
    2. Rotação simples esquerda.
    3. Rotação dupla esquerda-direita.
    4. Rotação dupla direita-esquerda.

- **Método [`void remove(const std::vector<int>& values)`](src/AVLTree.cpp)**:
  - Remove um vetor de valores da árvore AVL.
  - Reseta o contador de rotações antes de cada remoção.
  - Imprime a árvore após cada remoção.

- **Método [`std::shared_ptr<Node> remove_avl_recursive(std::shared_ptr<Node> node, int value)`](src/AVLTree.cpp)**:
  - Realiza a remoção recursivamente e ajusta o balanceamento.
  - Executa rotações (simples e duplas) após a remoção, conforme necessário.

- **Método [`std::shared_ptr<Node> rotate_left(std::shared_ptr<Node> z)`](src/AVLTree.cpp)**:
  - Realiza uma rotação simples à esquerda.
  - Incrementa o contador de rotações.

- **Método [`std::shared_ptr<Node> rotate_right(std::shared_ptr<Node> z)`](src/AVLTree.cpp)**:
  - Realiza uma rotação simples à direita.
  - Incrementa o contador de rotações.

- **Método [`std::shared_ptr<Node> getRoot() const`](src/AVLTree.cpp)**:
  - Retorna o nó raiz da árvore AVL.

- **Método [`std::shared_ptr<Node> get_min_value_node(std::shared_ptr<Node> node)`](src/AVLTree.cpp)**:
  - Localiza o nó com o menor valor em uma subárvore.

- **Método [`int get_balance(const std::shared_ptr<Node>& node)`](src/AVLTree.cpp)**:
  - Calcula o fator de balanceamento de um nó (diferença de altura entre as subárvores esquerda e direita).

- **Método [`int height(const std::shared_ptr<Node>& node)`](src/AVLTree.cpp)**:
  - Calcula a altura de um nó.

- **Método [`std::shared_ptr<Node> copyNode(const std::shared_ptr<Node>& node)`](src/AVLTree.cpp)**:
  - Copia um nó, incluindo seus filhos.

- **Método [`AVLTree copy() const`](src/AVLTree.cpp)**:
  - Retorna uma cópia completa da árvore AVL.
  
<p align="right">(<a href="#readme-topo">voltar ao topo</a>)</p>

## 🏁 Conclusão

<div align="justify">

A resolução do **Problema 1** representou uma oportunidade significativa para aplicar, de forma prática, os conceitos teóricos de estruturas de dados, com foco em árvores binárias e AVL. Este problema permitiu explorar detalhadamente o funcionamento dessas estruturas, suas operações e características particulares, proporcionando um aprendizado aprofundado e uma visão clara de suas aplicações e limitações.

Ao implementar árvores binárias, foi possível observar sua simplicidade e eficiência em cenários onde o balanceamento não é um fator determinante. No entanto, em situações onde a sequência de inserções ou remoções prejudica a simetria da árvore, percebeu-se um impacto negativo no desempenho, principalmente nas buscas. Em contraste, a implementação da árvore AVL revelou-se essencial para manter a eficiência em operações de busca, especialmente em árvores com grande profundidade. As rotações aplicadas para manter o balanceamento, embora aumentem a complexidade da implementação e o custo computacional, garantem uma performance consistente, especialmente em cenários com inserções e remoções frequentes.

A abordagem adotada para as operações, como o uso do predecessor durante a remoção de nós, foi particularmente desafiadora, exigindo cuidado para preservar a integridade da estrutura e o balanceamento na AVL. Além disso, a análise dos diferentes caminhamentos — pré-ordem, in-ordem, pós-ordem e em largura — destacou a relevância dessas técnicas em diferentes aplicações práticas, como a ordenação e a busca sistemática em conjuntos de dados hierárquicos.

Outro ponto de destaque foi o desafio adicional, que envolveu a geração de subconjuntos e a análise do impacto das remoções em uma árvore AVL. Este exercício não apenas reforçou a compreensão do balanceamento automático, mas também trouxe uma perspectiva prática para a análise de eficiência em algoritmos e estruturas de dados.

Em resumo, o trabalho alcançou os objetivos propostos, destacando as diferenças e aplicações de árvores binárias e AVL, e consolidou o entendimento sobre a importância de selecionar a estrutura de dados adequada para cada problema. Além disso, a experiência prática contribuiu para o desenvolvimento de habilidades fundamentais em análise algorítmica e implementação, abrindo caminho para a exploração de variações mais avançadas de árvores e suas aplicações em problemas reais, como sistemas de busca e gerenciamento de dados. Este projeto, portanto, não apenas solucionou o problema proposto, mas também forneceu uma base sólida para estudos futuros e aplicações mais complexas no campo das estruturas de dados.

</div>

<p align="right">(<a href="#readme-topo">voltar ao topo</a>)</p>

## 🔨 Começando

<div align="justify">

  Nesta seção estão exemplificados os meios através dos quais se tornam possíveis a compilação e execução do programa apresentado.

</div>

### Pré-requisitos

<div align="justify">

  Inicialmente, algumas considerações importantes sobre como se deve preparar o ambiente para compilar e executar o programa:

</div>

> [!NOTE]
> Recomenda-se usar uma distribuição de sistema operacional Linux ou o Windows Subsystem for Linux (WSL), pois os comandos no [makefile][makefile] foram selecionados para funcionar em um ambiente [shell/bash][bash-url].

<div align="justify">

  Considerando um ambiente shell, garanta que os seguintes comandos já foram executados:
  - Atualize os pacotes antes da instalação dos compiladores:
  console
  sudo apt update
  
  - Instale a coleção de compiladores __GNU/g++_ e o _make__:
  console
  sudo apt install build-essential
  
  - Se necessário, instale o __make__ individualmente:
  console
  sudo apt install make
  

</div>

### Instalando

<div align="justify">
  Com o ambiente preparado, os seguintes passos são para a instalação, compilação e execução do programa localmente:

  1. Clone o repositório no diretório desejado:
  console
  git clone https://github.com/dudatsouza/pratica-arvores.git
  cd pratica-arvores

  2. Compile o programa com o __make__, o que gera a pasta build, que contém arquivos de objeto e um arquivo executável:
  console
  make
  
  3. Execute o programa da pasta build após a compilação:
  console
  make run
  

  4. Se necessário, apague a última compilação da pasta build:
  console
  make clean
  

  O programa estará pronto para ser testado. Veja a tabela abaixo com alguns comandos do makefile:

</div>

<div align="center">

  | Comando      | *Descrição*                           |
  |--------------|-----------------------------------------|
  | make       | Compila o programa.                     |
  | make run   | Executa o programa com o arquivo de entrada fornecido. |
  | make clean | Remove os arquivos compilados.          |

</div>

<p align="right">(<a href="#readme-topo">voltar ao topo</a>)</p>

## 🧪 Ambiente de Compilação e Execução

<div align="justify">

  O trabalho foi desenvolvido e testado em um ambiente específico, com as seguintes configurações:

</div>

<div align='center'>

![Ubuntu][ubuntu-badge]
![GCC][gcc-badge]
![Make][make-badge] 

| *Hardware* | *Especificações* |
|:------------:|:-------------------:|
| *Laptop*   | Dell Inspiron 13 5330 |
| *Processador* | Intel Core i7-1360P |
| *Memória RAM* | 16 GB DDR5 |
| *Sistema Operacional* | Windows 11 |
| *IDE* | Visual Studio Code |
| *Placa de Vídeo* | Intel Iris Xe Graphics |

</div>

> [!IMPORTANT] 
> Para que os testes tenham validade, considere as especificações
> do ambiente de compilação e execução do programa.

<p align="right">(<a href="#readme-topo">voltar ao topo</a>)</p>

## 📨 Contato

<div align="justify">

Para mais informações ou sugestões, sinta-se à vontade para entrar em contato:

- ✉️ **E-mail**: [![Gmail Badge](https://img.shields.io/badge/-dudateixeirasouza@gmail.com-c14438?style=flat-square&logo=Gmail&logoColor=white&link=mailto:dudateixeirasouza@gmail.com)](mailto:dudateixeirasouza@gmail.com)
- 💼 **LinkedIn**: [![Linkedin Badge](https://img.shields.io/badge/-LinkedIn-0e76a8?style=flat-square&logo=Linkedin&logoColor=white)](https://www.linkedin.com/in/dudatsouza/)
- 📸 **Instagram**: [![Instagram Badge](https://img.shields.io/badge/-Instagram-e4405f?style=flat-square&logo=Instagram&logoColor=white)](https://www.instagram.com/dudat_18/) 
- 📱 **Telegram**: [![Telegram Badge](https://img.shields.io/badge/-Telegram-2CA5E0?style=flat-square&logo=Telegram&logoColor=white)](https://t.me/dudat_18)

Ficarei feliz em receber feedbacks, contribuições ou responder a quaisquer dúvidas que você possa ter sobre os trabalhos.

</div>

<p align="right">(<a href="#readme-topo">voltar ao topo</a>)</p>

## 🔖 Referências
1. CEFET-MG. **Aula 1 - Árvores Binárias**. Disponível em: [hhttps://ava.cefetmg.br/pluginfile.php/165783/mod_resource/content/8/Aula1.pdf](https://ava.cefetmg.br/pluginfile.php/165783/mod_resource/content/8/Aula1.pdf). Acesso em: 27 nov. 2024.

2. CEFET-MG. **Aula 2 - Árvores AVL**. Disponível em: [https://ava.cefetmg.br/pluginfile.php/261698/mod_resource/content/4/Aula2.pdf](https://ava.cefetmg.br/pluginfile.php/261698/mod_resource/content/4/Aula2.pdf). Acesso em: 27 nov. 2024.


[vscode-badge]: https://img.shields.io/badge/Visual%20Studio%20Code-0078d7.svg?style=for-the-badge&logo=visual-studio-code&logoColor=white
[vscode-url]: https://code.visualstudio.com/docs/?dv=linux64_deb
[make-badge]: https://img.shields.io/badge/_-MAKEFILE-427819.svg?style=for-the-badge
[make-url]: https://www.gnu.org/software/make/manual/make.html
[cpp-badge]: https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white
[cpp-url]: https://en.cppreference.com/w/cpp
[trabalho-url]: https://drive.google.com/file/d/15-BlglLNcPNOn9RRa__aTMfwafC-X43_/view?usp=sharing
[github-prof]: https://github.com/mpiress
[main-ref]: src/main.cpp
[branchAMM-url]: https://github.com/alvarengazv/trabalhosAEDS1/tree/AlgoritmosMinMax
[makefile]: ./makefile
[bash-url]: https://www.hostgator.com.br/blog/o-que-e-bash/
[lenovo-badge]: https://img.shields.io/badge/lenovo%20laptop-E2231A?style=for-the-badge&logo=lenovo&logoColor=white
[ubuntu-badge]: https://img.shields.io/badge/Ubuntu-E95420?style=for-the-badge&logo=ubuntu&logoColor=white
[Ubuntu-url]: https://ubuntu.com/
[ryzen5500-badge]: https://img.shields.io/badge/AMD%20Ryzen_5_5500U-ED1C24?style=for-the-badge&logo=amd&logoColor=white
[ryzen3500-badge]: https://img.shields.io/badge/AMD%20Ryzen_5_3500X-ED1C24?style=for-the-badge&logo=amd&logoColor=white
[windows-badge]: https://img.shields.io/badge/Windows-0078D6?style=for-the-badge&logo=windows&logoColor=white
[gcc-badge]: https://img.shields.io/badge/GCC-5C6EB8?style=for-the-badge&logo=gnu&logoColor=white


[linkedin-autor1]: https://www.linkedin.com/in/guilherme-alvarenga-de-azevedo-959474201/
[telegram-autor1]: https://t.me/alvarengazv
[gmail-autor1]: mailto:gui.alvarengas234@gmail.com

[linkedin-autor2]: https://www.linkedin.com/in/dudatsouza/
[telegram-autor2]: https://t.me/dudat_18
[gmail-autor2]: mailto:dudateixeirasouza@gmail.com

[linkedin-autor3]: https://www.linkedin.com/
[telegram-autor3]: https://t.me/
[gmail-autor3]: mailto:memanuel643@gmail.com

[linkedin-badge]: https://img.shields.io/badge/-LinkedIn-0077B5?style=for-the-badge&logo=Linkedin&logoColor=white
[telegram-badge]: https://img.shields.io/badge/Telegram-2CA5E0?style=for-the-badge&logo=telegram&logoColor=white
[gmail-badge]: https://img.shields.io/badge/-Gmail-D14836?style=for-the-badge&logo=Gmail&logoColor=white