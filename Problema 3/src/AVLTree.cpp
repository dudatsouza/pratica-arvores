#include "AVLTree.hpp"
#include <chrono>

AVLTree::AVLTree() : root(nullptr) {}

AVLTree::~AVLTree() {}

int AVLTree::height(Node* node) {
    return node ? node->height : 0;
}

int AVLTree::balanceFactor(Node* node) {
    return node ? height(node->left) - height(node->right) : 0;
}

Node* AVLTree::rotateLeft(Node* node) {
    Node* newRoot = node->right;
    node->right = newRoot->left;
    newRoot->left = node;

    node->height = 1 + std::max(height(node->left), height(node->right));
    newRoot->height = 1 + std::max(height(newRoot->left), height(newRoot->right));

    return newRoot;
}

Node* AVLTree::rotateRight(Node* node) {
    Node* newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = node;

    node->height = 1 + std::max(height(node->left), height(node->right));
    newRoot->height = 1 + std::max(height(newRoot->left), height(newRoot->right));

    return newRoot;
}

Result AVLTree::insert(Node*& node, const std::string& key, const std::string& definition, int& interactions) {
    interactions++;
    if (!node) {
        node = new Node(key, definition);
        return {0, interactions};
    }

    if (key < node->key) {
        insert(node->left, key, definition, interactions);
    } else if (key > node->key) {
        insert(node->right, key, definition, interactions);
    } else {
        return {0, interactions}; // Palavra já existe
    }

    node->height = 1 + std::max(height(node->left), height(node->right));

    int balance = balanceFactor(node);

    // Balanceamento
    if (balance > 1 && key < node->left->key) {
        node = rotateRight(node);  // Ajuste: atualiza o ponteiro do nó
    } else if (balance < -1 && key > node->right->key) {
        node = rotateLeft(node);  // Ajuste: atualiza o ponteiro do nó
    } else if (balance > 1 && key > node->left->key) {
        node->left = rotateLeft(node->left);
        node = rotateRight(node);
    } else if (balance < -1 && key < node->right->key) {
        node->right = rotateRight(node->right);
        node = rotateLeft(node);
    }

    return {0, interactions};
}

Result AVLTree::insert(const std::string& key, const std::string& definition) {
    int interactions = 0;
    auto start = std::chrono::high_resolution_clock::now();
    insert(root, key, definition, interactions);  // Chama a função auxiliar
    auto end = std::chrono::high_resolution_clock::now();
    return {std::chrono::duration<double, std::milli>(end - start).count(), interactions};
}

Result AVLTree::search(Node* node, const std::string& key, std::string& definition, int& interactions) {
    interactions++;
    if (!node) return {0, interactions};

    if (key == node->key) {
        definition = node->definition;
        return {0, interactions};
    }

    if (key < node->key)
        return search(node->left, key, definition, interactions);
    else
        return search(node->right, key, definition, interactions);
}

Result AVLTree::search(const std::string& key, std::string& definition) {
    int interactions = 0;
    auto start = std::chrono::high_resolution_clock::now();
    Result result = search(root, key, definition, interactions);
    auto end = std::chrono::high_resolution_clock::now();
    result.timeMs = std::chrono::duration<double, std::milli>(end - start).count();
    return result;
}

void AVLTree::collectSuggestions(Node* node, const std::string& prefix, std::vector<std::string>& suggestions, int& interactions) {
    if (!node) return;

    interactions++;
    if (node->key.find(prefix) == 0)
        suggestions.push_back(node->key);

    collectSuggestions(node->left, prefix, suggestions, interactions);
    collectSuggestions(node->right, prefix, suggestions, interactions);
}

Result AVLTree::autocomplete(const std::string& prefix, std::vector<std::string>& suggestions) {
    int interactions = 0;
    auto start = std::chrono::high_resolution_clock::now();
    collectSuggestions(root, prefix, suggestions, interactions);
    auto end = std::chrono::high_resolution_clock::now();
    return {std::chrono::duration<double, std::milli>(end - start).count(), interactions};
}
