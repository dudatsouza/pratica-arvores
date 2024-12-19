#ifndef AVLTREE_HPP
#define AVLTREE_HPP

#include "problema3.hpp"
#include "Node.hpp"

class AVLTree : public Dictionary {
private:
    Node* root;

    int height(Node* node);
    int balanceFactor(Node* node);
    Node* rotateLeft(Node* node);
    Node* rotateRight(Node* node);
    Result insert(Node*& node, const std::string& key, const std::string& definition, int& interactions);
    Result search(Node* node, const std::string& key, std::string& definition, int& interactions);
    void collectSuggestions(Node* node, const std::string& prefix, std::vector<std::string>& suggestions, int& interactions);

public:
    AVLTree();
    ~AVLTree();
    Result insert(const std::string& key, const std::string& definition) override;
    Result search(const std::string& key, std::string& definition) override;
    Result autocomplete(const std::string& prefix, std::vector<std::string>& suggestions) override;

    Node* getRoot() { return root; }
};

#endif // AVLTREE_HPP
