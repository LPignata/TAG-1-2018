#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include "graph.hpp"

// Construtor do grafo
Graph::Graph() {}

// Adiciona nó ao grafo
void Graph::add_node(std::string id) {
	bool exist = false;
	for (auto node : Graph::nodes) {
		if (node->get_id() == id)
			exist = true;
	}
	if (!exist) {
		Node* node = new Node(id);
		Graph::nodes.push_back(node);
	}
}

void Graph::add_node(std::string id, int qualifications, int vacations) {
	bool exist = false;
	for (auto node : Graph::nodes) {
		if (node->get_id() == id) {
			exist = true;
			node->set_qualifications(qualifications);
			node->set_vacations(vacations);
		}
	}
	if (!exist) {
		Node* node = new Node(id);
		node->set_qualifications(qualifications);
		node->set_vacations(vacations);
		Graph::nodes.push_back(node);
	}
}

// Adiciona aresta ao grafo
void Graph::add_edge(std::string id_source, std::string id_target) {
	int source = -1, target = -1;
	for (int i = 0; i < Graph::nodes.size(); i++) {
		if (Graph::nodes[i]->get_id() == id_source)
			source = i;
		if (Graph::nodes[i]->get_id() == id_target)
			target = i;
	}
	if (source == -1) {
		add_node(id_source);
		source = Graph::nodes.size() - 1;
	}
	if (target == -1) {
		add_node(id_target);
		target = Graph::nodes.size() - 1;
	}
	Graph::nodes[source]->add_edge(Graph::nodes[target]);
}

void Graph::set_default() {
	for (auto node : nodes) {
		node->set_default();
	}
}

// Marca todos os nós como não visitados
void Graph::default_estate() {
	for (auto node : nodes) {
		node->set_estate(Estate::NO_VISITED);
	}
}

// Construtores do nó
Graph::Node::Node() {
	this->estate = NO_VISITED;
	receive_node = 0;
	default_receive_node = 0;
}

Graph::Node::Node(std::string id) {
	this->estate = NO_VISITED;
	this->id = id;
	receive_node = 0;
	default_receive_node = 0;
}

// Adiciona ligação com nó (Adicionar aresta)
void Graph::Node::add_edge(Node* node) {
	edge.push_back(node);
}

// Retorna o vector de adjacência do nó
std::vector<Graph::Node*> Graph::Node::get_list_edge() {
	return Graph::Node::edge;
}

// Adiciona em um o receive_node
void Graph::Node::add_receive() {
	receive_node++;
	default_receive_node++;
}

// Diminui em um o receive_node
void Graph::Node::sub_receive() {
	receive_node--;
}

// Devolve os valores originais de receive_node
void Graph::Node::default_receive() {
	receive_node = default_receive_node;
}

// Métodos get e set
std::string Graph::Node::get_id() {
	return this->id;
}

void Graph::Node::set_id(std::string id) {
	this->id = id;
}

Graph::Estate Graph::Node::get_estate() {
	return estate;
}

void Graph::Node::set_estate(Graph::Estate estate) {
	this->estate = estate;
}

int Graph::Node::get_qualifications() {
	return qualifications;
}

void Graph::Node::set_qualifications(int qualifications) {
	this->qualifications = qualifications;
}

int Graph::Node::get_vacations() {
	return vacations;
}

void Graph::Node::set_vacations(int vacations) {
	this->vacations = vacations;
}

int Graph::Node::get_degree() {
	return edge.size();
}

int Graph::Node::get_receive() {
	return receive_node;
}

bool Graph::Node::is_teacher() {
	return get_vacations() == 0;
}

std::vector<std::pair<std::string, std::string> > Graph::to_teachers() {
	
}