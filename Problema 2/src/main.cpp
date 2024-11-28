
#include "problema2.hpp"

void menuInterativo() {
    Node* root = nullptr;
    int escolha, valor;

    while (true) {
        std::cout << "\nMenu:\n";
        std::cout << "1. Inserir nó\n";
        std::cout << "2. Remover nó\n";
        std::cout << "3. Exibir nível máximo\n";
        std::cout << "4. Sugerir rotações\n";
        std::cout << "5. Mostrar caminho mais longo\n";
        std::cout << "6. Sair\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> escolha;

        switch (escolha) {
        case 1:
            std::cout << "Digite o valor a ser inserido: ";
            std::cin >> valor;
            root = inserirNo(root, valor);
            break;
        case 2:
            std::cout << "Digite o valor a ser removido: ";
            std::cin >> valor;
            root = removerNo(root, valor);
            break;
        case 3:
            std::cout << "Nível máximo atual: " << calcularAltura(root) << "\n";
            break;
        case 4:
            sugerirRotacoes(root);
            break;
        case 5:
            mostrarCaminhoMaisLongo(root);
            break;
        case 6:
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
