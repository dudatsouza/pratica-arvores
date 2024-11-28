
#include "problema2.hpp"

// Construtor do nó
Node::Node(int value) : data(value), left(nullptr), right(nullptr) {}

// Função para calcular a altura de uma subárvore
int calcularAltura(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    return std::max(calcularAltura(root->left), calcularAltura(root->right)) + 1;
}

std::vector<int> multiplasEntradas() {
    std::vector<int> treeValuesBinary;
    std::cout << "Digite os valores separados por vírgula (e pressione Enter): ";
    std::string line;
    std::getline(std::cin, line); // Captura a linha completa com os números
    treeValuesBinary.clear(); // Limpa o vetor de valores
    size_t pos = 0;
    try {
        // Enquanto encontrar vírgulas, processa os valores
        while ((pos = line.find(',')) != std::string::npos) {
            std::string token = line.substr(0, pos); // Extrai o número como string
            token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end()); // Remove espaços
            if (!token.empty()) { // Verifica se o token não está vazio antes de converter
                treeValuesBinary.push_back(std::stoi(token)); // Converte para inteiro e adiciona ao vetor
            }
            line.erase(0, pos + 1); // Remove o número processado e a vírgula
        }

        // Adicionar o último valor (ou único se não houver vírgulas)
        line.erase(std::remove_if(line.begin(), line.end(), ::isspace), line.end()); // Remove espaços
        if (!line.empty()) { // Verifica se a string restante não está vazia
            treeValuesBinary.push_back(std::stoi(line)); // Converte o último valor e adiciona ao vetor
        }
    } catch (const std::invalid_argument& e) {
        std::cout << "Erro: Entrada inválida. Certifique-se de que os valores sejam números separados por vírgula." << std::endl;
        treeValuesBinary.clear(); // Limpa o vetor, já que houve erro na entrada
        return {}; // Retorna ao menu sem prosseguir com a operação
    } catch (const std::out_of_range& e) {
        std::cout << "Erro: Um dos números está fora do intervalo permitido." << std::endl;
        treeValuesBinary.clear(); // Limpa o vetor, já que houve erro na entrada
        return {}; // Retorna ao menu sem prosseguir com a operação
    }

    return treeValuesBinary;
}

// Inserção de um nó na árvore
Node* inserirNo(Node* root, int valor) {
    if (root == nullptr) {
        return new Node(valor);
    }
    if (valor < root->data) {
        root->left = inserirNo(root->left, valor);
    } else {
        root->right = inserirNo(root->right, valor);
    }

    return root;
}

// Função auxiliar para encontrar o nó mínimo
Node* encontrarMinimo(Node* root) {
    while (root && root->left) {
        root = root->left;
    }
    return root;
}

// Remoção de um nó da árvore
Node* removerNo(Node* root, int valor) {
    if (root == nullptr) {
        return nullptr;
    }

    std::cout << "Removendo " << valor << "...\n";
    if (valor < root->data) {
        root->left = removerNo(root->left, valor);
    } else if (valor > root->data) {
        root->right = removerNo(root->right, valor);
    } else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = encontrarMinimo(root->right);
        root->data = temp->data;
        root->right = removerNo(root->right, temp->data);
    }

    int altura = calcularAltura(root);

    std::cout << "Altura atual: " << altura << "\n";
    return root;
}

// Função para sugerir rotações
void sugerirRotacoes(Node* root) {
    if (root == nullptr) {
        return;
    }

    int alturaEsquerda = calcularAltura(root->left);
    int alturaDireita = calcularAltura(root->right);

    if (alturaEsquerda > alturaDireita + 1) {
        std::cout << "Subárvore desbalanceada detectada no nó " << root->data << ". Sugestão: Rotação à direita.\n";
    } else if (alturaDireita > alturaEsquerda + 1) {
        std::cout << "Subárvore desbalanceada detectada no nó " << root->data << ". Sugestão: Rotação à esquerda.\n";
    }

    sugerirRotacoes(root->left);
    sugerirRotacoes(root->right);
}

// Rotação à direita
Node* rotacaoDireita(Node* root) {
    Node* novaRaiz = root->left;
    root->left = novaRaiz->right;
    novaRaiz->right = root;
    return novaRaiz;
}

// Rotação à esquerda
Node* rotacaoEsquerda(Node* root) {
    Node* novaRaiz = root->right;
    root->right = novaRaiz->left;
    novaRaiz->left = root;
    return novaRaiz;
}

// Encontrar o caminho mais longo
void encontrarCaminhoMaisLongo(Node* root, std::vector<int>& caminhoAtual, std::vector<int>& caminhoMaisLongo) {
    if (root == nullptr) {
        if (caminhoAtual.size() > caminhoMaisLongo.size()) {
            caminhoMaisLongo = caminhoAtual;
        }
        return;
    }

    caminhoAtual.push_back(root->data);
    encontrarCaminhoMaisLongo(root->left, caminhoAtual, caminhoMaisLongo);
    encontrarCaminhoMaisLongo(root->right, caminhoAtual, caminhoMaisLongo);
    caminhoAtual.pop_back();
}

// Mostrar o caminho mais longo
void mostrarCaminhoMaisLongo(Node* root) {
    std::vector<int> caminhoAtual, caminhoMaisLongo;
    encontrarCaminhoMaisLongo(root, caminhoAtual, caminhoMaisLongo);

    std::cout << "Caminho mais longo: ";
    for (int valor : caminhoMaisLongo) {
        std::cout << valor << " ";
    }
    std::cout << "\n";
}

std::vector<int> gerarArvoreDesbalanceada(int m) {
    std::vector<int> resultado;

    // Determinar os limites para desbalanceamento em m/3 níveis
    int limiteDesbalanceado = m / 2.5;

    // Adicionar os valores da subárvore mais profunda (lado esquerdo)
    for (int i = limiteDesbalanceado; i >= 1; --i) {
        resultado.push_back(i);
    }

    // Adicionar os valores restantes da parte "central"
    for (int i = limiteDesbalanceado + 1; i <= 2 * limiteDesbalanceado; ++i) {
        resultado.push_back(i);
    }

    // Adicionar os valores restantes da subárvore mais rasa (lado direito)
    for (int i = 2 * limiteDesbalanceado + 1; i <= m; ++i) {
        resultado.push_back(i);
    }

    return resultado;
}

std::vector<int> gerarArvoreTorta(int m) {
    // gerar vetor de tamanho m, arvore torta, onde os valores são inseridos em ordem crescente

    std::vector<int> vetor;
    for (int i = 1; i <= m; i++) {
        vetor.push_back(i);
    }

    return vetor;
}

void analiseDeCrescimento() {
    std::cout << "Para uma melhor análise de crescimento, vamos fazer a analise com vários tamanho de árvores, de 3 até 100.\n";

    std::vector<std::pair<int, double>> analise;

    for (int m = 3; m <= 1000; m++) {
        std::vector<int> insercoesTortas = gerarArvoreTorta(m);
        std::vector<int> insercoesEquilibradas = gerarArvoreDesbalanceada(m);
        
        double depreciacao = analisando(insercoesTortas, insercoesEquilibradas);

        analise.push_back(std::make_pair(m, depreciacao));
    }

    int media = 0;

    std::cout << "\nAnálise de crescimento finalizada.\n";
    std::cout << "Depreciação de altura para diferentes tamanhos de árvores:\n";
    for (auto& p : analise) {
        media += p.second;
        std::cout << "Tamanho da árvore: " << p.first << ", Depreciação: " << p.second << "%\n";
    }

    std::cout << "\nMédia de depreciação: " << (double)media / analise.size() << "%\n";
}


// Função para análise de crescimento
double analisando(std::vector<int> insercoesTortas, std::vector<int> insercoesEquilibradas) {
    Node* arvoreTorta = nullptr;
    Node* arvoreEquilibrada = nullptr;

    std::cout << "\nInserindo na árvore torta:\n";
    for (int valor : insercoesTortas) {
        arvoreTorta = inserirNo(arvoreTorta, valor);
        std::cout << "Após inserir " << valor << ": Altura = " << calcularAltura(arvoreTorta) << "\n";
    }

    std::cout << "\nInserindo na árvore equilibrada:\n";
    for (int valor : insercoesEquilibradas) {
        arvoreEquilibrada = inserirNo(arvoreEquilibrada, valor);
        std::cout << "Após inserir " << valor << ": Altura = " << calcularAltura(arvoreEquilibrada) << "\n";
    }

    int alturaTorta = calcularAltura(arvoreTorta);
    int alturaEquilibrada = calcularAltura(arvoreEquilibrada);

    std::cout << "\nComparação de alturas:\n";
    std::cout << "Árvore torta: Altura final = " << alturaTorta << "\n";
    std::cout << "Árvore equilibrada: Altura final = " << alturaEquilibrada << "\n";

    double depreciacao = ((double)(alturaTorta - alturaEquilibrada) / alturaTorta) * 100.0;
    std::cout << "Depreciação entre as alturas: " << depreciacao << "%\n";

    return depreciacao;
}


// Função para imprimir a árvore no formato solicitado
void prettyPrintTree(Node* root) {
    printTreeHelper(root, "", false);
    std::cout << std::endl;
}

// Função auxiliar recursiva para imprimir a árvore
void printTreeHelper(Node* node, const std::string& prefix, bool isLeft) {
    if (node != nullptr) {
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
        std::cout << node->data << std::endl;

        // Recurso para os filhos (esquerdo e direito)
        // Ajusta o prefixo para manter o alinhamento
        printTreeHelper(node->left, prefix + (isLeft ? "   │     " : "      "), true);
        printTreeHelper(node->right, prefix + (isLeft ? "   │     " : "      "), false);
    }
}