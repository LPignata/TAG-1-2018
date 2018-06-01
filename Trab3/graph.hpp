#ifndef _GRAPH_H
#define _GRAPH_H

#include <vector>
#include <list>

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

				Node(std::string id);

				// Adiciona ligação com nó (Adicionar aresta)
				void add_edge(Node* node);

				// Retorna o vector de adjacência do nó
				std::vector<Node*> get_list_edge();
				
				// Coloca valores padrão para a execução dos algoritmos
				void set_default();

				// Métodos get e set
				std::string get_id();

				void set_id(std::string id);

				Estate get_estate();

				void set_estate(Graph::Estate estate);

				int get_qualifications();

				void set_qualifications(int qualifications);

				int get_vacations();

				void set_vacations(int vacations);

				int get_degree();
				
				int get_receive();

				bool is_teacher();


			private:

				// Vetor contendo os nós na qual o nó atual contém ligação (arestas)
				std::vector<Node*> edge;

				// ID do nó
				std::string id;

				// Estado do nó	
				Graph::Estate estate;

				// Número de habilitações
				int qualifications;

				// Número de vagas
				int vacations;

				// Número de vagas disponíveis
				int free_vacations;

				// Número do índice do vetor de adjacência
				int index;
		};

		// Construtor do grafo
		Graph();

		// Adiciona nó ao grafo
		void add_node(std::string id);

		void add_node(std::string id, int qualifications, int vacations);

		// Adiciona aresta ao grafo
		void add_edge(std::string id_source, std::string id_target);
		
		// Coloca valores padrão nos nós
		void set_default();
		
		// Marca todos os nós como não visitados
		void default_estate();

		// Algoritmo ótimo para professores
		std::vector<std::pair<std::string, std::string> > to_teachers();
		
	private:

		// Vetor contendo todos os nós do grafo
		std::vector<Node*> nodes;

};

#endif