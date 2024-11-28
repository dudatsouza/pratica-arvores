<a name="readme-topo"></a>

<h1 align='center'>
  📊 PROBLEMA 2 - Nível Máximo
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

  🔑 <b>Keywords:</b> 
<br>
</details>

## 🔍 Introdução

<div align='justify'>

  Este [trabalho][trabalho-url] tem como base o **Problema 2** da lista de exercícios de **Árvores Binárias e AVL**, proposto na disciplina de **Algoritmos e Estruturas de Dados II**. 

</div>

<p align="right">(<a href="#readme-topo">voltar ao topo</a>)</p>


## 🎯 Objetivos

<div align="justify">

### Objetivo Geral


### Objetivos Específicos


</div>

<p align="right">(<a href="#readme-topo">voltar ao topo</a>)</p>

## 🔬 Modelagem de Aplicação

<div align="justify">

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