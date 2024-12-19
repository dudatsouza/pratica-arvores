#ifndef PROBLEMA3_HPP
#define PROBLEMA3_HPP

#include <string>
#include <vector>
#include <chrono>
#include "Node.hpp"

// Estrutura para armazenar o tempo de execução e o número de interações
struct Result {
    double timeMs;    // Tempo em milissegundos
    int interactions; // Número de interações realizadas
};

// Classe abstrata para dicionário
class Dictionary {
public:
    virtual ~Dictionary() = default;

    // Inserir uma palavra e sua definição
    virtual Result insert(const std::string& key, const std::string& definition) = 0;

    // Buscar a definição de uma palavra
    virtual Result search(const std::string& key, std::string& definition) = 0;

    // Sugerir palavras com base em um prefixo
    virtual Result autocomplete(const std::string& prefix, std::vector<std::string>& suggestions) = 0;
};

// Função auxiliar para realizar testes em diferentes árvores
void performTest(Dictionary* tree, const std::string& operation, const std::string& key, const std::string& definition = "");

void loadDataset(Dictionary* tree, const std::string& filename);

// Funções para visualização da árvore
void prettyPrintTree(Node* root);
void printTreeHelper(Node* node, const std::string& prefix, bool isLeft);

#endif // PROBLEMA3_HPP
