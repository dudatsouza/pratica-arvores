#include "problema1.hpp"
#include "BinaryTree.hpp"
#include "AVLTree.hpp"

int main() {
    Problema1 p1;
    while (true) {
        int choice = p1.menu();

        if (p1.verificarArvoresCriadas(choice)) {
            std::cout << "A árvore ainda não foi criada. Por favor, insira os valores antes de continuar." << std::endl;
            std::cout << "Pressione Enter para continuar...";
            std::cin.get();
            system("clear");
            continue;
        }

        switch (choice) {
            case 1:
                p1.inserirValoresProblema();
                break;
            case 2:
                p1.removerValoresProblema();
                break;
            case 3:
                p1.buscarElementosProblema();
                break;
            case 4:
                p1.inserirValores();
                break;
            case 5:
                p1.removerValores();
                break;
            case 6:
                p1.buscarElemento();
                break;
            case 7:
                p1.desafioAdicional();
                break;
            case 8:
                std::cout << "Saindo..." << std::endl;
                return 0;
            default:
                std::cout << "Opção inválida! Tente novamente." << std::endl;
        }
    }

    return 0;
}
