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

		// Construtor do grafo
		Graph() {}

		// Adiciona nó ao grafo
		void add_node(int id) {
			nodes.push_back(new Node(id));
		}

		// Adiciona aresta ao grafo
		void add_edge(int id_source, int id_target) {
			Node* node_source, node_target;
			for (int i = 0; i < nodes.length(); i++) {
				if (nodes[i]->get_id() == id_source) {
					node_source = nodes[i];
				}
				if (nodes[i]->get_id() == id_target) {
					node_target = nodes[i];
				}
				if ((node_target != null) && (node_sourcer != null)) {
					break;
				}
			}
			node_source->add_edge(node_target);
		}

		// Realiza a contagem dos graus dos nós
		// e retorna um vetor contendo id e grau
		vector<pair<int, int> > count_degree() {
			vector<<pair<int, int> > degrees;

			for (int i = 0; i < nodes.size(); i++) {
				degrees.push_back(make_pair(nodes[i]->get_id(), nodes[i]->get_degree()));
			}
			return degrees;
		}
		

	private:

		// Classe interna para o nó
		class Node {

			public:

				// Construtores do nó
				Node() {
					this.estate = NO_VISITED;
				}

				Node(int id) {
					this.estate = NO_VISITED;
					this.id = id;
				}

				// Adiciona ligação com nó (Adicionar aresta)
				void add_edge(Node* node) {
					edge.push_back(node);
				}

				// Métodos get e set
				int get_id() {
					return this.id;
				}

				void set_id(int id) {
					this.id = id;
				}

				Estate get_estate() {
					return estate;
				}

				void set_estate(Graph::Estate estate) {
					this.estate = estate;
				}

				int get_degree() {
					return edge->size();
				}

			private:

				// Vetor contendo os nós na qual o nó atual contém ligação (arestas)
				std::vector<Node>* edge;

				// ID do nó
				int id;

				// Estado do nó	
				Graph::Estate estate;
		};

		// Vetor contendo todos os nós do grafo
		std::vector<Node>* nodes;

}
