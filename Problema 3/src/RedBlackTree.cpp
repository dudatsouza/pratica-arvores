#include "RedBlackTree.hpp"
#include <chrono>

RedBlackTree::RedBlackTree() : root(nullptr) {}

RedBlackTree::~RedBlackTree() {}

void RedBlackTree::rotateLeft(RedBlackNode*& node) {
    RedBlackNode* rightChild = static_cast<RedBlackNode*>(node->right);
    node->right = rightChild->left;

    if (rightChild->left != nullptr) {
        rightChild->left->parent = node;
    }

    rightChild->parent = node->parent;

    if (node->parent == nullptr) {
        root = rightChild;
    } else if (node == node->parent->left) {
        node->parent->left = rightChild;
    } else {
        node->parent->right = rightChild;
    }

    rightChild->left = node;
    node->parent = rightChild;
}

void RedBlackTree::rotateRight(RedBlackNode*& node) {
    RedBlackNode* leftChild = static_cast<RedBlackNode*>(node->left);
    node->left = leftChild->right;

    if (leftChild->right != nullptr) {
        leftChild->right->parent = node;
    }

    leftChild->parent = node->parent;

    if (node->parent == nullptr) {
        root = leftChild;
    } else if (node == node->parent->right) {
        node->parent->right = leftChild;
    } else {
        node->parent->left = leftChild;
    }

    leftChild->right = node;
    node->parent = leftChild;
}

void RedBlackTree::fixInsert(RedBlackNode*& node) {
    RedBlackNode* parent = nullptr;
    RedBlackNode* grandparent = nullptr;

    while (node != root && node->color == RED && static_cast<RedBlackNode*>(node->parent)->color == RED) {
        parent = static_cast<RedBlackNode*>(node->parent);
        grandparent = static_cast<RedBlackNode*>(parent->parent);

        if (parent == grandparent->left) {
            RedBlackNode* uncle = static_cast<RedBlackNode*>(grandparent->right);
            if (uncle != nullptr && uncle->color == RED) {
                grandparent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                node = grandparent;
            } else {
                if (node == parent->right) {
                    rotateLeft(parent);
                    node = parent;
                    parent = static_cast<RedBlackNode*>(node->parent);
                }
                rotateRight(grandparent);
                std::swap(parent->color, grandparent->color);
                node = parent;
            }
        } else {
            RedBlackNode* uncle = static_cast<RedBlackNode*>(grandparent->left);
            if (uncle != nullptr && uncle->color == RED) {
                grandparent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                node = grandparent;
            } else {
                if (node == parent->left) {
                    rotateRight(parent);
                    node = parent;
                    parent = static_cast<RedBlackNode*>(node->parent);
                }
                rotateLeft(grandparent);
                std::swap(parent->color, grandparent->color);
                node = parent;
            }
        }
    }
    root->color = BLACK;
}

Result RedBlackTree::insert(RedBlackNode*& root, RedBlackNode*& node, int& interactions) {
    interactions++;
    if (root == nullptr) {
        root = node;
        return {0, interactions};
    }

    if (node->key < root->key) {
        RedBlackNode* leftChild = static_cast<RedBlackNode*>(root->left); // Cast explícito
        insert(leftChild, node, interactions);
        root->left = leftChild;
        root->left->parent = root;
    } else if (node->key > root->key) {
        RedBlackNode* rightChild = static_cast<RedBlackNode*>(root->right); // Cast explícito
        insert(rightChild, node, interactions);
        root->right = rightChild;
        root->right->parent = root;
    }

    return {0, interactions};
}

Result RedBlackTree::insert(const std::string& key, const std::string& definition) {
    int interactions = 0;
    auto start = std::chrono::high_resolution_clock::now();

    RedBlackNode* newNode = new RedBlackNode(key, definition);
    Result res = insert(root, newNode, interactions);
    fixInsert(newNode);

    auto end = std::chrono::high_resolution_clock::now();
    return {std::chrono::duration<double, std::milli>(end - start).count(), interactions};
}

Result RedBlackTree::search(RedBlackNode* node, const std::string& key, std::string& definition, int& interactions) {
    interactions++;
    if (node == nullptr) {
        return {0, interactions};
    }

    if (key == node->key) {
        definition = node->definition;
        return {0, interactions};
    }

    if (key < node->key) {
        return search(static_cast<RedBlackNode*>(node->left), key, definition, interactions);
    } else {
        return search(static_cast<RedBlackNode*>(node->right), key, definition, interactions);
    }
}

Result RedBlackTree::search(const std::string& key, std::string& definition) {
    int interactions = 0;
    auto start = std::chrono::high_resolution_clock::now();
    Result res = search(root, key, definition, interactions);
    auto end = std::chrono::high_resolution_clock::now();
    res.timeMs = std::chrono::duration<double, std::milli>(end - start).count();
    return res;
}

void RedBlackTree::collectSuggestions(RedBlackNode* node, const std::string& prefix, std::vector<std::string>& suggestions, int& interactions) {
    if (!node) return;

    interactions++;
    if (node->key.find(prefix) == 0) {
        suggestions.push_back(node->key);
    }

    collectSuggestions(static_cast<RedBlackNode*>(node->left), prefix, suggestions, interactions);
    collectSuggestions(static_cast<RedBlackNode*>(node->right), prefix, suggestions, interactions);
}


Result RedBlackTree::autocomplete(const std::string& prefix, std::vector<std::string>& suggestions) {
    int interactions = 0;
    auto start = std::chrono::high_resolution_clock::now();
    collectSuggestions(root, prefix, suggestions, interactions);
    auto end = std::chrono::high_resolution_clock::now();
    return {std::chrono::duration<double, std::milli>(end - start).count(), interactions};
}
