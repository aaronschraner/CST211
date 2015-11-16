/********************************************************************************
 * Author:            Aaron Schraner
 * Date Created:      November 15, 2015
 * Last Modified:     November 15, 2015
 * Assignment number: 7 Graph
 * Filename:          Edge.h
 * 
 * Class: Edge
 * 
 * Methods: 
 * 
 ********************************************************************************/
#ifndef EDGE_H
#define EDGE_H
#include "Vertex.h"

template < typename V, typename E >
class Graph<V,E>::Edge
{
	public:
		//comparison (for use in std::set<Edge>)
		bool operator<(const Graph<V,E>::Edge e) const { return e.first == first ? second < e.second : first < e.first; }
		
		//constructor
		Edge(Vertex* first, Vertex* second, E value):first(first), second(second), value(value) {}
		
		//get the vertex that isn't <v>
		const Vertex* other(const Vertex* v) const;
		Vertex* other(Vertex* v) ;

		//simple inline accessors
		const E& getValue() const { return value; }
		E& getValue() { return value; }

		int getWeight() const { return weight; }
		void setWeight(int w) { weight = w; }

		const Vertex* getFirst() const { return first; }
		const Vertex* getSecond() const { return second; }
		Vertex* getFirst() { return first; }
		Vertex* getSecond() { return second; }

		void setFirst(const Vertex* f) { first = f; }
		void setSecond(const Vertex* s) { second = s; }

	private:
		int weight;
		const Vertex* first, *second;
		E value;
};
#include "Edge_impl.h"

#endif

