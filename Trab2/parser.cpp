#include <iostream>
#include <fstream>
#include <string>
#include "graph.hpp"
#include "parser.hpp"

// Construtor padrão
Parser::Parser() {
    graph = new Graph();
}

Graph* Parser::fill_graph(std::string str_file) {
    std::string line;
    std::ifstream file(str_file);
    int nodes, source, target;

    file >> nodes;

    for (int i = 0; i < nodes; i++) {
        graph->add_node(i);
    }

    while (file >> source >> target) {
        graph->add_edge(source, target);
    }

    file.close();

    return graph;
}