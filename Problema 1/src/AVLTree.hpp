#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

#include "BinaryTree.hpp"
#include "Node.hpp"

class AVLTree : public BinaryTree {
public:
    AVLTree();
    void insert(const std::vector<int>& values);
    void remove(const std::vector<int>& values) ;

    int getRotationCount() const { return rotationCount; }
    void resetRotationCount() { rotationCount = 0; }
    std::shared_ptr<Node> getRoot() const;
    std::shared_ptr<Node> copyNode(const std::shared_ptr<Node>& node) const;
    AVLTree copy() const;

private:
    std::shared_ptr<Node> root;
    int rotationCount;
    std::shared_ptr<Node> insert_avl_recursive(std::shared_ptr<Node> node, int value);
    std::shared_ptr<Node> remove_avl_recursive(std::shared_ptr<Node> node, int value);
    std::shared_ptr<Node> rotate_left(std::shared_ptr<Node> z);
    std::shared_ptr<Node> rotate_right(std::shared_ptr<Node> z);
    int get_balance(const std::shared_ptr<Node>& node);
    int height(const std::shared_ptr<Node>& node);

    std::shared_ptr<Node> get_min_value_node(std::shared_ptr<Node> node);
};

#endif
