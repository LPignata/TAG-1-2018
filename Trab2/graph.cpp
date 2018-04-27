#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
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
	Graph::nodes[id_source]->add_edge(Graph::nodes[id_target]);
	Graph::nodes[id_target]->add_receive();
}

// Devolve os valores originais de receive_node
void Graph::default_receive() {
	for (auto node : nodes) {
		node->default_receive();
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

Graph::Node::Node(int id) {
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

int Graph::Node::get_receive() {
	return receive_node;
}

// Realiza a ordenação topológica utilizando o algoritmo de Kahn
// Algoritmo retirado de https://pt.wikipedia.org/wiki/Ordena%C3%A7%C3%A3o_topol%C3%B3gica
std::list<int> Graph::kahn() {
	std::list<int> l;
	std::list<Node*> s;
	Node* n;
	
	default_receive();
	
	for (auto node : nodes) {
		if (node->get_receive() == 0) {
			s.push_back(node);
		}
	}
	
	while (!s.empty()) {
		n = s.front();
		s.pop_front();
		l.push_back(n->get_id());
		
		for(auto node : n->get_list_edge()) {
			node->sub_receive();
			if (node->get_receive() == 0) {
				s.push_back(node);
			}
		}
	}

	return l;
}

// Realizar a ordenação topológica utilizando o DFS
// Algoritmo retirado de https://aprender.ead.unb.br/pluginfile.php/502187/mod_resource/content/1/aula_graf2018_1.11_12.pdf
std::list<int> Graph::dfs() {
	std::list<int> l;

	default_estate();
	default_receive();

	for (auto node : nodes) {
		if (node->get_estate() == Estate::NO_VISITED) {
			visite(node, &l);
		}
	}
	
	return l;
}

// Método auxiliar para utilizar a ordenação DFS
void Graph::visite(Node* node, std::list<int>* l) {
	node->set_estate(Estate::CHECKED);
	
	for (auto n : node->get_list_edge()) {
		if (n->get_estate() == NO_VISITED) {
			visite(n, l);
		}
	}
	
	l->push_front(node->get_id());
}