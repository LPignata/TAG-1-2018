#ifndef _PARSER_H
#define _PARSER_H

#include <stdio.h>
#include <string>

class Parser {
    public:
        Parser();

        Graph* fill_graph(std::string file);

    private:
        Graph* graph;
};

#endif