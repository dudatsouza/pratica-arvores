#include <iostream>

#include "AVLTree.hpp"
#include "BinaryTree.hpp"
#include "RedBlackTree.hpp"
#include "problema3.hpp"

void displayMenu() {
    std::cout << "\n--- MENU ---\n";
    std::cout << "1. Carregar dados de um arquivo\n";
    std::cout << "2. Inserir palavra e definição\n";
    std::cout << "3. Buscar definição de uma palavra\n";
    std::cout << "4. Autocompletar palavras\n";
    std::cout << "5. Visualizar árvores\n";
    std::cout << "6. Sair\n";
    std::cout << "Escolha uma opção: ";
}

int main() {
    BinaryTree binaryTree;
    AVLTree avlTree;
    RedBlackTree rbTree;

    int choice;
    do {
        displayMenu();
        std::cin >> choice;

        std::string key, definition;
        std::vector<std::string> suggestions;
        std::string filePath = "./datasets/testes.txt";

        switch (choice) {
            case 1:
                std::cout << "Carregando dados do arquivo: " << filePath << "...\n";

                std::cout << "Carregando em Árvore Binária...\n";
                performTest(&binaryTree, "load", filePath);

                std::cout << "Carregando em Árvore AVL...\n";
                performTest(&avlTree, "load", filePath);

                std::cout << "Carregando em Árvore Red-Black...\n";
                performTest(&rbTree, "load", filePath);
                break;

            case 2:
                std::cout << "Digite a palavra: ";
                std::cin >> key;
                std::cout << "Digite a definição: ";
                std::cin.ignore();
                std::getline(std::cin, definition);

                std::cout << "Inserindo em Árvore Binária...\n";
                performTest(&binaryTree, "insert", key, definition);

                std::cout << "Inserindo em Árvore AVL...\n";
                performTest(&avlTree, "insert", key, definition);

                std::cout << "Inserindo em Árvore Red-Black...\n";
                performTest(&rbTree, "insert", key, definition);
                break;

            case 3:
                std::cout << "Digite a palavra a buscar: ";
                std::cin >> key;

                std::cout << "Buscando em Árvore Binária...\n";
                performTest(&binaryTree, "search", key);

                std::cout << "Buscando em Árvore AVL...\n";
                performTest(&avlTree, "search", key);

                std::cout << "Buscando em Árvore Red-Black...\n";
                performTest(&rbTree, "search", key);
                break;

            case 4:
                std::cout << "Digite o prefixo para autocompletar: ";
                std::cin >> key;

                std::cout << "Autocompletando em Árvore Binária...\n";
                performTest(&binaryTree, "autocomplete", key);

                std::cout << "Autocompletando em Árvore AVL...\n";
                performTest(&avlTree, "autocomplete", key);

                std::cout << "Autocompletando em Árvore Red-Black...\n";
                performTest(&rbTree, "autocomplete", key);
                break;
            
            case 5:
                std::cout << "Visualizando a Árvore Binária:\n";
                prettyPrintTree(binaryTree.getRoot());

                std::cout << "\nVisualizando a Árvore AVL:\n";
                prettyPrintTree(avlTree.getRoot());

                std::cout << "\nVisualizando a Árvore Red-Black:\n";
                prettyPrintTree(rbTree.getRoot());
                break;

            case 6:
                std::cout << "Encerrando o programa. Até mais!\n";
                break;                

            default:
                std::cout << "Opção inválida. Tente novamente.\n";
        }
    } while (choice != 6);

    return 0;
}
