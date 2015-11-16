#include <iostream>
#include <list>
#include <set>

using namespace std;

//CLASS DECLARATIONS
template <typename V, typename E>
class Graph
{
	public:
		class Vertex;
		class Edge;
		void remove(Vertex* v);
		template <typename U, typename X>
		friend ostream& operator<<(ostream& os, const Graph<U,X>& g);
	private:
		list<Vertex> vertices;
		set<Edge> edges;
		friend int main();
};

//the done cursor

template <typename V, typename E>
class Graph<V,E>::Vertex
{
	public:
		template <typename U, typename X>
		friend ostream& operator<<(ostream& os, const Graph<U,X>& g);
		Vertex(V value):value(value) {};
	private:
		V value;
		set<Edge*> neighbors;
		friend int main();
};

template <typename V, typename E>
class Graph<V,E>::Edge
{
	public:
		template <typename U, typename X>
		friend ostream& operator<<(ostream& os, const Graph<U,X>& g);
		bool operator<(const Graph<V,E>::Edge e) const { return e.first == first ? second < e.second : first < e.first; }
		Edge(Vertex* first, Vertex* second, E value):first(first), second(second), value(value) {}
	private:
		int weight;
		Vertex* first, *second;
		E value;
		friend int main();
};

typedef Graph<int,char>::Vertex GVertex;


//  __  __    _    ___ _   _ 
// |  \/  |  / \  |_ _| \ | |
// | |\/| | / _ \  | ||  \| |
// | |  | |/ ___ \ | || |\  |
// |_|  |_/_/   \_\___|_| \_|
//                           
int main()
{
	Graph<int, char> myGraph;
	myGraph.vertices.push_back(GVertex(1));
	myGraph.vertices.push_back(GVertex(2));
	myGraph.vertices.push_back(GVertex(3));
	list<GVertex>::iterator it = myGraph.vertices.begin();
	myGraph.edges.insert(Graph<int,char>::Edge(&(*it), &(*(++it)), 'a'));
	myGraph.edges.insert(Graph<int,char>::Edge(&(*it), &(*(++it)), 'b'));

	cout << myGraph;


}

template <typename V, typename E>
void Graph<V,E>::remove(Vertex* v)
{
	for(typename set<Graph<V,E>::Edge*>::iterator it = v->neighbors.begin(); it != v->neighbors.end();)
	{
		Edge* e = *it;
		++it;
		e->first->neighbors.erase(e->first->neighbors.find(e));
		e->second->neighbors.erase(e->second->neighbors.find(e));
		edges.erase(edges.find(*e));
	}
	vertices.remove(*v);
}


template <typename V, typename E>
ostream& operator<<(ostream& os, const Graph<V,E>& g)
{
	//print elements
	os << "Elements: \n";
	for (const auto& vert:g.vertices)
	{
		os << "\t" << vert.value << endl;
	}

	os << "Edges: \n";
	for (const auto& e:g.edges)
	{
		os << "\t" << e.first->value << " <==[" << e.value <<  "]==> " << e.second->value << endl;
	}
	return os;
}
