#ifndef _GMLPARSER_H
#define _GMLPARSER_H

#include <stdio.h>
#include <string>

class GMLParser {
    public:
        GMLParser();

        Graph* fill_graph(std::string file);

    private:
        Graph* graph;
};

#endif