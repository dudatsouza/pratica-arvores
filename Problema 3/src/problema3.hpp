
#ifndef PROBLEMA3_HPP
#define PROBLEMA3_HPP

#include <string>
#include <vector>

// Estrutura de um nó da árvore
struct TreeNode {
    std::string palavra;
    std::string definicao;
    TreeNode* esquerda;
    TreeNode* direita;

    TreeNode(std::string p, std::string d) : palavra(p), definicao(d), esquerda(nullptr), direita(nullptr) {}
};

// Funções para manipulação da árvore
TreeNode* inserir(TreeNode* raiz, const std::string& palavra, const std::string& definicao);
void sugestoes(TreeNode* raiz, const std::string& prefixo, std::vector<std::string>& resultados);

#endif // PROBLEMA3_HPP
