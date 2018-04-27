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
				
				// Adiciona em um o receive_node
				void add_receive();
				
				// Diminui em um o receive_node
				void sub_receive();
				
				// Devolve os valores originais de receive_node
				void default_receive();

				// Métodos get e set
				int get_id();

				void set_id(int id);

				Estate get_estate();

				void set_estate(Graph::Estate estate);

				int get_degree();
				
				int get_receive();

			private:

				// Vetor contendo os nós na qual o nó atual contém ligação (arestas)
				std::vector<Node*> edge;

				// ID do nó
				int id;

				// Estado do nó	
				Graph::Estate estate;
				
				// Número de arestas que o nó recebe
				int receive_node;
				
				// Número de arestas padrão que o nó recebe
				int default_receive_node;
		};

		// Construtor do grafo
		Graph();

		// Adiciona nó ao grafo
		void add_node(int id);

		// Adiciona aresta ao grafo
		void add_edge(int id_source, int id_target);
		
		// Devolve os valores originais de receive_node
		void default_receive();
		
		// Marca todos os nós como não visitados
		void default_estate();
		
		// Realiza a ordenação topológica utilizando o algoritmo de Kahn
		// Algoritmo retirado de https://pt.wikipedia.org/wiki/Ordena%C3%A7%C3%A3o_topol%C3%B3gica
		std::list<int> kahn();
		
		// Realizar a ordenação topológica utilizando o DFS
		// Algoritmo retirado de https://pt.wikipedia.org/wiki/Ordena%C3%A7%C3%A3o_topol%C3%B3gica
		std::list<int> dfs();
		
		// Método auxiliar para utilizar a ordenação DFS
		void visite(Node* node, std::list<int>* l);
		

	private:

		// Vetor contendo todos os nós do grafo
		std::vector<Node*> nodes;

};

#endif