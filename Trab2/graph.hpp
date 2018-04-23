#ifndef _GRAPH_H
#define _GRAPH_H

#include <vector>

class Graph {

	public:

		// Estrutura que diz o estado do nó
		enum Estate {
			NO_VISITED,
			CHECKED,
			ATIVE,
			FINISH
		};

		// Classe interna para os nós
		class Node {
			public:
			
				// Construtores do nó
				Node();

				Node(int id);

				// Adiciona ligação com nó (Adicionar aresta)
				void add_edge(Node* node);

				// Retorna o vector de adjacência do nó
				std::vector<Node*> get_list_edge();

				// Métodos get e set
				int get_id();

				void set_id(int id);

				Estate get_estate();

				void set_estate(Graph::Estate estate);

				int get_degree();

			private:

				// Vetor contendo os nós na qual o nó atual contém ligação (arestas)
				std::vector<Node*> edge;

				// ID do nó
				int id;

				// Estado do nó	
				Graph::Estate estate;
		};

		// Construtor do grafo
		Graph();

		// Adiciona nó ao grafo
		void add_node(int id);

		// Adiciona aresta ao grafo
		void add_edge(int id_source, int id_target);

	private:

		// Vetor contendo todos os nós do grafo
		std::vector<Node*> nodes;

};

#endif