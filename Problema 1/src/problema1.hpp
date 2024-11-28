
#ifndef PROBLEMA1_HPP
#define PROBLEMA1_HPP

#include "BinaryTree.hpp"
#include "AVLTree.hpp"

#include <bits/stdc++.h>

class Problema1 {
    public:
        Problema1() {};
        std::vector<int> arvore1 = {88, 22, 45, 33, 22, 90, 27, 59, 13};
        std::vector<int> arvore2 = {65, 47, 21, 11, 72, 23, 5, 34, 28};
        std::vector<int> arvore3 = {65, 34, 89, 23, 60, 54, 81, 95, 39};
        std::vector<int> arvore4 = {15, 10, 20, 5, 12, 18, 25, 98, 44};

        BinaryTree treeBinary1, treeBinary2, treeBinary3, treeBinary4, treeBinary;
        std::vector<BinaryTree*> treesBinary = {&treeBinary1, &treeBinary2, &treeBinary3, &treeBinary4};

        AVLTree treeAVL1, treeAVL2, treeAVL3, treeAVL4, treeAVL;
        std::vector<AVLTree*> treesAVL = {&treeAVL1, &treeAVL2, &treeAVL3, &treeAVL4};

        std::vector<int> treeValuesBinary;
        std::vector<int> treeValuesAVL;

        int menu();
        bool verificarArvoresCriadas(int choice);
        void inserirValoresProblema();
        void removerValoresProblema();
        void buscarElementosProblema();
        void inserirValores();
        void removerValores();
        void buscarElemento();
        void desafioAdicional();
        void printordem (std::vector<std::string> order);
        void buscas(BinaryTree *tree, int target);
        void criandoArvoresAVLProblema();
        void criandoArvoreAVL();
        std::vector<std::vector<int>> gerarSubconjuntos(const std::vector<int>& valores);
        std::pair<std::vector<int>, int> analisarRotacoesArvore(AVLTree arvore, const std::vector<int>& valores);
};

#endif
