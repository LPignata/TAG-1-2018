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
    std::ifstream file(str_file);
    int size, source, target;

    file >> size;
    while (size--) {
        file >> source >> target;
        graph->add_edge(source, target);
    }

    return graph;
}