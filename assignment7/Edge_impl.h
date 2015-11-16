/********************************************************************************
 * Author:            Aaron Schraner
 * Date Created:      November 15, 2015
 * Last Modified:     November 15, 2015
 * Assignment number: 7 Graph
 * Filename:          Edge_impl.h
 * 
 ********************************************************************************/
#ifndef EDGE_IMPL_H
#define EDGE_IMPL_H
#include "Vertex.h"

template <typename V, typename E>
typename Graph<V,E>::Vertex* Graph<V,E>::Edge::other(Graph<V,E>::Vertex* v) 
{
	return (Graph<V,E>::Vertex*)(v==first?second:first);
}

template <typename V, typename E>
const typename Graph<V,E>::Vertex* Graph<V,E>::Edge::other(const Graph<V,E>::Vertex* v) const
{
	return (v==first?second:first);
}

#endif

