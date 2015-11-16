/********************************************************************************
 * Author:            Aaron Schraner
 * Date Created:      November 15, 2015
 * Last Modified:     November 15, 2015
 * Assignment number: 7 Graph
 * Filename:          Graph_impl.h
 * 
 *
 *  ___________
 * ( . . . . . )                          
 *  ----------- 
 *     o                                  ___-------___
 *      o                             _-~~             ~~-_
 *       o                         _-~                    /~-_
 *              /^\__/^\         /~  \                   /    \
 *            /|  O|| O|        /      \_______________/        \        <big data structures assignment>
 *           | |___||__|      /       /                \          \
 *           |          \    /      /                    \          \
 *           |   ________) /______/                        \_________ \
 *           |         / /         \                      /            \
 *            \         \^\\         \                  /               \     /
 *              \         ||           \______________/      _-_       //\__//
 *                \       ||------_-~~-_ ------------- \ --/~   ~\    || __/
 *                  ~-----||====/~     |==================|       |/~~~~~
 *                   (_(__/  ./     /                    \_\      \.
 *                          (_(___/                         \_____)_)
 ********************************************************************************/
#ifndef GRAPH_IMPL_H
#define GRAPH_IMPL_H
#include <iostream>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
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

template <typename V, typename E>
void Graph<V,E>::insert(V value)
{
	vertices.push_back(Vertex(value));
}

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
	std::pair<typename std::set<Graph<V,E>::Edge>::iterator,bool> edgeit = edges.insert(Edge(from, to, value));
	from->getMNeighbors().insert((Graph<V,E>::Edge*)&*edgeit.first);
	to->getMNeighbors().insert((Graph<V,E>::Edge*)&*edgeit.first);


}

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

template <typename V, typename E>
typename Graph<V,E>::Vertex* Graph<V,E>::find(V value) 
{
	for (Vertex& v:vertices)
		if(v.getValue() == value)
			return &v;

	//not found
	return 0;
}

template <typename V, typename E>
const typename Graph<V,E>::Vertex* Graph<V,E>::find(V value) const
{
	for (const Vertex& v:vertices)
		if(v.getValue() == value)
			return &v;

	//not found
	return 0;
}

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
}

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
	


template <typename V, typename E>
std::ostream& operator<<(std::ostream& os, const Graph<V,E>& g)
{
	//print elements
	os << "Elements: \n";
	for (const auto& vert:g.vertices)
	{
		os << "\t" << vert.getValue() << " ( ";//<< std::endl;
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

#endif

