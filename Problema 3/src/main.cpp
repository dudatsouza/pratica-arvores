
#include <iostream>
#include "problema3.hpp"

int main() {
    TreeNode* dicionario = nullptr;

    // Inserindo palavras no dicionário
    dicionario = inserir(dicionario, "apple", "A fruit");
    dicionario = inserir(dicionario, "apricot", "Another fruit");
    dicionario = inserir(dicionario, "banana", "Yellow fruit");
    dicionario = inserir(dicionario, "blueberry", "A small blue fruit");
    dicionario = inserir(dicionario, "cherry", "A red fruit");

    // Simulando busca de sugestões
    std::string prefixo;
    std::cout << "Digite o prefixo para sugestões: ";
    std::cin >> prefixo;

    std::vector<std::string> resultados;
    sugestoes(dicionario, prefixo, resultados);

    std::cout << "Sugestões para "" << prefixo << "":" << std::endl;
    for (const auto& palavra : resultados)
        std::cout << palavra << std::endl;

    return 0;
}
