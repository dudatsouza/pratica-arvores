
#include "problema1.hpp"
int Problema1::menu() {
    std::cout << "\nMenu:" << std::endl;
    std::cout << "1. Inserir valores do problema" << std::endl;
    std::cout << "2. Remover valores do problema" << std::endl;
    std::cout << "3. Buscar elementos do problema" << std::endl;
    std::cout << "4. Inserir valores" << std::endl;
    std::cout << "5. Remover valores" << std::endl;
    std::cout << "6. Buscar elemento" << std::endl;
    std::cout << "7. Desafio adicional" << std::endl;
    std::cout << "8. Sair" << std::endl;
    std::cout << "Escolha uma opção: ";
    int choice;
    std::cin >> choice;
    std::cin.ignore();

    return choice;
}

bool Problema1::verificarArvoresCriadas(int choice) {
    return (((choice == 2 || choice == 3) && (treeBinary1.getRoot() == nullptr || treeBinary2.getRoot() == nullptr || treeBinary3.getRoot() == nullptr || treeBinary4.getRoot() == nullptr)) || ((choice == 5 || choice == 6) && treeBinary.getRoot() == nullptr));
}

void Problema1::inserirValoresProblema() {
    std::cout << "Inserindo valores do problema..." << std::endl;
    for (size_t i = 0; i < treesBinary.size(); ++i) {
        std::cout << "\nÁrvore " << i + 1 << std::endl;
        std::vector<int> values = (i == 0) ? arvore1 : (i == 1) ? arvore2 : (i == 2) ? arvore3 : arvore4;
        std::cout << "Valores inseridos: ";
        for (int val : values) {
            std::cout << val << " ";
        }   
        std::cout << std::endl;         
        treesBinary[i]->insert(values);
        
        if (i != 3)
            std::cout << "Pressione Enter para ir para a próxima árvore" << std::endl;
        else
            std::cout << "Pressione Enter para ver todos os resultados" << std::endl;
        std::cin.get();
        system("clear");
    }

    std::cout << "\nResultados das inserções:" << std::endl;
    for (size_t i = 0; i < treesBinary.size(); ++i) {
        std::cout << "\nÁrvore " << i + 1 << std::endl;
        prettyPrintTree(treesBinary[i]->getRoot());
    }
    std::cout << "Pressione Enter para continuar...";
    std::cin.get();
    system("clear");
}

void Problema1::removerValoresProblema() {
    std::vector<int> remove1 = {33, 90, 33, 45};
    std::vector<int> remove2 = {11, 72, 65, 23};
    std::vector<int> remove3 = {34, 89, 81, 95};
    std::vector<int> remove4 = {20, 5, 18, 44};

    std::cout << "Removendo valores do problema..." << std::endl;
    for (size_t i = 0; i < treesBinary.size(); ++i) {
        std::cout << "\nÁrvore " << i + 1 << std::endl;
        std::vector<int> values = (i == 0) ? remove1 : (i == 1) ? remove2 : (i == 2) ? remove3 : remove4;
        treesBinary[i]->remove(values);
        
        if (i != 3)
            std::cout << "Pressione Enter para ir para a próxima árvore" << std::endl;
        else
            std::cout << "Pressione Enter para ver todos os resultados" << std::endl;
        std::cin.get();
        system("clear");
    }

    std::cout << "\nResultados das remoções:" << std::endl;
    for (size_t i = 0; i < treesBinary.size(); ++i) {
        std::cout << "\nÁrvore " << i + 1 << std::endl;
        prettyPrintTree(treesBinary[i]->getRoot());
    }
    std::cout << "Pressione Enter para continuar...";
    std::cin.get();
    system("clear");
}

void Problema1::buscarElementosProblema() {
    int target1 = 27, target2 = 28, target3 = 23, target4 = 12;

    std::cout << "Buscando elementos do problema..." << std::endl;
    for (size_t i = 0; i < treesBinary.size(); ++i) {
        int target = (i == 0) ? target1 : (i == 1) ? target2 : (i == 2) ? target3 : target4;
        std::cout << "\nÁrvore " << i + 1 << ", Elemento buscado: " << target << std::endl;
        buscas(treesBinary[i], target);
        std::cout << "Pressione Enter para continuar...";
        std::cin.get();
    }
    system("clear");
}

void Problema1::inserirValores() {
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
        return; // Retorna ao menu sem prosseguir com a operação
    } catch (const std::out_of_range& e) {
        std::cout << "Erro: Um dos números está fora do intervalo permitido." << std::endl;
        treeValuesBinary.clear(); // Limpa o vetor, já que houve erro na entrada
        return; // Retorna ao menu sem prosseguir com a operação
    }

    treeBinary.insert(treeValuesBinary);
}

void Problema1::removerValores() {
    std::cout << "Digite os valores a serem removidos, separados por vírgula (e pressione Enter): ";
    std::string line;
    std::getline(std::cin, line); // Captura a linha completa com os números
    std::vector<int> valuesToRemove; // Vetor para armazenar os valores a serem removidos
    size_t pos = 0;

    try {
        // Enquanto encontrar vírgulas, processa os valores
        while ((pos = line.find(',')) != std::string::npos) {
            std::string token = line.substr(0, pos); // Extrai o número como string
            token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end()); // Remove espaços
            if (!token.empty()) { // Verifica se o token não está vazio antes de converter
                valuesToRemove.push_back(std::stoi(token)); // Converte para inteiro e adiciona ao vetor
            }
            line.erase(0, pos + 1); // Remove o número processado e a vírgula
        }

        // Adicionar o último valor (ou único se não houver vírgulas)
        line.erase(std::remove_if(line.begin(), line.end(), ::isspace), line.end()); // Remove espaços
        if (!line.empty()) { // Verifica se a string restante não está vazia
            valuesToRemove.push_back(std::stoi(line)); // Converte o último valor e adiciona ao vetor
        }
    } catch (const std::invalid_argument& e) {
        std::cout << "Erro: Entrada inválida. Certifique-se de que os valores sejam números separados por vírgula." << std::endl;
        return; // Retorna ao menu sem prosseguir com a operação
    } catch (const std::out_of_range& e) {
        std::cout << "Erro: Um dos números está fora do intervalo permitido." << std::endl;
        return; // Retorna ao menu sem prosseguir com a operação
    }

    treeBinary.remove({valuesToRemove});
}

void Problema1::buscarElemento() {
    std::cout << "Digite o elemento a ser buscado: ";
    int target;
    std::cin >> target;
    std::cin.ignore();
    std::cout << "Resultados da busca:" << std::endl;
    buscas(&treeBinary, target);
}

void Problema1::desafioAdicional() {
    while (true) {
        std::cout << "\nDESAFIO ADICIONAL" << std::endl;
        std::cout << "Este desafio consiste em analisar as árvores já geradas e, usando a ideia de uma árvore AVL, identificar um subconjunto de elementos cujas remoções resultem no maior número de rotações (rebalanceamentos) da árvore." << std::endl;

        std::cout << "\nMenu:" << std::endl;
        std::cout << "1. Analisar árvores do problema" << std::endl;
        std::cout << "2. Analisar uma nova árvore AVL" << std::endl;
        std::cout << "3. Sair" << std::endl;
        std::cout << "Escolha uma opção: ";

        int sub_choice;
        std::cin >> sub_choice;
        std::cin.ignore(); // Consumir o '\n'

        if (sub_choice == 1) {
            criandoArvoresAVLProblema(); // Criar as árvores do problema
            std::vector<int> nMaxRotations(treesAVL.size());
            std::vector<std::vector<int>> melhorSubconjuntos(treesAVL.size());

            // Após a criação, realizar a análise das rotações
            for (size_t i = 0; i < treesAVL.size(); ++i) {
                std::cout << "\nAnalisando rotações para a Árvore AVL " << i + 1 << ":" << std::endl;

                std::vector<int> valores = (i == 0) ? arvore1 : (i == 1) ? arvore2 : (i == 2) ? arvore3 : arvore4;

                AVLTree arvore = *treesAVL[i];

                auto [melhorSubconjunto, maxRotations] = analisarRotacoesArvore(arvore, valores);

                // Exibir resultados
                std::cout << "Melhor subconjunto para remoção: ";
                for (int val : melhorSubconjunto) {
                    std::cout << val << " ";
                }
                std::cout << "\nNúmero de rotações resultantes: " << maxRotations << std::endl;
                
                nMaxRotations[i] = maxRotations;
                melhorSubconjuntos[i] = melhorSubconjunto;


                std::cout << "Pressione Enter para continuar...";
                std::cin.get();
                system("clear");
            }

            std::cout << "Resultados finais:" << std::endl;
            for (size_t i = 0; i < treesAVL.size(); ++i) {
                std::cout << "\nÁrvore AVL " << i + 1 << ":" << std::endl;
                std::cout << "Melhor subconjunto para remoção: ";
                for (int val : melhorSubconjuntos[i]) {
                    std::cout << val << " ";
                }
                std::cout << "\nNúmero de rotações resultantes: " << nMaxRotations[i] << std::endl;
            }

            std::cout << "Pressione Enter para continuar...";
            std::cin.get();
            system("clear");

        } else if (sub_choice == 2) {
            criandoArvoreAVL(); // Criar uma nova árvore AVL

            std::cout << "\nAnalisando rotações para a árvore criada:" << std::endl;

            std::vector<int> valores = treeValuesAVL;

            AVLTree arvore = treeAVL;


            auto [melhorSubconjunto, maxRotations] = analisarRotacoesArvore(arvore, valores);

            std::cout << "Pressione Enter para continuar...";
            std::cin.get();
            system("clear");

            // Exibir resultados
            std::cout << "Melhor subconjunto para remoção: ";
            for (int val : melhorSubconjunto) {
                std::cout << val << " ";
            }
            std::cout << "\nNúmero de rotações resultantes: " << maxRotations << std::endl;

            std::cout << "Pressione Enter para continuar...";
            std::cin.get();
            system("clear");


        } else if (sub_choice == 3) {
            std::cout << "Saindo do desafio adicional..." << std::endl;
            std::cin.get();
            system("clear");
            break;

        } else {
            std::cout << "Opção inválida! Tente novamente." << std::endl;
        }
    }
}

void Problema1::printordem(std::vector<std::string> order) {
    for (const auto& val : order) {
        std::cout << val;
        // se for o ultimo elemento, imprime um espaço
        if (val == order.back()) 
            std::cout << std::endl;
        else 
            std::cout << " -> ";
    }
}

void Problema1::buscas(BinaryTree *tree, int target) {
    int visits = 0;
    std::vector<std::string> order = {};
    visits = tree->search_pre_order(tree->getRoot(), target, order, "");
    std::cout << "1. Método pré-ordem:" << std::endl;
    std::cout << "             ├──── n° de visitação = " << visits << std::endl;
    std::cout << "             └──── ordem = ";
    printordem(order);

    order = {};
    visits = tree->search_post_order(tree->getRoot(), target, order, "");
    std::cout << "2. Método pós-ordem:" << std::endl;
    std::cout << "             ├──── n° de visitação = " << visits << std::endl;
    std::cout << "             └──── ordem = ";
    printordem(order);

    order = {};
    visits = tree->search_in_order(tree->getRoot(), target, order, "");
    std::cout << "3. Método in-ordem:" << std::endl;
    std::cout << "             ├──── n° de visitação = " << visits << std::endl;
    std::cout << "             └──── ordem = ";
    printordem(order);  

    order = {};
    tree->search_level_order(target, visits, order);
    std::cout << "4. Método em largura:" << std::endl;
    std::cout << "             ├──── n° de visitação = " << visits << std::endl;
    std::cout << "             └──── ordem = ";
    printordem(order);
}

void Problema1::criandoArvoresAVLProblema() {
    std::cout << "Criando árvores do problema usando AVL..." << std::endl;
    for (size_t i = 0; i < treesAVL.size(); ++i) {
        std::cout << "\nÁrvore AVL " << i + 1 << ":" << std::endl;
        std::vector<int> values = (i == 0) ? arvore1 : (i == 1) ? arvore2 : (i == 2) ? arvore3 : arvore4;
        std::cout << "Valores inseridos: ";
        for (int val : values) {
            std::cout << val << " ";
        }
        std::cout << std::endl;

        treesAVL[i]->insert(values);

        if (i < 3)
            std::cout << "Pressione Enter para ir para a próxima árvore" << std::endl;
        else
            std::cout << "Pressione Enter para ver todos os resultados" << std::endl;
        std::cin.get();
        system("clear");
    }

    std::cout << "\nResultados das inserções nas árvores AVL:" << std::endl;
    for (size_t i = 0; i < treesAVL.size(); ++i) {
        std::cout << "\nÁrvore AVL " << i + 1 << ":" << std::endl;
        prettyPrintTree(treesAVL[i]->getRoot());
    }

    std::cout << "Pressione Enter para continuar...";
    std::cin.get();
    system("clear");
}

void Problema1::criandoArvoreAVL() {
    std::cout << "Digite os valores separados por vírgula: ";
    std::string line;
    std::getline(std::cin, line); // Captura a linha completa com os números

    size_t pos = 0;

    try {
        // Processar os valores separados por vírgulas
        while ((pos = line.find(',')) != std::string::npos) {
            std::string token = line.substr(0, pos);
            token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
            if (!token.empty()) {
                treeValuesAVL.push_back(std::stoi(token));
            }
            line.erase(0, pos + 1);
        }

        // Processar o último valor (ou único se não houver vírgulas)
        line.erase(std::remove_if(line.begin(), line.end(), ::isspace), line.end());
        if (!line.empty()) {
            treeValuesAVL.push_back(std::stoi(line));
        }

        treeAVL.insert(treeValuesAVL);

        std::cout << "Árvore inserida:" << std::endl;
        prettyPrintTree(treeAVL.getRoot());

        std::cout << "Pressione Enter para continuar...";
        std::cin.get();
        system("clear");

    } catch (const std::invalid_argument& e) {
        std::cout << "Erro: Entrada inválida. Certifique-se de que os valores sejam números separados por vírgula." << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Erro: Um dos números está fora do intervalo permitido." << std::endl;
    }
}

std::vector<std::vector<int>> Problema1::gerarSubconjuntos(const std::vector<int>& valores) {
    std::vector<std::vector<int>> subconjuntos;
    int n = valores.size();
    for (int mask = 1; mask < (1 << n); ++mask) { // Gera todas as combinações, exceto o subconjunto vazio
        std::vector<int> subconjunto;
        for (int j = 0; j < n; ++j) {
            if (mask & (1 << j)) { // Verifica se o elemento `j` está incluído no subconjunto
                subconjunto.push_back(valores[j]);
            }
        }
        subconjuntos.push_back(subconjunto);
    }
    return subconjuntos;
}

std::pair<std::vector<int>, int> Problema1::analisarRotacoesArvore(AVLTree arvore, const std::vector<int>& valores) {
    int maxRotations = 0;
    std::vector<int> melhorSubconjunto;

    // Gera todos os subconjuntos possíveis
    auto subconjuntos = gerarSubconjuntos(valores);

    for (const auto& subconjunto : subconjuntos) {
        // Criar uma cópia profunda da árvore para cada subconjunto
        AVLTree arvore1 = arvore.copy();
        
        arvore1.resetRotationCount(); // Resetar contador de rotações

        std::cout << "\nAnalisando subconjunto: ";
        for (int valor : subconjunto) {
            std::cout << valor << " ";
        }
        std::cout << std::endl;

        // Remover os valores do subconjunto na cópia
        for (int valor : subconjunto) {
            arvore1.remove({valor});
        }

        // Verificar número de rotações
        int rotacoes = arvore1.getRotationCount();
        std::cout << "Rotações geradas: " << rotacoes << std::endl;

        // Atualizar o melhor subconjunto se necessário
        if (rotacoes > maxRotations) {
            maxRotations = rotacoes;
            melhorSubconjunto = subconjunto;
        }

    }

    return {melhorSubconjunto, maxRotations}; // Retorna o subconjunto com mais rotações e o número de rotações

}
