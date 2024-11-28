
#ifndef PROBLEMA2_HPP
#define PROBLEMA2_HPP

#include <iostream>
#include <vector>
#include <algorithm>

// Estrutura do nó da árvore binária
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value);
};

// Declarações de funções
int calcularAltura(Node* root);
Node* inserirNo(Node* root, int valor);
Node* removerNo(Node* root, int valor);
void sugerirRotacoes(Node* root);
Node* rotacaoDireita(Node* root);
Node* rotacaoEsquerda(Node* root);
void encontrarCaminhoMaisLongo(Node* root, std::vector<int>& caminhoAtual, std::vector<int>& caminhoMaisLongo);
void mostrarCaminhoMaisLongo(Node* root);

#endif // PROBLEMA2_HPP
