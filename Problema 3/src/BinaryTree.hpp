#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

#include "problema3.hpp"
#include "Node.hpp"

class BinaryTree : public Dictionary {
private:
    Node* root;
    Result insert(Node*& node, const std::string& key, const std::string& definition, int& interactions);
    Result search(Node* node, const std::string& key, std::string& definition, int& interactions);
    void collectSuggestions(Node* node, const std::string& prefix, std::vector<std::string>& suggestions, int& interactions);

public:
    BinaryTree();
    ~BinaryTree();
    Result insert(const std::string& key, const std::string& definition) override;
    Result search(const std::string& key, std::string& definition) override;
    Result autocomplete(const std::string& prefix, std::vector<std::string>& suggestions) override;
    Node* getRoot() { return root; }
};

#endif // BINARYTREE_HPP
