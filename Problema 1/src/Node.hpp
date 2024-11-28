#ifndef NODE_HPP
#define NODE_HPP

#include <bits/stdc++.h>

struct Node {
    int value;
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;
    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

#endif