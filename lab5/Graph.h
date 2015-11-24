/********************************************************************************
 * Author:            Aaron Schraner
 * Date Created:      November 15, 2015
 * Last Modified:     November 15, 2015
 * Assignment number: 7 Graph
 * Filename:          Graph.h
 * 
 * Class: Graph
 * 
 * Methods: thoroughly documented in Graph_impl.h and Graph_undocumented.h
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
		//vertex class
		class Vertex;

		//edge class
		class Edge;

		//basic functions
		bool isEmpty() { return vertices.empty(); }
		void remove(Vertex* v);
		void insert(V value);

		//edge insertion/removal
		void insertEdge(Vertex* from, Vertex* to, E value);
		void insertEdge(V from, V to, E value) { insertEdge(find(from), find(to), value) ;}
		void removeEdge(Vertex* from, Vertex* to);
		void removeEdge(V from, V to) { removeEdge(find(from), find(to));}
		Edge* findEdge(Vertex* from , Vertex* to);
		Edge* findEdge(V from , V to) { return findEdge(find(from), find(to)); }

		//find a vertex given its value
		const Vertex* find(V value) const;
		Vertex* find(V value) ;

		//constructors
		Graph() {}
		Graph(const Graph<V,E> &g);
		Graph& operator=(const Graph& g);

		//traversals
		void depthFirst(void (*visit)(V data), Vertex* startNode = 0);
		void breadthFirst(void (*visit) (V), Vertex* startNode = 0);

		//friends
		template <typename U, typename X>
		friend std::ostream& operator<<(std::ostream& os, const Graph<U,X>& g);

		//get vertices
		std::list<Vertex>& getVertices() { return vertices; }
		const std::list<Vertex>& getVertices() const { return vertices; }


	private:
		//all the vertices in the graph
		std::list<Vertex> vertices;

		//all the edges in the graph
		std::set<Edge> edges;
};
#include "Vertex.h"
#include "Edge.h"
#include "Graph_impl.h"

#endif

