#include <iostream>
#include <stdio.h>
#include <algorithm>
#include "graph.hpp"
#include "gmlparser.hpp"

using namespace std;

int main() {
	GMLParser parser;
	vector<pair<int, int> > degrees;

	Graph* graph = parser.fill_graph("karate/karate.gml");

	degrees = graph->count_degree();

	// Mostra em ordem descrente o id do nó e o seu grau
	for (int i = degrees.size() - 1; i >= 0; i--) {
		cout << "ID = " << degrees[i].second << endl;
		cout << "Grau = " << degrees[i].first << endl << endl;
	}

	std::vector<std::pair<int, std::vector<Graph::Node*> > >* list = graph->get_maximal();

	sort(list->begin(), list->end());

	cout << "Clique maximal de 5 = ";
	std::vector<Graph::Node*> maximal = (*list)[list->size() - 1].second;
	for (auto node : maximal) {
		cout << node->get_id() << " ";
	}
	cout << endl << endl;

	cout << "Clique maximo = ";
	for (auto node : *list) {
		if (node.first == 5) {
			for (auto maximo : node.second) {
				cout << maximo->get_id() << " ";
			}
			break;
		}
	}
	cout << endl << endl;

	return 0;
}