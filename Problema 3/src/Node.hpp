#ifndef NODE_HPP
#define NODE_HPP

#include <string>

struct Node {
    std::string key;
    std::string definition;
    Node* left;
    Node* right;
    Node* parent; // Adicionando ponteiro para o pai
    int height;

    Node(const std::string& k, const std::string& d)
        : key(k), definition(d), left(nullptr), right(nullptr), parent(nullptr), height(1) {}
};

#endif // NODE_HPP
