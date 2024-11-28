
#include "problema2.hpp"

void menuInterativo() {
    Node* root = nullptr;
    int escolha;
    std::vector<int> treeValuesBinary;

    while (true) {
        std::cout << "\nMenu:\n";
        std::cout << "1. Inserir nó\n";
        std::cout << "2. Remover nó\n";
        std::cout << "3. Exibir nível máximo\n";
        std::cout << "4. Sugerir rotações\n";
        std::cout << "5. Mostrar caminho mais longo\n";
        std::cout << "6. Análise de crescimento\n";
        std::cout << "7. Sair\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> escolha;
        std::cin.ignore();

        switch (escolha) {
        case 1:
            treeValuesBinary = multiplasEntradas();

            if (treeValuesBinary.size() == 0) {
                std::cout << "Nenhum valor inserido.\n";                
            } else {
                for (int val : treeValuesBinary) {
                    std::cout << "Inserindo " << val << "...\n";
                    root = inserirNo(root, val);
                    int altura = calcularAltura(root);
                    std::cout << "Altura atual: " << altura << "\n";
                    std::cout << "Árvore atual:\n";
                    prettyPrintTree(root);
                }
            }

            break;
        case 2:
            treeValuesBinary = multiplasEntradas();

            if (treeValuesBinary.size() == 0) {
                std::cout << "Nenhum valor removido.\n";
                break;
            } else {
                for (int val : treeValuesBinary) {
                    std::cout << "Removendo " << val << "...\n";
                    root = removerNo(root, val);
                    int altura = calcularAltura(root);
                    std::cout << "Altura atual: " << altura << "\n";
                    std::cout << "Árvore atual:\n";
                    prettyPrintTree(root);
                }       
            }   

            break;
        case 3:
            std::cout << "Nível máximo atual: " << calcularAltura(root) << "\n";
            std::cout << "Árvore atual:\n";
            prettyPrintTree(root);
            break;
        case 4:
            sugerirRotacoes(root);
            std::cout << "Árvore atual:\n";
            prettyPrintTree(root);
            break;
        case 5:
            mostrarCaminhoMaisLongo(root);
            std::cout << "Árvore atual:\n";
            prettyPrintTree(root);
            break;
        case 6:
            analiseDeCrescimento();
            break;
        case 7:
            std::cout << "Saindo...\n";
            return;
        default:
            std::cout << "Opção inválida. Tente novamente.\n";
        }
    }
}

int main() {
    menuInterativo();
    return 0;
}
