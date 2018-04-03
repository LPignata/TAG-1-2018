#include <iostream>
#include <fstream>
#include <string>
#include "graph.hpp"
#include "gmlparser.hpp"

// Construtor padrão
GMLParser::GMLParser() {
    graph = new Graph();
}

Graph* GMLParser::fill_graph(std::string str_file) {
    std::string line;
    std::ifstream file(str_file);
    int source = 0, target = 0;

    while (std::getline(file, line)) {
        
        if (line.find("id") != -1) {
            graph->add_node(stoi(line.substr(line.find("id") + 3)));
        }
        else if (line.find("source") != -1) {
            source = stoi(line.substr(line.find("source") + 7));
            if (target != 0) {
                graph->add_edge(source, target);
                source = 0;
                target = 0;
            }
        }
        else if (line.find("target") != -1) {
            target = stoi(line.substr(line.find("target") + 7));
            if (source != 0) {
                graph->add_edge(source, target);
                source = 0;
                target = 0;
            }
        }
    }

    return graph;
}