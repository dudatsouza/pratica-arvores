#include "BinaryTree.hpp"

// Função para imprimir a árvore no formato solicitado
void prettyPrintTree(const std::shared_ptr<Node>& root) {
    printTreeHelper(root, "", false);
    std::cout << std::endl;
}

// Função auxiliar recursiva para imprimir a árvore
void printTreeHelper(const std::shared_ptr<Node>& node, const std::string& prefix, bool isLeft) {
    if (node) {
        // se for o root colocar como (T) 
        if (prefix == "") {
            std::cout << "(T)────";
        }
        else { 
            // Imprime o valor do nó com o prefixo adequado
            std::cout << prefix;

            // Escolhe o conector com base se é filho esquerdo ou direito
            std::cout << (isLeft ? "(L)├────" : "(R)└────");
        }

        // Imprime o valor do nó
        std::cout << node->value << std::endl;

        // Recurso para os filhos (esquerdo e direito)
        // Ajusta o prefixo para manter o alinhamento
        printTreeHelper(node->left, prefix + (isLeft ? "   │     " : "      "), true);
        printTreeHelper(node->right, prefix + (isLeft ? "   │     " : "      "), false);
    }
}

BinaryTree::BinaryTree() : root(nullptr) {}

std::shared_ptr<Node> BinaryTree::getRoot() const {
    return root;
}

void BinaryTree::insert(const std::vector<int>& values) {
    for (int value : values) {
        std::cout << "Valor inserido: " << value << std::endl;
        root = insert_recursive(root, value);
        std::cout << "Árvore atual:" << std::endl;
        prettyPrintTree(root);
    }
}

void BinaryTree::remove(const std::vector<int>& values) {
    for (int value : values) {
        std::cout << "Valor removido: " << value << std::endl;
        root = remove_recursive(root, value);
        std::cout << "Árvore atual:" << std::endl;
        prettyPrintTree(root);
    }
}

std::shared_ptr<Node> BinaryTree::insert_recursive(std::shared_ptr<Node> node, int value) {
    if (!node) {
        return std::make_shared<Node>(value);
    }
    if (value < node->value) {
        node->left = insert_recursive(node->left, value);
    } else {
        node->right = insert_recursive(node->right, value);
    }
    return node;
}

std::shared_ptr<Node> BinaryTree::remove_recursive(std::shared_ptr<Node> node, int value) {
    if (!node) {
        std::cout << "Valor " << value << " não encontrado." << std::endl;
        return nullptr;
    }

    if (value < node->value) {
        node->left = remove_recursive(node->left, value);
    } else if (value > node->value) {
        node->right = remove_recursive(node->right, value);
    } else {
        // Caso 1: Nó folha
        if (!node->left && !node->right) {
            return nullptr;
        }
        // Caso 2: Nó com um filho
        if (!node->left) {
            return node->right;
        }
        if (!node->right) {
            return node->left;
        }
        // Caso 3: Nó com dois filhos
        auto predecessor = get_min_value_node(node->left);
        node->value = predecessor->value;
        node->left = remove_recursive(node->left, predecessor->value);
    }
    return node;
}

std::shared_ptr<Node> BinaryTree::get_min_value_node(std::shared_ptr<Node> node) {
    while (node && node->left) {
        node = node->left;
    }
    return node;
}

int BinaryTree::search_pre_order(const std::shared_ptr<Node>& node, int target, std::vector<std::string>& order, const std::string& direction) {
    if (!node) {
        order.push_back("nulo" + direction);
        return 1;
    }
    order.push_back(std::to_string(node->value));
    if (node->value == target) {
        return 1;
    }
    int left_visits = search_pre_order(node->left, target, order, "L" + std::to_string(node->value));
    int right_visits = search_pre_order(node->right, target, order, "R" + std::to_string(node->value));
    return 1 + left_visits + right_visits;
}

int BinaryTree::search_post_order(const std::shared_ptr<Node>& node, int target, std::vector<std::string>& order, const std::string& direction) {
    if (!node) {
        order.push_back("(nulo" + direction + ")");
        return 1;
    }
    int left_visits = search_post_order(node->left, target, order, "L" + std::to_string(node->value));
    int right_visits = search_post_order(node->right, target, order, "R" + std::to_string(node->value));
    order.push_back(std::to_string(node->value)); 
    if (node->value == target) {
        return 1 + left_visits + right_visits;
    }
    return 1 + left_visits + right_visits;
}

int BinaryTree::search_in_order(const std::shared_ptr<Node>& node, int target, std::vector<std::string>& order, const std::string& direction) {
    if (!node) {
        order.push_back("nulo" + direction);
        return 1;
    }
    int left_visits = search_in_order(node->left, target, order, "Left" + std::to_string(node->value));
    order.push_back(std::to_string(node->value));
    if (node->value == target) {
        return 1 + left_visits;
    }
    int right_visits = search_in_order(node->right, target, order, "Right" + std::to_string(node->value));
    return 1 + left_visits + right_visits;
}

void BinaryTree::search_level_order(int target, int &visits, std::vector<std::string>& order) {
    if (!root) {
        std::cout << "Largura: Visitas = 1, Ordem = nulo" << std::endl;
        return;
    }
    std::queue<std::pair<std::shared_ptr<Node>, std::string>> q;
    q.push({root, ""});
    visits = 0;

    while (!q.empty()) {
        auto [node, direction] = q.front();
        q.pop();
        visits++;

        if (!node) {
            order.push_back("nulo" + direction);
            continue;
        }

        order.push_back(std::to_string(node->value));
        if (node->value == target) {
            break;
        }
        q.push({node->left, "Left" + std::to_string(node->value)});
        q.push({node->right, "Right" + std::to_string(node->value)});
    }
}
