#include <vector>
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
	Node* node_source, *node_target;
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
}

// Realiza a contagem dos graus dos nós
// e retorna um vetor contendo id e grau
std::vector <std::pair<int, int> > Graph::count_degree() {
	std::vector <std::pair<int, int> > degrees;

	for (int i = 0; i < Graph::nodes.size(); i++) {
		degrees.push_back(std::make_pair(Graph::nodes[i]->get_degree(), Graph::nodes[i]->get_id()));
	}
	return degrees;
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