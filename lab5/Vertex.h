/********************************************************************************
 * Author:            Aaron Schraner
 * Date Created:      November 15, 2015
 * Last Modified:     November 15, 2015
 * Assignment number: 7 Graphs
 * Filename:          Vertex.h
 * 
 * Class: Vertex
 * 
 * Methods: documented in Vertex_undocumented.h
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
		//constructor given value
		Vertex(V value):value(value) {};

		//get the value of this vertex
		V& getValue() { return value; }
		const V& getValue() const { return value; }

		//get a list of this vertex's neighbors
		std::set<Edge*>& getMNeighbors() { return neighbors; }
		const std::set<Edge*>& getNeighbors() const { return neighbors; }

	private:
		//the value of this vertex
		V value;

		//a set of this vertex's neighbor edge pointers
		std::set<Edge*> neighbors;
};

//more thorough documentation in Vertex_undocumented.h
#include "Vertex_impl.h"

#endif

