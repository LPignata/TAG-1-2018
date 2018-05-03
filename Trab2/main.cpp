#include <iostream>
#include <algorithm>
#include <list>
#include <ctime>
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

int kahn(int number, Graph* graph) {
	clock_t clocker;
	
	cout << "Kahn - " << number << " vértices" << endl;
	clocker = clock();
	list<int> ordenation = graph->kahn();
	clocker = ((double)(clock() - clocker)) / CLOCKS_PER_SEC;
	cout << '(' << clocker << " segundos)" << endl << endl;
	print_ordenation(ordenation);
	return clocker;
}

int dfs(int number, Graph* graph) {
	clock_t clocker;
	
	cout << "DFS - " << number << " vértices" << endl;
	clocker = clock();
	list<int> ordenation = graph->dfs();
	clocker = ((double)(clock() - clocker)) / CLOCKS_PER_SEC;
	cout << '(' << clocker << " segundos)" << endl << endl;
	print_ordenation(ordenation);
	return clocker;
}

void generate_graphic(vector<pair<int, int> > times) {

}

int main() {
	Parser parser_small;
	Parser parser_med;
	Parser parser_large;
	Parser parser_huge;
	vector<pair<int, int> > timer;

	Graph* graph_small = parser_small.fill_graph("top_datasets/top_small.txt");
	Graph* graph_med = parser_med.fill_graph("top_datasets/top_med.txt");
	Graph* graph_large = parser_large.fill_graph("top_datasets/top_large.txt");
	Graph* graph_huge = parser_huge.fill_graph("top_datasets/top_huge.txt");
	
	timer.push_back(make_pair(10, kahn(10, graph_small)));
	timer.push_back(make_pair(100, kahn(100, graph_med)));
	timer.push_back(make_pair(10000, kahn(10000, graph_large)));
	timer.push_back(make_pair(100000, kahn(100000, graph_huge)));
	
	timer.push_back(make_pair(10, dfs(10, graph_small)));
	timer.push_back(make_pair(100, dfs(100, graph_med)));
	timer.push_back(make_pair(10000, dfs(10000, graph_large)));
	timer.push_back(make_pair(100000, dfs(100000, graph_huge)));
	
	generate_graphic(timer);

	return 0;
}