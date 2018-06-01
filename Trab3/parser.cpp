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
    while (getline(file, line)) {
        if (((line[0] == '/') && (line[1] == '/')) || (line.empty()))
            continue;
        
        std::vector<std::string> two_points{Parser::explode(line, ':')};
        
        // Se trata de um professor
        if (two_points.size() == 2) {
            two_points[0] = Parser::trim(two_points[0], '(');
            two_points[0] = Parser::trim(two_points[0], ')');
            two_points[1] = Parser::trim(two_points[1], ' ');
            two_points[1] = Parser::trim(two_points[1], '(');
            two_points[1] = Parser::trim(two_points[1], ')');

            std::vector<std::string> teacher{Parser::explode(two_points[0], ',')};
            teacher[1] = Parser::trim(teacher[1], ' ');

            std::vector<std::string> schools{Parser::explode(two_points[1], ',')};
            schools[1] = Parser::trim(schools[1], ' ');
            schools[2] = Parser::trim(schools[2], ' ');
            schools[3] = Parser::trim(schools[3], ' ');
            schools[4] = Parser::trim(schools[4], ' ');

            graph->add_node(teacher[0], std::stoi(teacher[1]), 0);
            for (auto school : schools)
                graph->add_edge(teacher[0], school);
        }
        // Se trata de uma escola
        else {
            two_points[0] = Parser::trim(two_points[0], '(');
            two_points[0] = Parser::trim(two_points[0], ')');
            two_points[1] = Parser::trim(two_points[1], '(');
            two_points[1] = Parser::trim(two_points[1], ')');
            two_points[2] = Parser::trim(two_points[2], '(');
            two_points[2] = Parser::trim(two_points[2], ')');
            graph->add_node(two_points[0], std::stoi(two_points[1]), std::stoi(two_points[2]));
        }
        
    }

    file.close();

    return graph;
}

const std::vector<std::string> Parser::explode(const std::string& s, const char& c) {
    std::string buff{""};
	std::vector<std::string> v;
	
	for(auto n:s)
	{
		if(n != c) buff+=n; else
		if(n == c && buff != "") { v.push_back(buff); buff = ""; }
	}
	if(buff != "") v.push_back(buff);
	
	return v;
}

std::string Parser::trim(std::string str, char c) {
    while (str[0] == c)
        str.erase(str.begin());
    while (str.back() == c)
        str.erase(str.end()-1);
    return str;
}