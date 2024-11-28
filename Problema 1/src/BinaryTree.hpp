#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include "Node.hpp"

#include <bits/stdc++.h>

void prettyPrintTree(const std::shared_ptr<Node>& root);
void printTreeHelper(const std::shared_ptr<Node>& node, const std::string& prefix, bool isLeft);

class BinaryTree {
    public:
        BinaryTree();
        virtual void insert(const std::vector<int>& values);
        virtual void remove(const std::vector<int>& values);
        int search_pre_order(const std::shared_ptr<Node>& node, int target, std::vector<std::string>& order, const std::string& direction);
        int search_post_order(const std::shared_ptr<Node>& node, int target, std::vector<std::string>& order, const std::string& direction);
        int search_in_order(const std::shared_ptr<Node>& node, int target, std::vector<std::string>& order, const std::string& direction);
        void search_level_order(int target, int &visits, std::vector<std::string>& order);
        std::shared_ptr<Node> getRoot() const;
    protected:
        std::shared_ptr<Node> root;
        std::shared_ptr<Node> insert_recursive(std::shared_ptr<Node> node, int value);
        std::shared_ptr<Node> remove_recursive(std::shared_ptr<Node> node, int value);
        std::shared_ptr<Node> get_min_value_node(std::shared_ptr<Node> node);

};

#endif
