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

/********************************************************************************
 * Vertex* other(Vertex* v) ;
 * 	Purpose: 
 * 		Return the vertex in this edge that is _not_ v
 * 		other(first) = second, other(second) = first
 * 		intended to only be called with v=first or seocnd
 * 	
 * 	Entry: 
 * 		v: the vertex that should not be returned
 * 	
 * 	Exit: 
 * 		returns the vertex that is linked to <v> by this edge
 * 	
 ********************************************************************************/
template <typename V, typename E>
typename Graph<V,E>::Vertex* Graph<V,E>::Edge::other(Graph<V,E>::Vertex* v) 
{
	return (Graph<V,E>::Vertex*)(v==first?second:first);
}

/********************************************************************************
 * const Vertex* other(const Vertex* v) const;
 * 	Purpose: 
 * 		same as the other other() but const version
 * 	
 * 	Entry: 
 * 		v: the vertex that should not be returned
 * 	
 * 	Exit: 
 * 		returns the vertex that is linked to <v> by this edge
 * 	
 ********************************************************************************/
template <typename V, typename E>
const typename Graph<V,E>::Vertex* Graph<V,E>::Edge::other(const Graph<V,E>::Vertex* v) const
{
	return (v==first?second:first);
}


//other inline functions documented in Edge_undocumented.h

#endif

