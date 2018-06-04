#include <iostream>
#include <algorithm>
#include <list>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include "graph.hpp"
#include "parser.hpp"

using namespace std;

int main() {
	Parser parser;

	Graph* graph = parser.fill_graph("data/entradaProj3TAG.txt");
	for (auto n : graph->to_teachers()) {
		cout << '(' << n.first << ", " << n.second << ')' << endl;
	}
	return 0;
}