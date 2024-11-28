#include "BinaryTree.hpp"
#include "AVLTree.hpp"


AVLTree::AVLTree() : BinaryTree(), root(nullptr), rotationCount(0) {}

void AVLTree::insert(const std::vector<int>& values) {
    for (int value : values) {
        std::cout << "Valor inserido: " << value << std::endl;
        resetRotationCount(); // Resetar contador antes de inserir
        root = insert_avl_recursive(root, value);
        if (getRotationCount() != 0) 
            std::cout << "Número de rotações realizadas: " << getRotationCount() << std::endl;
        std::cout << "Árvore atual:" << std::endl;
        prettyPrintTree(root);
    }
}

std::shared_ptr<Node> AVLTree::insert_avl_recursive(std::shared_ptr<Node> node, int value) {
    if (!node) {
        return std::make_shared<Node>(value);
    }

    if (value < node->value) {
        node->left = insert_avl_recursive(node->left, value);
    } else {
        node->right = insert_avl_recursive(node->right, value);
    }

    int balance = get_balance(node);

    // Rotação Simples Direita
    if (balance > 1 && value < node->left->value) {
        std::cout << "Rotação Simples Direita do nó " << node->value << std::endl;
        return rotate_right(node);
    }

    // Rotação Simples Esquerda
    if (balance < -1 && value > node->right->value) {
        std::cout << "Rotação Simples Esquerda do nó " << node->value << std::endl;
        return rotate_left(node);
    }

    // Rotação Dupla Esquerda-Direita
    if (balance > 1 && value > node->left->value) {
        node->left = rotate_left(node->left);
        std::cout << "Rotação Dupla Esquerda-Direita do nó " << node->value << std::endl;
        return rotate_right(node);
    }

    // Rotação Dupla Direita-Esquerda
    if (balance < -1 && value < node->right->value) {
        node->right = rotate_right(node->right);
        std::cout << "Rotação Dupla Direita-Esquerda do nó " << node->value << std::endl;
        return rotate_left(node);
    }

    return node;
}

void AVLTree::remove(const std::vector<int>& values) {
    for (int value : values) {
        std::cout << "Removendo valor (AVL): " << value << std::endl;
        resetRotationCount(); // Resetar contador antes de remover
        root = remove_avl_recursive(root, value);
        if (getRotationCount() != 0) 
            std::cout << "Número de rotações realizadas: " << getRotationCount() << std::endl;
        std::cout << "Árvore atual:" << std::endl;
        prettyPrintTree(root);
    }
}

std::shared_ptr<Node> AVLTree::remove_avl_recursive(std::shared_ptr<Node> node, int value) {
    if (!node) return nullptr;

    if (value < node->value) {
        node->left = remove_avl_recursive(node->left, value);
    } else if (value > node->value) {
        node->right = remove_avl_recursive(node->right, value);
    } else {
        // Nó encontrado
        if (!node->left && !node->right) return nullptr;
        if (!node->left) return node->right;
        if (!node->right) return node->left;

        auto predecessor = get_min_value_node(node->right);
        node->value = predecessor->value;
        node->right = remove_avl_recursive(node->right, predecessor->value);
    }

    // Balancear árvore após remoção
    int balance = get_balance(node);

    if (balance > 1 && get_balance(node->left) >= 0) {
        std::cout << "Rotação Simples Direita do nó " << node->value << std::endl;
        return rotate_right(node);
    }

    if (balance < -1 && get_balance(node->right) <= 0) {
        std::cout << "Rotação Simples Esquerda do nó " << node->value << std::endl;
        return rotate_left(node);
    }

    if (balance > 1 && get_balance(node->left) < 0) {
        node->left = rotate_left(node->left);
        std::cout << "Rotação Dupla Esquerda-Direita do nó " << node->value << std::endl;
        return rotate_right(node);
    }

    if (balance < -1 && get_balance(node->right) > 0) {
        node->right = rotate_right(node->right);
        std::cout << "Rotação Dupla Direita-Esquerda do nó " << node->value << std::endl;
        return rotate_left(node);
    }

    return node;
}

std::shared_ptr<Node> AVLTree::rotate_left(std::shared_ptr<Node> z) {
    std::shared_ptr<Node> y = z->right;
    std::shared_ptr<Node> T2 = y->left;

    y->left = z;
    z->right = T2;

    rotationCount++; // Incrementa o contador de rotações
    return y;
}

std::shared_ptr<Node> AVLTree::rotate_right(std::shared_ptr<Node> z) {
    std::shared_ptr<Node> y = z->left;
    std::shared_ptr<Node> T3 = y->right;

    y->right = z;
    z->left = T3;

    rotationCount++; // Incrementa o contador de rotações
    return y;
}

std::shared_ptr<Node> AVLTree::getRoot() const {
    return root;
}

std::shared_ptr<Node> AVLTree::get_min_value_node(std::shared_ptr<Node> node) {
    std::shared_ptr<Node> current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

int AVLTree::get_balance(const std::shared_ptr<Node>& node) {
    if (!node) {
        return 0;
    }
    return height(node->left) - height(node->right);
}

int AVLTree::height(const std::shared_ptr<Node>& node) {
    if (!node) {
        return 0;
    }
    return 1 + std::max(height(node->left), height(node->right));
}

std::shared_ptr<Node> AVLTree::copyNode(const std::shared_ptr<Node>& node) const {
    if (!node) return nullptr;

    auto newNode = std::make_shared<Node>(node->value);
    newNode->left = copyNode(node->left);  // Chamadas recursivas também funcionarão
    newNode->right = copyNode(node->right);
    return newNode;
}

AVLTree AVLTree::copy() const {
    AVLTree newTree;
    newTree.root = copyNode(this->root);
    return newTree;
}
