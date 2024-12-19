#ifndef REDBLACKTREE_HPP
#define REDBLACKTREE_HPP

#include "problema3.hpp"
#include "Node.hpp"

enum Color { RED, BLACK };

struct RedBlackNode : public Node {
    Color color;
    RedBlackNode(const std::string& k, const std::string& d, Color c = RED)
        : Node(k, d), color(c) {}
};

class RedBlackTree : public Dictionary {
private:
    RedBlackNode* root;

    // Métodos auxiliares
    void rotateLeft(RedBlackNode*& node);
    void rotateRight(RedBlackNode*& node);
    void fixInsert(RedBlackNode*& node);

    // Inserção recursiva
    Result insert(RedBlackNode*& root, RedBlackNode*& node, int& interactions);

    // Busca e autocompletar
    Result search(RedBlackNode* node, const std::string& key, std::string& definition, int& interactions);
    void collectSuggestions(RedBlackNode* node, const std::string& prefix, std::vector<std::string>& suggestions, int& interactions);

public:
    RedBlackTree();
    ~RedBlackTree();

    // Métodos principais
    Result insert(const std::string& key, const std::string& definition) override;
    Result search(const std::string& key, std::string& definition) override;
    Result autocomplete(const std::string& prefix, std::vector<std::string>& suggestions) override;

    Node* getRoot() { return root; }
};

#endif // REDBLACKTREE_HPP
