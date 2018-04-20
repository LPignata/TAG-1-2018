#include <vector>
#include <iostream>
#include <algorithm>
#include "graph.hpp"

// Construtor do grafo
Graph::Graph() {}

// Adiciona nó ao grafo
void Graph::add_node(int id) {
	Node* node = new Node(id);
	Graph::nodes.push_back(node);
}

// Adiciona aresta ao grafo
void Graph::add_edge(int id_source, int id_target) {
	Node* node_source = nullptr, *node_target = nullptr;
	for (int i = 0; i < Graph::nodes.size(); i++) {
		if (Graph::nodes[i]->get_id() == id_source) {
			node_source = Graph::nodes[i];
		}
		if (Graph::nodes[i]->get_id() == id_target) {
			node_target = Graph::nodes[i];
		}
		if ((node_target != nullptr) && (node_source != nullptr)) {
			break;
		}
	}
	node_source->add_edge(node_target);
	node_target->add_edge(node_source);
}

// Realiza a contagem dos graus dos nós
// e retorna um vetor contendo id e grau
std::vector <std::pair<int, int> > Graph::count_degree() {
	std::vector <std::pair<int, int> > degrees;

	for (int i = 0; i < Graph::nodes.size(); i++) {
		degrees.push_back(std::make_pair(Graph::nodes[i]->get_degree(), Graph::nodes[i]->get_id()));
	}
	std::sort(degrees.begin(), degrees.end());
	return degrees;
}

// Obtém um vetor contendo os cliques do grafo
std::vector<std::pair<int, std::vector<Graph::Node*> > >* Graph::get_maximal() {
	std::vector<Graph::Node*> r;
	std::vector<Graph::Node*> x;
	std::vector<std::pair<int, std::vector<Graph::Node*> > >* list = new std::vector<std::pair<int, std::vector<Graph::Node*> > >();
	Graph::bron_kerbosch(r, Graph::nodes, x, list);
	return list;
}

// Construtores do nó
Graph::Node::Node() {
	this->estate = NO_VISITED;
}

Graph::Node::Node(int id) {
	this->estate = NO_VISITED;
	this->id = id;
}

// Adiciona ligação com nó (Adicionar aresta)
void Graph::Node::add_edge(Node* node) {
	edge.push_back(node);
}

// Retorna o vector de adjacência do nó
std::vector<Graph::Node*> Graph::Node::get_list_edge() {
	return Graph::Node::edge;
}

// Métodos get e set
int Graph::Node::get_id() {
	return this->id;
}

void Graph::Node::set_id(int id) {
	this->id = id;
}

Graph::Estate Graph::Node::get_estate() {
	return estate;
}

void Graph::Node::set_estate(Graph::Estate estate) {
	this->estate = estate;
}

int Graph::Node::get_degree() {
	return edge.size();
}

void Graph::bron_kerbosch(std::vector<Graph::Node*> r, std::vector<Graph::Node*> p, std::vector<Graph::Node*> x, std::vector<std::pair<int, std::vector<Graph::Node*> > >* list) {
	if(p.empty() && x.empty()) {
		list->push_back(make_pair(r.size(), r));
		return;
	}
	
	auto p1 = p;

	for (auto node : p1) {
		std::vector<Graph::Node*> intersectionP = {}, intersectionX = {};
		for (auto node2 : node->get_list_edge()) {
			if (find(p.begin(), p.end(), node2) != p.end()) {
				intersectionP.push_back(node2);
			}
			if (find(x.begin(), x.end(), node2) != x.end()) {
				intersectionX.push_back(node2);
			}
		}
		std::vector<Graph::Node*> r1 = r;
		r1.push_back(node);
		Graph::bron_kerbosch(r1, intersectionP, intersectionX, list);
		p.erase(find(p.begin(), p.end(), node));
		x.push_back(node);
	}
}