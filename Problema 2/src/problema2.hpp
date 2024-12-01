
#ifndef PROBLEMA2_HPP
#define PROBLEMA2_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <queue>
#include <cmath>
#include <fstream>


// Estrutura do nó da árvore binária
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value);
};

// Declarações de funções
int calcularAltura(Node* root);
std::vector<int> multiplasEntradas();
Node* inserirNo(Node* root, int valor);
Node* removerNo(Node* root, int valor);
void sugerirRotacoes(Node*& root, int& aux, bool balancear, bool printar);
Node* rotacaoDireita(Node* root);
Node* rotacaoEsquerda(Node* root);
void encontrarCaminhoMaisLongo(Node* root, std::vector<int>& caminhoAtual, std::vector<int>& caminhoMaisLongo);
void mostrarCaminhoMaisLongo(Node* root);
void analiseDeCrescimento();
double analisando(Node* arvoreTorta, Node* arvoreQseEquilibrada);
void prettyPrintTree(Node* root);
void printTreeHelper(Node* node, const std::string& prefix, bool isLeft);
void salvarArquivo(std::string nomeArquivo, std::vector<std::pair<int, double>> analise);

#endif // PROBLEMA2_HPP
