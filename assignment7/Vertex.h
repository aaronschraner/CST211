/********************************************************************************
 * Author:            Aaron Schraner
 * Date Created:      November 15, 2015
 * Last Modified:     November 15, 2015
 * Assignment number: 7 Graphs
 * Filename:          Vertex.h
 * 
 * Class: Vertex
 * 
 * Methods: 
 *     TODO //TODO TODO ():
 *         TODO
 * 
 * 
 ********************************************************************************/
#ifndef VERTEX_H
#define VERTEX_H
#include <iostream>
#include <list>
#include "Graph.h"

template < typename V, typename E >
class Graph<V,E>::Vertex
{
	public:
		Vertex(V value):value(value) {};

		V& getValue() { return value; }
		const V& getValue() const { return value; }

		std::set<Edge*>& getMNeighbors() { return neighbors; }
		const std::set<Edge*>& getNeighbors() const { return neighbors; }

	private:
		V value;
		std::set<Edge*> neighbors;
};
#include "Vertex_impl.h"

#endif

