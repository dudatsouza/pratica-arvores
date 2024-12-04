#include "problema2.hpp"

void menuInterativo() {
    Node* root = nullptr;
    int escolha;
    int aux = 0, balancear1 = 0;
    bool balancear = false, printar = false;
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
                    std::cout << "Árvore Modificada:\n";
                    prettyPrintTree(root);
                    std::cout << "Altura atual: " << altura << "\n\n";
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
                    std::cout << "Árvore Modificada:\n";
                    prettyPrintTree(root);
                    std::cout << "Altura atual: " << altura << "\n\n";
                }       
            }   

            break;
        case 3:
            std::cout << "Árvore:\n";
            prettyPrintTree(root);
            std::cout << "Nível máximo atual: " << calcularAltura(root) << "\n";
            break;
        case 4:
            std::cout << "Você deseja sugerir rotações para a árvore atual e balanceá-la?\n";
            std::cout << "1. Sim\n";
            std::cout << "2. Não\n";
            std::cin >> balancear1;

            if (balancear1 == 1) {
                balancear = true;
            } else {
                balancear = false;
            }
            aux = 0;
            printar = true;
            sugerirRotacoes(root, aux, balancear, printar);
            if (aux == 0) {
                std::cout << "Nenhuma rotação sugerida, árvore está balanceada.\n";
            }

            if(balancear) {
                while(aux != 0) {
                    aux = 0;
                    sugerirRotacoes(root, aux, balancear, printar);
                }
            }
            
            std::cout << "Árvore atual:\n";
            prettyPrintTree(root);
            break;
        case 5:
            mostrarCaminhoMaisLongo(root);
            std::cout << "Árvore atual:\n";
            prettyPrintTree(root);
            std::cout << "Nível máximo atual: " << calcularAltura(root) << "\n";
            break;
        case 6:
            std::cout << "Para uma melhor análise de crescimento, vamos fazer a analise com vários tamanho de árvores, de 3 até 1000.\n";
            std::cout << "Precione Enter para iniciar a análise de crescimento, e aguarde pode levar alguns segundos...\n";
            std::cin.ignore();
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
