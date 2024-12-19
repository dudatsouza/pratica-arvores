#include "problema3.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>

namespace fs = std::filesystem;

// Função para carregar um conjunto de teste de um arquivo TXT
void loadDataset(Dictionary* tree, const std::string& filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Erro: Não foi possível abrir o arquivo: " << filename << std::endl;
        return;
    }

    std::string line;
    int count = 0;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string key, definition;

        // Separar palavra e definição (delimitador ":")
        if (std::getline(ss, key, ':') && std::getline(ss, definition)) {
            Result result = tree->insert(key, definition);
            count++;
        }
    }

    file.close();
    std::cout << count << " entradas carregadas do arquivo: " << filename << std::endl;
}

// Função para gerenciar operações no menu
void performTest(Dictionary* tree, const std::string& operation, const std::string& key, const std::string& definition) {
    Result result;
    std::string retrievedDefinition;
    std::vector<std::string> suggestions;

    if (operation == "insert") {
        result = tree->insert(key, definition);
    } else if (operation == "search") {
        result = tree->search(key, retrievedDefinition);
        if (result.timeMs != 0) {
            std::cout << "Definição encontrada: " << retrievedDefinition << "\n";
        } else {
            std::cout << "Palavra não encontrada.\n";
        }
    } else if (operation == "autocomplete") {
        result = tree->autocomplete(key, suggestions);
        std::cout << "Sugestões: ";
        for (const auto& suggestion : suggestions) {
            std::cout << suggestion << " ";
        }
        std::cout << "\n";
    } else if (operation == "load") {
        loadDataset(tree, key); // "key" é usado para passar o caminho do arquivo
    }

    if (operation != "load") {
        std::cout << "Tempo: " << result.timeMs << " ms, Interações: " << result.interactions << "\n";
    }
}

// Função auxiliar recursiva para imprimir a árvore
void printTreeHelper(Node* node, const std::string& prefix, bool isLeft) {
    if (node != nullptr) {
        if (prefix == "") {
            // Root node (T)
            std::cout << "(T)────";
        } else {
            // Display the node with its prefix
            std::cout << prefix;

            // Choose connector based on whether it's left or right child
            std::cout << (isLeft ? "(L)├────" : "(R)└────");
        }

        // Print the node's key
        std::cout << node->key << std::endl;

        // Recur for children (left and right)
        // Adjust the prefix for alignment
        printTreeHelper(node->left, prefix + (isLeft ? "   │     " : "      "), true);
        printTreeHelper(node->right, prefix + (isLeft ? "   │     " : "      "), false);
    }
}

// Função para imprimir a árvore no formato solicitado
void prettyPrintTree(Node* root) {
    printTreeHelper(root, "", false);
}
