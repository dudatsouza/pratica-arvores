<a name="readme-topo"></a>

<h1 align='center'>
  📊 PROBLEMA 2 - Cálculo e Análise do Nível Máximo

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
  O **Problema 2** propõe o estudo e a implementação de algoritmos relacionados ao cálculo do nível máximo de árvores binárias, incluindo a análise de suas propriedades estruturais e o impacto de operações como inserção e remoção. O nível máximo, que determina a profundidade da folha mais distante da raiz, é uma métrica fundamental para entender a eficiência e o balanceamento de árvores binárias. Além disso, o problema inclui desafios adicionais, como a análise de crescimento, identificação do caminho mais longo e sugestões de rotações para balanceamento, proporcionando uma abordagem abrangente para explorar o comportamento das árvores binárias em diferentes cenários.


  🔑 <b>Keywords:</b> Árvores Binárias, Nível Máximo, Estruturas de Dados, Inserção e Remoção, Análise de Crescimento, Balanceamento, Caminho Mais Longo, Rotações.

<br>
</details>

## 🔍 Introdução

<div align='justify'>

  
Este [trabalho][trabalho-url] tem como base o **Problema 2** da lista de exercícios de **Árvores Binárias e AVL**, proposto na disciplina de **Algoritmos e Estruturas de Dados II**. O objetivo principal é explorar a profundidade estrutural das árvores binárias através do cálculo do nível máximo, permitindo uma melhor compreensão da eficiência e do impacto do balanceamento em operações fundamentais como inserção e remoção. 

O nível máximo, também conhecido como altura da árvore, é a distância da raiz até a folha mais profunda, sendo uma métrica importante para avaliar o desempenho e a estabilidade de algoritmos que utilizam árvores como estrutura de dados. Além disso, este trabalho busca integrar conceitos de visualização interativa, análise de crescimento e sugestão de rotações, possibilitando que o comportamento das árvores seja analisado de forma mais dinâmica e abrangente.

Por fim, o **Problema 2** também introduz um desafio adicional, que consiste em sugerir rotações ou reorganizações para balancear a árvore com base no nível máximo calculado, abordando aspectos práticos e teóricos do balanceamento em árvores binárias. Este trabalho não apenas reforça conceitos fundamentais de estruturas de dados, mas também permite o desenvolvimento de habilidades analíticas e de implementação em situações práticas.

</div>

<p align="right">(<a href="#readme-topo">voltar ao topo</a>)</p>


## 🎯 Objetivos

<div align="justify">

### Objetivo Geral

O objetivo geral deste trabalho é explorar e implementar algoritmos e técnicas de análise estrutural de árvores binárias, com foco no cálculo do nível máximo, visualização interativa, análise de crescimento e sugestões de balanceamento, utilizando conceitos aprendidos na disciplina de **Algoritmos e Estruturas de Dados II**.


### Objetivos Específicos


- Implementar uma função para calcular o nível máximo de uma árvore binária e analisar sua profundidade em diferentes cenários.
- Fornecer uma visualização interativa que permita ao usuário observar mudanças no nível máximo após inserções e remoções de nós.
- Comparar o crescimento e a profundidade de árvores desbalanceadas e balanceadas, explorando diferentes conjuntos de inserções.
- Identificar o caminho mais longo da raiz até uma folha, permitindo análises sobre o impacto do desbalanceamento.
- Desenvolver uma abordagem para sugerir rotações ou reorganizações que poderiam tornar a árvore balanceada com base no nível máximo calculado.
- Consolidar conceitos de balanceamento e eficiência em árvores binárias e AVL por meio de uma aplicação prática.


</div>

<p align="right">(<a href="#readme-topo">voltar ao topo</a>)</p>

## 🔬 Modelagem de Aplicação

<div align="justify">

A solução para o **Problema 2** foi desenvolvida de maneira modular, permitindo a interação do usuário com a árvore binária por meio de um menu interativo. A partir dos conceitos aprendidos sobre árvores binárias e AVL, a implementação deste problema foi estruturada para abordar desafios práticos e teóricos relacionados à profundidade, desbalanceamento e reorganização de árvores. A seguir, detalharemos os principais aspectos da modelagem da aplicação:

### Menu Interativo
A interação com a aplicação é realizada por meio de um menu intuitivo, implementado na função [`menuInterativo`](src/main.cpp). O menu oferece as seguintes opções:
1. Inserir nós.
2. Remover nós.
3. Exibir a altura atual da árvore.
4. Sugerir rotações para balanceamento.
5. Mostrar o caminho mais longo.
6. Realizar uma análise de crescimento.
7. Sair do programa.

### Inserção de Valores
A inserção de valores na árvore binária é feita de maneira iterativa. Para cada valor fornecido, a função [`inserirNo`](src/problema2.cpp) é chamada, garantindo a adição do elemento na posição correta, de acordo com as propriedades da árvore binária de busca. 

### Remoção de Valores
A remoção de valores segue uma abordagem similar à inserção, sendo feita para cada valor informado pelo usuário. A função [`removerNo`](src/problema2.cpp) lida com casos especiais, como nós com um único filho ou folhas, garantindo que a estrutura da árvore seja mantida.

### Leitura dos Dados
Os dados fornecidos pelo usuário são capturados utilizando a função [`multiplasEntradas`](src/problema2.cpp), permitindo a entrada de valores separados por vírgulas. Isso possibilita operações em lote, como inserir ou remover múltiplos valores de uma só vez. A entrada é validada, e mensagens de erro são exibidas caso haja valores inválidos.

### Visualização da Altura e Estrutura
Após cada operação de inserção ou remoção, a altura atual da árvore é exibida, e sua estrutura é mostrada ao usuário. Esse recurso auxilia na compreensão do impacto de cada modificação realizada. Para facilitar a visualização da árvore pelo usuário, a função [`prettyPrintTree`](src/problema2.cpp) exibe os nós hierarquicamente, indicando os filhos esquerdo e direito de cada nó.

### Altura Máxima da Árvore

A aplicação inclui a funcionalidade de **encontrar a altura máxima da árvore**, que representa o comprimento do caminho mais longo da raiz até um nó folha. Esse cálculo é fundamental para analisar o balanceamento e a eficiência de operações na árvore.

A função responsável por calcular a altura máxima é [`encontrarAlturaMaxima`](src/problema2.cpp), que utiliza um algoritmo recursivo para percorrer a árvore e determinar sua profundidade.

1. **Definição Base**:
   - Se a árvore estiver vazia, a altura é definida como `0`.
   - Caso contrário, a função é chamada recursivamente para os nós esquerdo e direito.

2. **Recursão**:
   - Para cada nó, a função calcula a altura máxima de suas subárvores esquerda e direita.
   - A altura do nó atual é definida como o maior valor entre as alturas das subárvores, incrementado em `1`.

3. **Resultado Final**:
   - Após visitar todos os nós, a função retorna a altura máxima da árvore, que é exibida ao usuário.

#### Exemplo de Execução

Considere a seguinte árvore binária:

```
        10
       /  \
      5    15
     / \  
    3   7 
```


1. A função começa na raiz (`10`) e recorre aos filhos esquerdo (`5`) e direito (`15`).
2. No ramo esquerdo, a subárvore com raiz em `5` é avaliada, onde as alturas de `3` e `7` são `1`.
3. A altura do nó `5` é calculada como `max(1, 1) + 1 = 2`.
4. No ramo direito, o nó `15` é uma folha, resultando em altura `1`.
5. A altura máxima da árvore é então `max(2, 1) + 1 = 3`.

O cálculo da altura máxima é essencial para:
- Avaliar o balanceamento de árvores AVL, onde a diferença de altura entre as subárvores deve ser no máximo `1`.
- Analisar a eficiência de buscas e inserções, já que o desempenho dessas operações depende diretamente da altura da árvore.

### Sugestão de Rotações

A função [`sugerirRotacoes`](src/problema2.cpp) analisa o balanceamento da árvore e sugere rotações caso algum nó esteja desbalanceado. Mensagens claras indicam ao usuário onde e qual rotação deve ser aplicada.

A sugestão de rotações é baseada no cálculo do **fator de balanceamento** para cada nó da árvore. O fator de balanceamento é a diferença entre as alturas da subárvore esquerda e da subárvore direita. Este valor determina se a árvore está equilibrada ou se uma rotação é necessária.

- **Fator de Balanceamento**:
  - Valores aceitáveis: `-1`, `0`, `1`.
  - Valores fora deste intervalo indicam desbalanceamento:
    - **Fator < -1**: A subárvore direita é mais profunda.
    - **Fator > 1**: A subárvore esquerda é mais profunda.

- **Identificação de Rotações**:
  - Com base no fator de balanceamento do nó pai e dos nós filhos, as rotações sugeridas podem ser:
    - **Rotação Simples à Esquerda**:
      - Ocorre quando a subárvore direita está desbalanceada e o fator de balanceamento do nó filho direito é maior ou igual a `0`.
    - **Rotação Simples à Direita**:
      - Ocorre quando a subárvore esquerda está desbalanceada e o fator de balanceamento do nó filho esquerdo é menor ou igual a `0`.
    - **Rotação Dupla à Esquerda**:
      - Ocorre quando a subárvore direita está desbalanceada e o fator de balanceamento do nó filho direito é negativo.
    - **Rotação Dupla à Direita**:
      - Ocorre quando a subárvore esquerda está desbalanceada e o fator de balanceamento do nó filho esquerdo é positivo.


A função `sugerirRotacoes` percorre a árvore, recalculando a altura de cada nó e verificando os fatores de balanceamento. Caso um nó esteja desbalanceado, a função identifica o tipo de rotação necessária e exibe uma mensagem no console, indicando:
- O nó desbalanceado.
- O tipo de rotação sugerida (simples ou dupla).
- A subárvore onde a rotação deve ser aplicada.

#### Exemplo de Execução

Considere a seguinte sequência de inserções: `30`, `20`, `10`.

1. Após inserir o valor `10`:
   - O fator de balanceamento do nó `30` será `2` (desbalanceado).
   - A subárvore esquerda do nó `30` (raiz) estará mais profunda.
   - O fator de balanceamento do nó `20` (filho esquerdo) será `1`.

**Sugestão**: **Rotação Simples à Direita no nó `30`**.

A árvore resultante será balanceada:

```
        20
       /  \
      10   30
```

A funcionalidade de sugestão de rotações é crucial para manter a árvore balanceada, garantindo:
- Operações eficientes de busca, inserção e remoção.
- Melhor visualização e entendimento do balanceamento das árvores AVL.
- Uma ferramenta pedagógica para demonstrar como as rotações influenciam na estrutura da árvore.


### Caminho Mais Longo
A aplicação permite que o usuário visualize o **caminho mais longo** da raiz até um nó folha. Essa funcionalidade é implementada na função [`mostrarCaminhoMaisLongo`](src/problema2.cpp). Para identificar o caminho mais longo, a função utiliza uma abordagem recursiva que percorre a árvore em profundidade, acumulando os nós visitados.

1. **Recursão**:
   - A função inicia na raiz da árvore e, para cada nó, recursivamente percorre os filhos esquerdo e direito.
   - Para cada ramo da árvore, ela calcula o comprimento do caminho.

2. **Comparação de Altura**:
   - Em cada passo, os caminhos das subárvores esquerda e direita são comparados.
   - O caminho mais longo entre os dois é selecionado.

3. **Acumulação de Nós**:
   - À medida que a função recorre à árvore, os valores dos nós visitados no caminho atual são armazenados em uma estrutura, como um vetor (`std::vector<int>`).

4. **Resultado**:
   - Após visitar todos os nós, o caminho mais longo é retornado e exibido ao usuário como uma sequência de valores.

#### Exemplo de Execução

Considere a seguinte árvore binária:

```
        10
       /  \
      5    15
     / \  
    3   7 
```

1. A função começa na raiz (`10`) e calcula o comprimento do caminho para os filhos esquerdo (`5`) e direito (`15`).
2. No ramo esquerdo (`5`), ela continua para os nós `3` e `7`, identificando o caminho mais longo como `10 -> 5 -> 3`.
3. Comparando com o ramo direito (`10 -> 15`), o caminho mais longo é determinado como `10 -> 5 -> 3`.

Este recurso é útil para identificar possíveis desbalanceamentos na árvore e compreender sua profundidade estrutural.

### Análise de Crescimento

A **análise de crescimento**, implementada na função [`analiseDeCrescimento`](src/problema2.cpp), avalia o impacto do balanceamento na altura das árvores e, por consequência, na eficiência das operações realizadas. Essa análise utiliza funções específicas para gerar duas configurações de árvores: **tortas** (completamente desbalanceadas) e **parcialmente balanceadas**, permitindo uma comparação clara entre os dois cenários.

#### Funcionamento

1. **Geração de Árvores**:
   - **Árvore Torta**:
     - A função [`gerarArvoreTorta`](src/problema2.cpp) cria uma árvore completamente desbalanceada, onde os valores são inseridos em ordem crescente. Esse processo faz com que cada novo nó seja adicionado ao lado direito da árvore, resultando em uma estrutura semelhante a uma lista encadeada.
     - **Implementação**:
       - Um vetor de valores inteiros é preenchido sequencialmente de 1 até \( m \), onde \( m \) representa o tamanho da árvore. Cada valor será posteriormente inserido na árvore, sempre no lado direito, devido à ordem crescente dos dados.
       - Exemplo para \( m = 5 \):
         ```
         Vetor gerado: [1, 2, 3, 4, 5]
         Árvore resultante:
         1
          \
           2
            \
             3
              \
               4
                \
                 5
         ```

   - **Árvore Parcialmente Balanceada**:
     - A função [`gerarArvoreDesbalanceada`](src/problema2.cpp) simula uma árvore mais equilibrada, mas não completamente balanceada. Os valores são distribuídos em três blocos:
       - **Subárvore mais profunda (lado esquerdo)**: contém os menores valores, inseridos de forma decrescente para formar uma estrutura densa.
       - **Nível central (base do balanceamento)**: os valores intermediários são adicionados em ordem crescente, garantindo uma estrutura centralizada.
       - **Subárvore mais rasa (lado direito)**: contém os maiores valores, também inseridos em ordem crescente.
     - **Implementação**:
       - O tamanho da subárvore mais profunda é calculado dividindo \( m \) por um fator de ajuste (neste caso, \( 2.5 \)). Isso distribui os valores entre os três blocos mencionados.
       - Para cada bloco, um laço preenche o vetor com os valores correspondentes. O resultado é um vetor que, ao ser inserido na árvore, cria uma configuração próxima ao equilíbrio.
       - Exemplo para \( m = 15 \):
         Vetor gerado: [6, 5, 4, 3, 2, 1, 7, 8, 9, 10, 11, 12, 13, 14, 15]
         Árvore resultante:

         ```
                      7
                 /        \
                /          \
               3            11
            /    \        /    \
           1      5      9     13
          /  \   / \    / \    / \
         2   4  6   8  10  12 14 15
        ```

2. **Construção e Inserção**:
   - Ambos os vetores gerados são utilizados para construir as árvores. Os valores são inseridos sequencialmente por meio da função [`inserirNo`](src/problema2.cpp), que insere cada elemento na árvore respeitando as regras de uma árvore binária de busca.

3. **Cálculo das Alturas**:
   - Após a construção, a altura de cada árvore é calculada pela função [`calcularAltura`](src/problema2.cpp), que realiza um caminhamento recursivo até o nó mais profundo, retornando a altura máxima.

4. **Depreciação de Desempenho**:
   - A função [`analisando`](src/problema2.cpp) calcula a diferença percentual entre as alturas das duas árvores, permitindo observar como o balanceamento influencia a eficiência:
     \[
     \text{Depreciação} = \frac{\text{Altura Torta} - \text{Altura Equilibrada}}{\text{Altura Torta}} \times 100
     \]

5. **Iteração para Diferentes Tamanhos**:
   - A função [`analiseDeCrescimento`](src/problema2.cpp) realiza o processo para tamanhos de árvore variando de \( m = 5 \) até \( m = 1000 \), registrando a depreciação para cada tamanho e exibindo os resultados.

---

#### Por que as Árvores são Geradas Dessa Forma?

- **Árvore Torta**:
  - Representa o **pior caso** para uma árvore binária de busca, destacando o impacto negativo de inserções sequenciais em ordem crescente.
  - A altura da árvore cresce linearmente com o número de elementos (\( O(n) \)).

- **Árvore Parcialmente Balanceada**:
  - Busca simular uma distribuição mais próxima de uma árvore equilibrada, sem utilizar algoritmos específicos de balanceamento, como em uma árvore AVL.
  - A configuração resultante tem uma altura significativamente menor do que a da árvore torta, mas ainda maior do que a de uma árvore balanceada ideal.

---

#### Importância da Análise

A análise de crescimento destaca os benefícios de estruturas balanceadas:
- Árvores tortas apresentam um desempenho significativamente inferior, com tempo de busca, inserção e remoção diretamente proporcional ao número de elementos.
- Árvores parcialmente balanceadas demonstram uma melhoria significativa na eficiência, com alturas mais próximas ao ideal, reduzindo o tempo de execução das operações.

A implementação das funções para geração das árvores e cálculo da depreciação reforça a importância do balanceamento, mesmo em casos onde a otimização completa (como AVL) não é aplicável.

<p align="right">(<a href="#readme-topo">voltar ao topo</a>)</p>


</div>

<p align="right">(<a href="#readme-topo">voltar ao topo</a>)</p>

## 🗳️ Metodologia

<div align="justify">

  O projeto foi implementado em **C++**, utilizando a IDE **Visual Studio Code** para o desenvolvimento do código-fonte e a organização modular dos arquivos. A estrutura foi dividida em diferentes classes e arquivos de cabeçalho, responsáveis pela implementação de árvores binárias e árvores AVL, bem como pela interação com o usuário por meio de um menu dinâmico. Essa abordagem permitiu a separação de responsabilidades, maior clareza do código e flexibilidade para futuras expansões.

  ### 📁 Arquivos 



  

  A estrutura do projeto está organizada da seguinte forma:

  ```.
  ├── build
  │ ├── objects/src
  │ │ ├── main.o
  │ │ └── problema1.o
  | └── app
  ├── src
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

#### Arquivo [problema2.hpp](src/problema2.hpp)



</div>

<p align="right">(<a href="#readme-topo">voltar ao topo</a>)</p>



### 📝 Funções Implementadas

<div align="justify">


</div>

#### Arquivo [main.cpp](src/main.cpp)

O arquivo principal `main.cpp` é responsável por inicializar o programa e gerenciar o fluxo de execução por meio de um menu interativo.



#### Arquivo [problema2.cpp](src/problema2.cpp)



<p align="right">(<a href="#readme-topo">voltar ao topo</a>)</p>

## 🏁 Conclusão

<div align="justify">


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

[linkedin-badge]: https://img.shields.io/badge/-LinkedIn-0077B5?style=for-the-badge&logo=Linkedin&logoColor=white
[telegram-badge]: https://img.shields.io/badge/Telegram-2CA5E0?style=for-the-badge&logo=telegram&logoColor=white
[gmail-badge]: https://img.shields.io/badge/-Gmail-D14836?style=for-the-badge&logo=Gmail&logoColor=white