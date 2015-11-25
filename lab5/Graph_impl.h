/********************************************************************************
 * Author:            Aaron Schraner
 * Date Created:      November 15, 2015
 * Last Modified:     November 24, 2015
 * Assignment number: 7 Graph
 * Filename:          Graph_impl.h
 * 
 ********************************************************************************/
#ifndef GRAPH_IMPL_H
#define GRAPH_IMPL_H
#include <iostream>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>

/********************************************************************************
 * void remove(Vertex* v);
 * 	Purpose: 
 * 		remove a vertex <v> from the graph
 * 		also unlink any edges that point to v
 * 	
 * 	Entry: 
 * 		v: pointer to the vertex to be removed
 * 	
 * 	Exit: 
 * 		removes the vertex and returns nothing
 * 	
 ********************************************************************************/
template <typename V, typename E>
void Graph<V,E>::remove(Vertex* v)
{
	//iterate through all the vertex's edges
	for(auto it = v->neighbors.begin(); it != v->neighbors.end();)
	{
		//need to get a copy of the edge pointer before it is deleted
		Edge* e = *it;
		++it;
		//unlink the edge from its end vertices
		e->getFirst()->neighbors.erase(e->first->neighbors.find(e));
		e->getFirst()->second->neighbors.erase(e->second->neighbors.find(e));

		//delete the edge
		edges.erase(edges.find(*e));
	}
	vertices.remove(*v);
}

/********************************************************************************
 * void insert(V value);
 * 	Purpose: 
 * 		insert a value into the graph
 * 		by default the resulting vertex is not linked to any other vertices
 * 	
 * 	Entry: 
 * 		value: the  value of the vertex that should be created
 * 	
 * 	Exit: 
 * 		returns void
 * 	
 ********************************************************************************/
template <typename V, typename E>
void Graph<V,E>::insert(V value)
{
	vertices.push_back(Vertex(value));
}

/********************************************************************************
 * void insertEdge(Vertex* from, Vertex* to, E value);
 * 	Purpose: 
 * 		Creates an edge with end points <to> and <from> with value <value>
 * 		and inserts it into the graph.
 * 		first creates the edge and appends it to the graphs set of edges,
 * 		then links the vertices from and to to that edge
 * 	
 * 	Entry: 
 * 		from: the vertex to link the edge from
 * 		to: the vertex to link the edge to
 * 		value: the value to assign the edge
 * 	
 * 	Exit: 
 * 		returns void
 * 	
 ********************************************************************************/
template <typename V, typename E>
void Graph<V,E>::insertEdge(Vertex* from, Vertex* to, E value)
{
	//check if edge already exists
	for (auto n : from -> getNeighbors())
	{
		if(n->other(from) == to)
			return;
	}
	
	//if it doesn't add it to <edges>
	//insert a new edge with the specified vertices and store the location of it
	std::pair<typename std::set<Graph<V,E>::Edge>::iterator,bool> edgeit = edges.insert(Edge(from, to, value));

	//link that edge to <from> and <to>
	from->getMNeighbors().insert((Graph<V,E>::Edge*)&*edgeit.first);
	to->getMNeighbors().insert((Graph<V,E>::Edge*)&*edgeit.first);


}

/********************************************************************************
 * void removeEdge(Vertex* from, Vertex* to);
 * 	Purpose: 
 * 		Remove a vertex with the given from and to vertices from the graph
 * 		first find the requested edge in <edges> and get a pointer to it,
 * 		then unlink it from its first and second vertices
 * 		then remove it from <edges>
 * 	
 * 	Entry: 
 * 		//TODO: change "remove a vertex" to "remove the edge"
 * 		from: pointer to the first vertex in the edge to be deleted
 * 		to: pointer to the second vertex in the edge to be deleted
 * 	
 * 	Exit: 
 * 		returns void
 * 	
 ********************************************************************************/
template <typename V, typename E>
void Graph<V,E>::removeEdge(Vertex* from, Vertex* to)
{
	for (auto it = from -> getNeighbors().begin(); it != from->getNeighbors().end();)
		if(it->other(from) == to)
		{
			Edge* e = *it;
			//delete to's edge pointer
			to->getNeighbors().erase(to->getNeighbors().find(e));
			from->getNeighbors().erase(from->getNeighbors().find(e));
			edges.erase(edges.find(*e));

		}
}

/********************************************************************************
 * Vertex* find(V value) ;
 * 	Purpose: 
 * 		find and return a pointer to the vertex whose value matches <value>
 * 		returns NULLPTR if search fails, searches from first created vertex
 * 		to last.
 * 	
 * 	Entry: 
 * 		V value: the value to search for (uses operator== to check if match)
 * 	
 * 	Exit: 
 * 		returns a pointer to the vertex if find succeeds,
 * 		otherwise returns 0 (NULLPTR)
 * 	
 ********************************************************************************/
template <typename V, typename E>
typename Graph<V,E>::Vertex* Graph<V,E>::find(V value) 
{
	for (Vertex& v:vertices)
		if(v.getValue() == value)
			return &v;

	//not found
	return 0;
}

/********************************************************************************
 * const Vertex* find(V value) const;
 * 	Purpose: 
 * 		same as other find() but const version
 * 	
 * 	Entry: 
 * 	
 * 	Exit: 
 * 	
 ********************************************************************************/
template <typename V, typename E>
const typename Graph<V,E>::Vertex* Graph<V,E>::find(V value) const
{
	for (const Vertex& v:vertices)
		if(v.getValue() == value)
			return &v;

	//not found
	return 0;
}

/********************************************************************************
 * Graph& operator=(const Graph& g);
 * 	Purpose: 
 * 		assignment operator for graph class
 * 	
 * 	Entry: 
 * 		copies all of the vertices from <g> into this graph and rebuilds the edges
 * 		g: the graph to be copied/assigned into this graph
 * 	
 * 	Exit: 
 * 		returns a reference to the newly created graph copy
 * 		(currently doesn't work)
 * 	
 ********************************************************************************/
template <typename V, typename E>
Graph<V,E>& Graph<V,E>::operator=(const Graph<V,E>& g)
{
	vertices.clear();
	edges.clear();
	std::map<Graph<V,E>::Vertex*, Graph<V,E>::Vertex*> newptrs;
	for( auto it = g.vertices.begin(); it != g.vertices.end(); ++it)
	{
		vertices.push_back(Graph<V,E>::Vertex(it->getValue()));
		newptrs.insert(std::pair<Graph<V,E>::Vertex*, Graph<V,E>::Vertex*>(&*it, &(*vertices.rbegin())));
	}
	edges = g.edges;
	for(auto it = edges.begin(); it != edges.end(); ++it)
	{
		it->setFirst(newptrs[it->getFirst()]);
		it->setSecond(newptrs[it->getSecond()]);
	}
	return *this;
}

/********************************************************************************
 * Graph(const Graph<V,E> &g);
 * 	Purpose: 
 * 		copy constructor for graph class
 * 		creates a copy of <g> with the same structure and edge and node values
 * 	
 * 	Entry: 
 * 		g: the graph to be copied
 * 	
 * 	Exit: 
 * 		constructs the graph and exists
 * 		(currently doesn't work)
 * 	
 ********************************************************************************/
template <typename V, typename E>
Graph<V,E>::Graph(const Graph<V,E> &g)
{
	std::map<const Graph<V,E>::Vertex*, Graph<V,E>::Vertex*> newptrs;
	for( auto it = g.vertices.begin(); it != g.vertices.end(); ++it)
	{
		vertices.push_back(Graph<V,E>::Vertex(it->getValue()));
		newptrs.insert(std::pair<const Graph<V,E>::Vertex*, Graph<V,E>::Vertex*>(&*it, &(*vertices.rbegin())));
	}
	this->edges = g.edges;
	for(auto it = this->edges.begin(); it != edges.end(); ++it)
	{
		Edge& e = (Edge&)*it;
		e.setFirst(newptrs[it->getFirst()]);
		e.setSecond(newptrs[it->getSecond()]);
	}
}

/********************************************************************************
 * void depthFirst(void (*visit)(V data), Vertex* startNode = 0);
 * 	Purpose: 
 * 		Traverse the graph starting at <startNode> (defaults to first vertex)
 * 		executing visit() on each vertex's value.
 * 	
 * 	Entry: 
 * 		visit: a pointer to a function of the form void function(V value)
 * 		gets called on every vertex in the graph as it is traversed
 * 		startNode: the node to start traversing at (defaults to first added vertex)
 * 	
 * 	Exit: 
 * 		executing visit() on each vertex's value.
 * 	
 ********************************************************************************/
template <typename V, typename E>
void Graph<V,E>::depthFirst(void (*visit) (V), Vertex* startNode  )
{
	std::map<Graph<V,E>::Vertex*, bool> processed;
	for(auto it = vertices.begin(); it != vertices.end(); ++it)
		processed.insert(std::pair<Graph<V,E>::Vertex*, bool>(&*it, false));

	if(!startNode)
		startNode = &*(vertices.begin());

	std::stack<Graph<V,E>::Vertex*> vertstack;
	vertstack.push(startNode);

	while(!vertstack.empty())
	{
		Graph<V,E>::Vertex* v = vertstack.top();
		vertstack.pop();

		if(!processed[v])
		{
			visit(v->getValue());
			processed[v] = true;
			for(typename std::set<Graph<V,E>::Edge*>::iterator e=v->getNeighbors().begin(); e != v->getNeighbors().end(); ++e)
				vertstack.push((*e)->other(v));
		}
	}
}

/********************************************************************************
 * void breadthFirst(void (*visit) (V), Vertex* startNode = 0);
 * 	Purpose: 
 * 		Traverse the graph starting at <startNode> (defaults to first vertex)
 * 		executing visit() on each vertex's value.
 * 	
 * 	Entry: 
 * 		visit: a pointer to a function of the form void function(V value)
 * 		gets called on every vertex in the graph as it is traversed
 * 		startNode: the node to start traversing at (defaults to first added vertex)
 * 	
 * 	Exit: 
 * 		executes visit() on each vertex and exits
 * 	
 ********************************************************************************/
template <typename V, typename E>
void Graph<V,E>::breadthFirst(void (*visit) (V), Vertex* startNode)
{
	std::map<Graph<V,E>::Vertex*, bool> processed;

	for(auto it = vertices.begin(); it != vertices.end(); ++it)
		processed.insert(std::pair<Graph<V,E>::Vertex*, bool>(&*it, false));

	if(!startNode)
		startNode = &*(vertices.begin());

	std::queue<Graph<V,E>::Vertex*> vertq;

	processed[startNode] = true;
	vertq.push(startNode);

	while(!vertq.empty())
	{
		Graph<V,E>::Vertex* v = vertq.front();
		visit(v->getValue());
		vertq.pop();
		for(auto e:v->getNeighbors())
			if(!processed[e->other(v)])
			{
				processed[e->other(v)] = true;
				vertq.push(e->other(v));
			}
	}
}
	
/********************************************************************************
 * std::ostream& operator<<(std::ostream& os, const Graph<U,X>& g);
 * 	Purpose: 
 * 		friend stream output operator for graph class
 * 		outputs all vertices with the value of every vertex they are linked to
 * 		then outputs every bidirectional link
 * 	
 * 	Entry: 
 * 		os: the output stream to print to
 * 		g: the graph to be printed
 * 		
 * 	
 * 	Exit: 
 * 		prints vertices and their edges with what the edges point to in the format
 * 		vertex ( [edgename]> edgevertex | [edgename]> edgevertex )
 * 		then prints all bidirectional links in the format
 * 		vertex <==[edgevalue]==> vertex
 * 	
 ********************************************************************************/
template <typename V, typename E>
std::ostream& operator<<(std::ostream& os, const Graph<V,E>& g)
{
	//print elements
	os << "Elements: \n";
	for (const auto& vert:g.vertices)
	{
		os << "\t" << vert.getValue() << " ( ";
		for(const auto e:vert.getNeighbors())
			os << "[" << e->getValue() << "]> " << e->other(&vert) -> getValue() << (e==*(vert.getNeighbors().rbegin()) ? " )\n" : " | ");
	}

	os << "Edges: \n";
	for (const auto& e:g.edges)
	{
		os << "\t" << e.getFirst()->getValue() << " <==[" << e.getValue() <<  "]==> " << e.getSecond()->getValue() << std::endl;
	}
	return os;
}

template <typename V, typename E>
typename Graph<V,E>::Edge* Graph<V,E>::findEdge(Vertex* from, Vertex* to)
{
	for (auto it = from -> getNeighbors().begin(); it != from->getNeighbors().end();++it)
		if ((*it)->other(from) == to)
			return *it;
	return 0;
}

#endif
