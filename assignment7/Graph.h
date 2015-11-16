/********************************************************************************
 * Author:            Aaron Schraner
 * Date Created:      November 15, 2015
 * Last Modified:     November 15, 2015
 * Assignment number: 7 Graph
 * Filename:          Graph.h
 * 
 * Class: Graph
 * 
 * Methods: 
 * 
 *  ________________________________________________ 
 * /  ___ _____   ____  _____ ____ ___ _   _ ____   \
 * | |_ _|_   _| | __ )| ____/ ___|_ _| \ | / ___|  |
 * |  | |  | |   |  _ \|  _|| |  _ | ||  \| \___ \  |
 * |  | |  | |   | |_) | |__| |_| || || |\  |___) | |
 * | |___| |_|   |____/|_____\____|___|_| \_|____/  |
 * \                                                /
 *  ------------------------------------------------ 
 * \                             .       .
 *  \                           / `.   .' " 
 *   \                  .---.  <    > <    >  .---.
 *    \                 |    \  \ - ~ ~ - /  /    |
 *          _____          ..-~             ~-..-~
 *         |     |   \~~~\.'                    `./~~~/
 *        ---------   \__/                        \__/
 *       .'  O    \     /               /       \  " 
 *      (_____,    `._.'               |         }  \/~~~/
 *       `----.          /       }     |        /    \__/
 *             `-.      |       /      |       /      `. ,~~|
 *                 ~-.__|      /_ - ~ ^|      /- _      `..-'   
 *                      |     /        |     /     ~-.     `-. _  _  _
 *                      |_____|        |_____|         ~ - . _ _ _ _ _>
 *
 ********************************************************************************/
#ifndef GRAPH_H
#define GRAPH_H
#include <list>
#include <set>
template < typename V, typename E >
class Graph
{
	public:
		class Vertex;
		class Edge;

		bool isEmpty() { return vertices.empty(); }
		void remove(Vertex* v);
		void insert(V value);

		void insertEdge(Vertex* from, Vertex* to, E value);
		void insertEdge(V from, V to, E value) { insertEdge(find(from), find(to), value) ;}
		void removeEdge(Vertex* from, Vertex* to);
		void removeEdge(V from, V to) { removeEdge(find(from), find(to));}

		const Vertex* find(V value) const;
		Vertex* find(V value) ;

		Graph() {}
		Graph(const Graph<V,E> &g);
		Graph& operator=(const Graph& g);

		void depthFirst(void (*visit)(V data), Vertex* startNode = 0);
		void breadthFirst(void (*visit) (V), Vertex* startNode = 0);

		template <typename U, typename X>
		friend std::ostream& operator<<(std::ostream& os, const Graph<U,X>& g);

	private:
		std::list<Vertex> vertices;
		std::set<Edge> edges;
};
#include "Vertex.h"
#include "Edge.h"
#include "Graph_impl.h"

#endif

