
#include "problema3.hpp"

// Função para inserir uma palavra na árvore
TreeNode* inserir(TreeNode* raiz, const std::string& palavra, const std::string& definicao) {
    if (!raiz) return new TreeNode(palavra, definicao);

    if (palavra < raiz->palavra)
        raiz->esquerda = inserir(raiz->esquerda, palavra, definicao);
    else if (palavra > raiz->palavra)
        raiz->direita = inserir(raiz->direita, palavra, definicao);

    return raiz;
}

// Função para coletar sugestões de palavras com base em um prefixo
void sugestoes(TreeNode* raiz, const std::string& prefixo, std::vector<std::string>& resultados) {
    if (!raiz) return;

    if (raiz->palavra.compare(0, prefixo.size(), prefixo) == 0)
        resultados.push_back(raiz->palavra);

    if (prefixo <= raiz->palavra)
        sugestoes(raiz->esquerda, prefixo, resultados);

    if (prefixo >= raiz->palavra)
        sugestoes(raiz->direita, prefixo, resultados);
}
