#include <iostream>
#include <algorithm>
#include <list>
#include <ctime>
#include <graphics.h>
#include "graph.hpp"
#include "parser.hpp"

using namespace std;

void print_ordenation(list<int> ordenation) {
	cout << '{';
	for (auto node : ordenation) {
		cout << node;
		if (node != ordenation.back())
			cout << ", ";
	}
	cout << '}' << endl << endl;
}

void kahn(int number, Graph* graph) {
	clock_t clocker;
	
	cout << "Kahn - " << number << " vértices" << endl;
	clocker = clock();
	list<int> ordenation = graph->kahn();
	clocker = clock() - clocker;
	cout << '(' << ((double)clocker) / CLOCKS_PER_SEC << " segundos)" << endl << endl;
	print_ordenation(ordenation);
}

void dfs(int number, Graph* graph) {
	clock_t clocker;
	
	cout << "DFS - " << number << " vértices" << endl;
	clocker = clock();
	list<int> ordenation = graph->dfs();
	clocker = clock() - clocker;
	cout << '(' << ((double)clocker) / CLOCKS_PER_SEC << " segundos)" << endl << endl;
	print_ordenation(ordenation);
}

int main() {
	Parser parser_small;
	Parser parser_med;
	Parser parser_large;
	Parser parser_huge;
	vector<pair<int, int> > degrees;

	Graph* graph_small = parser_small.fill_graph("top_datasets/top_small.txt");
	Graph* graph_med = parser_med.fill_graph("top_datasets/top_med.txt");
	Graph* graph_large = parser_large.fill_graph("top_datasets/top_large.txt");
	Graph* graph_huge = parser_huge.fill_graph("top_datasets/top_huge.txt");
	
	kahn(10, graph_small);
	kahn(100, graph_med);
	kahn(10000, graph_large);
	kahn(100000, graph_huge);
	
	dfs(10, graph_small);
	dfs(100, graph_med);
	dfs(10000, graph_large);
	dfs(100000, graph_huge);
	
	return 0;
}