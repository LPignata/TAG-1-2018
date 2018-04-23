#include <iostream>
#include <stdio.h>
#include <algorithm>
#include "graph.hpp"
#include "parser.hpp"

using namespace std;

int main() {
	Parser parser;
	vector<pair<int, int> > degrees;

	Graph* graph = parser.fill_graph("karate/karate.gml");

	return 0;
}