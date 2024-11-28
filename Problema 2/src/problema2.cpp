
#include "problema2.hpp"

// Construtor do nó
Node::Node(int value) : data(value), left(nullptr), right(nullptr) {}

// Função para calcular a altura de uma subárvore
int calcularAltura(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + std::max(calcularAltura(root->left), calcularAltura(root->right));
}

// Inserção de um nó na árvore
Node* inserirNo(Node* root, int valor) {
    if (root == nullptr) {
        return new Node(valor);
    }
    if (valor < root->data) {
        root->left = inserirNo(root->left, valor);
    } else {
        root->right = inserirNo(root->right, valor);
    }
    return root;
}

// Função auxiliar para encontrar o nó mínimo
Node* encontrarMinimo(Node* root) {
    while (root && root->left) {
        root = root->left;
    }
    return root;
}

// Remoção de um nó da árvore
Node* removerNo(Node* root, int valor) {
    if (root == nullptr) {
        return nullptr;
    }
    if (valor < root->data) {
        root->left = removerNo(root->left, valor);
    } else if (valor > root->data) {
        root->right = removerNo(root->right, valor);
    } else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = encontrarMinimo(root->right);
        root->data = temp->data;
        root->right = removerNo(root->right, temp->data);
    }
    return root;
}

// Função para sugerir rotações
void sugerirRotacoes(Node* root) {
    if (root == nullptr) {
        return;
    }

    int alturaEsquerda = calcularAltura(root->left);
    int alturaDireita = calcularAltura(root->right);

    if (alturaEsquerda > alturaDireita + 1) {
        std::cout << "Subárvore desbalanceada detectada em " << root->data << ". Sugestão: Rotação à direita.\n";
    } else if (alturaDireita > alturaEsquerda + 1) {
        std::cout << "Subárvore desbalanceada detectada em " << root->data << ". Sugestão: Rotação à esquerda.\n";
    }

    sugerirRotacoes(root->left);
    sugerirRotacoes(root->right);
}

// Rotação à direita
Node* rotacaoDireita(Node* root) {
    Node* novaRaiz = root->left;
    root->left = novaRaiz->right;
    novaRaiz->right = root;
    return novaRaiz;
}

// Rotação à esquerda
Node* rotacaoEsquerda(Node* root) {
    Node* novaRaiz = root->right;
    root->right = novaRaiz->left;
    novaRaiz->left = root;
    return novaRaiz;
}

// Encontrar o caminho mais longo
void encontrarCaminhoMaisLongo(Node* root, std::vector<int>& caminhoAtual, std::vector<int>& caminhoMaisLongo) {
    if (root == nullptr) {
        if (caminhoAtual.size() > caminhoMaisLongo.size()) {
            caminhoMaisLongo = caminhoAtual;
        }
        return;
    }

    caminhoAtual.push_back(root->data);
    encontrarCaminhoMaisLongo(root->left, caminhoAtual, caminhoMaisLongo);
    encontrarCaminhoMaisLongo(root->right, caminhoAtual, caminhoMaisLongo);
    caminhoAtual.pop_back();
}

// Mostrar o caminho mais longo
void mostrarCaminhoMaisLongo(Node* root) {
    std::vector<int> caminhoAtual, caminhoMaisLongo;
    encontrarCaminhoMaisLongo(root, caminhoAtual, caminhoMaisLongo);

    std::cout << "Caminho mais longo: ";
    for (int valor : caminhoMaisLongo) {
        std::cout << valor << " ";
    }
    std::cout << "\n";
}
