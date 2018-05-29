#ifndef _PARSER_H
#define _PARSER_H

#include <stdio.h>
#include <string>
#include <vector>

class Parser {
    public:
        Parser();

        Graph* fill_graph(std::string file);

    private:
        Graph* graph;
        
        const std::vector<std::string> explode(const std::string& s, const char& c);

        std::string trim(std::string str, char c);
};

#endif