#include "BinaryTree.hpp"
#include <chrono>

BinaryTree::BinaryTree() : root(nullptr) {}

BinaryTree::~BinaryTree() {}

Result BinaryTree::insert(Node*& node, const std::string& key, const std::string& definition, int& interactions) {
    interactions++;
    if (!node) {
        node = new Node(key, definition);
        return {0, interactions};
    }

    if (key < node->key)
        return insert(node->left, key, definition, interactions);
    else if (key > node->key)
        return insert(node->right, key, definition, interactions);

    return {0, interactions}; // Word already exists
}

Result BinaryTree::insert(const std::string& key, const std::string& definition) {
    int interactions = 0;
    auto start = std::chrono::high_resolution_clock::now();
    Result result = insert(root, key, definition, interactions);
    auto end = std::chrono::high_resolution_clock::now();
    result.timeMs = std::chrono::duration<double, std::milli>(end - start).count();
    return result;
}

Result BinaryTree::search(Node* node, const std::string& key, std::string& definition, int& interactions) {
    interactions++;
    if (!node)
        return {0, interactions};

    if (key == node->key) {
        definition = node->definition;
        return {0, interactions};
    }

    if (key < node->key)
        return search(node->left, key, definition, interactions);
    else
        return search(node->right, key, definition, interactions);
}

Result BinaryTree::search(const std::string& key, std::string& definition) {
    int interactions = 0;
    auto start = std::chrono::high_resolution_clock::now();
    Result result = search(root, key, definition, interactions);
    auto end = std::chrono::high_resolution_clock::now();
    result.timeMs = std::chrono::duration<double, std::milli>(end - start).count();
    return result;
}

void BinaryTree::collectSuggestions(Node* node, const std::string& prefix, std::vector<std::string>& suggestions, int& interactions) {
    if (!node)
        return;

    interactions++;
    if (node->key.find(prefix) == 0)
        suggestions.push_back(node->key);

    collectSuggestions(node->left, prefix, suggestions, interactions);
    collectSuggestions(node->right, prefix, suggestions, interactions);
}

Result BinaryTree::autocomplete(const std::string& prefix, std::vector<std::string>& suggestions) {
    int interactions = 0;
    auto start = std::chrono::high_resolution_clock::now();
    collectSuggestions(root, prefix, suggestions, interactions);
    auto end = std::chrono::high_resolution_clock::now();
    return {std::chrono::duration<double, std::milli>(end - start).count(), interactions};
}
