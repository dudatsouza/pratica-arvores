#include "problema2.hpp"

// Construtor do nó
Node::Node(int valor) {
    data = valor;
    left = nullptr;
    right = nullptr;
}

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

    return root;
}

void sugerirRotacoes(Node*& root, int& aux, bool balancear, bool printar) {
    if (root == nullptr) {
        return;
    }

    int alturaEsquerda = calcularAltura(root->left);
    int alturaDireita = calcularAltura(root->right);
    int diferencaAltura = alturaEsquerda - alturaDireita;

    // Tratar diferença maior que 2 (árvore desbalanceada severamente)
    if (diferencaAltura > 2) {
        if (printar) {
            std::cout << "Arvore analisada: \n";
            prettyPrintTree(root);
            std::cout << "Subárvore severamente desbalanceada detectada no nó " << root->data 
                      << ". Diferença de altura: " << diferencaAltura 
                      << ". Sugestão: Rotação(s) para balancear.\n\n";
        }
        
        while (diferencaAltura > 1) {
            // Verifica qual caso aplicar (rotação à direita ou esquerda-direita)
            if (calcularAltura(root->left->left) >= calcularAltura(root->left->right)) {
                if (balancear) {
                    if (printar) {
                        std::cout << "Rotação à direita sugerida no nó " << root->data << ".\n";
                    }
                    root = rotacaoDireita(root);
                    if (printar) {
                        std::cout << "Árvore após rotação à direita: \n";
                        prettyPrintTree(root);
                    }
                }
            } else {
                if (balancear) {
                    if (printar) {
                        std::cout << "Rotação esquerda-direita sugerida no nó " << root->data << ".\n";
                    }
                    root->left = rotacaoEsquerda(root->left);
                    root = rotacaoDireita(root);
                    if (printar) {
                        std::cout << "Árvore após rotação esquerda-direita: \n";
                        prettyPrintTree(root);
                    }
                }
            }
            alturaEsquerda = calcularAltura(root->left);
            alturaDireita = calcularAltura(root->right);
            diferencaAltura = alturaEsquerda - alturaDireita;
            aux++;
        }
    }

    // Tratar diferença menor que -2 (árvore desbalanceada severamente)
    else if (diferencaAltura < -2) {
        if (printar) {
            prettyPrintTree(root);
            std::cout << "Subárvore severamente desbalanceada detectada no nó " << root->data 
                      << ". Diferença de altura: " << diferencaAltura 
                      << ". Sugestão: Rotação(s) para balancear.\n\n";
        }

        while (diferencaAltura < -1) {
            // Verifica qual caso aplicar (rotação à esquerda ou direita-esquerda)
            if (calcularAltura(root->right->right) >= calcularAltura(root->right->left)) {
                if (balancear) {
                    if (printar) {
                        std::cout << "Rotação à esquerda sugerida no nó " << root->data << ".\n";
                    }
                    root = rotacaoEsquerda(root);
                    if (printar) {
                        std::cout << "Árvore após rotação à esquerda: \n";
                        prettyPrintTree(root);
                    }
                }
            } else {
                if (balancear) {
                    if (printar) {
                        std::cout << "Rotação direita-esquerda sugerida no nó " << root->data << ".\n";
                    }
                    root->right = rotacaoDireita(root->right);
                    root = rotacaoEsquerda(root);
                    if (printar) {
                        std::cout << "Árvore após rotação direita-esquerda: \n";
                        prettyPrintTree(root);
                    }
                }
            }
            alturaEsquerda = calcularAltura(root->left);
            alturaDireita = calcularAltura(root->right);
            diferencaAltura = alturaEsquerda - alturaDireita;
            aux++;
        }
    }

    // Continua verificando os filhos recursivamente
    sugerirRotacoes(root->left, aux, balancear, printar);
    sugerirRotacoes(root->right, aux, balancear, printar);
}

// Funções de rotação
Node* rotacaoDireita(Node* nó) {
    Node* aux = nó->left;
    nó->left = aux->right;
    aux->right = nó;
    return aux;
}

Node* rotacaoEsquerda(Node* nó) {
    Node* aux = nó->right;
    nó->right = aux->left;
    aux->left = nó;
    return aux;
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
        std::cout << valor;
        if (valor != caminhoMaisLongo.back()) {
            std::cout << " -> ";
        }
    }
    std::cout << "\n";
}

int calcularMenorAltura(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    
    return std::min(calcularMenorAltura(root->left), calcularMenorAltura(root->right)) + 1;
} 

Node* gerarArvoreQseEquilibrada(int m, int n) {
    Node* balanceada = nullptr;

    for (int i = 1; i <= m; i++) {
        int alturaMax = calcularAltura(balanceada);
        int alturaMin = calcularMenorAltura(balanceada);
        if (i < m/2 ) {
            if (alturaMax - alturaMin > n) { 
                int aux = 1;
                while (aux != 0) {
                    aux = 0;
                    sugerirRotacoes(balanceada, aux, true, false);
                }
            } 
        }
        balanceada = inserirNo(balanceada, i);
    }

    return balanceada;
}

Node* gerarArvoreTorta(int m) {
    // gerar vetor de tamanho m, arvore torta, onde os valores são inseridos em ordem crescente

    Node* root = nullptr;
    for (int i = 1; i <= m; i++) {
        root = inserirNo(root, i);
    }

    return root;
}
 
void analiseDeCrescimento() {
    std::vector<std::pair<int, double>> analise;

    for (int m = 3; m <= 1000; m++) {
        Node* arvoreTorta= gerarArvoreTorta(m);
        int n = m/3;
        Node* arvoreQseEquilibrada = gerarArvoreQseEquilibrada(m, n);
        
        double depreciacao = analisando(arvoreTorta, arvoreQseEquilibrada);

        analise.push_back(std::make_pair(m, depreciacao));
    }

    std::cout << "\nAnálise de crescimento finalizada.\n";
    std::cout << "Depreciação de altura para diferentes tamanhos de árvores:\n";
    for (auto& p : analise) {
        std::cout << "Tamanho: " << p.first << " - Depreciação: " << p.second << "%\n";
    }

    double max = 0, min = 100;
    for (auto& p : analise) {
        if (p.second > max) {
            max = p.second;
        }
        if (p.second < min) {
            min = p.second;
        }
    }

    std::cout << "Maior depreciação: " << max << "%  - Menor depreciação: " << min << "%\n";
    salvarArquivo ("datasets/analise.csv", analise);

    // executar arquivo python para plotar o gráfico
    system("python3 src/plot.py");
}

void salvarArquivo(std::string nomeArquivo, std::vector<std::pair<int, double>> analise) {
    std::ofstream arquivo(nomeArquivo);
    if (arquivo.is_open()) {
        arquivo << "Tamanho da árvore,Depreciação\n";
        for (auto& p : analise) {
            arquivo << p.first << "," << p.second << "\n";
        }
        arquivo.close();
        std::cout << "Análise salva no arquivo " << nomeArquivo << ".\n";
    } else {
        std::cout << "Erro ao salvar o arquivo " << nomeArquivo << ".\n";
    }
}

// Função para análise de crescimento
double analisando(Node* arvoreTorta, Node* arvoreQseEquilibrada) {

    int alturaTorta = calcularAltura(arvoreTorta);
    int alturaEquilibrada = calcularAltura(arvoreQseEquilibrada);

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