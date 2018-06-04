#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include <string>
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

void Graph::Node::set_default() {
	while (!list->empty()) {
		list->pop_back();
	}
	for (auto node : edge) {
		list_edge->push_back(node);
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
	this->list_edge = new std::list<Node*>;
	this->list = new std::vector<Node*>;
}

Graph::Node::Node(std::string id) {
	this->estate = NO_VISITED;
	this->id = id;
	this->list_edge = new std::list<Node*>;
	this->list = new std::vector<Node*>;
}

// Adiciona ligação com nó (Adicionar aresta)
void Graph::Node::add_edge(Node* node) {
	edge.push_back(node);
}

// Retorna o vector de adjacência do nó
std::list<Graph::Node*>* Graph::Node::get_list_edge() {
	return Graph::Node::list_edge;
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

bool Graph::Node::is_teacher() {
	return get_vacations() == 0;
}

std::vector<Graph::Node*>* Graph::Node::get_list() {
	return Graph::Node::list;
}

std::vector<std::pair<std::string, std::string> > Graph::to_teachers() {
	std::list<Node*> list;
	Node *p, *e;

	set_default();
	
	// Adicionar os professores na fila
	for (auto node : nodes) {
		if (node->is_teacher())
			list.push_back(node);
	}

	while (!list.empty()) {
		// Pega o primeiro elemento da lista
		p = list.front();
		list.pop_front();
		if (p->get_list_edge()->empty())
			continue;
		// Retira o primeiro elemento de p
		e = p->get_list_edge()->front();
		p->get_list_edge()->pop_front();
		// Adiciona p em e
		e->get_list()->push_back(p);

		// Confere se estourou e retira o pior
		if (e->get_list()->size() > e->get_vacations()) {
			Node* n = NULL;
			for (auto node : *e->get_list()) {
				if (n == NULL) {
					n = node;
				}
				else {
					if (n->get_qualifications() == e->get_qualifications())
						n = node;
					else if (n->get_qualifications() > e->get_qualifications()) {
						if (node->get_qualifications() < e->get_qualifications())
							n = node;
						else 
							n = (node->get_qualifications() < n->get_qualifications()) ? node : n;
					}
					else {
						if (node->get_qualifications() > e->get_qualifications())
							n = node;
						else 
							n = (node->get_qualifications() > n->get_qualifications()) ? node : n;
					}
				}
			}
			e->get_list()->erase(std::find(e->get_list()->begin(), e->get_list()->end(), n));
			list.push_back(n);
		}
	}

	std::vector<std::pair<std::string, std::string> > vector;
	for (auto node : nodes) {
		if (!node->is_teacher()) {
			for (auto n : *node->get_list()) {
				vector.push_back(std::make_pair(node->get_id(), n->get_id()));
			}
		}
	}
	return vector;
}