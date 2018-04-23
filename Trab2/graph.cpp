#include <vector>
#include <iostream>
#include <algorithm>
#include "graph.hpp"

// Construtor do grafo
Graph::Graph() {}

// Adiciona nó ao grafo
Node* Graph::add_node(int id) {
	Node* node = new Node(id);
	Graph::nodes.push_back(node);
	return node;
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

	if (node_source == nullptr) {
		node_source = add_node(id_source);
	}
	if (node_target == nullptr) {
		node_target = add_node(id_target);
	}

	node_source->add_edge(node_target);
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