#include <iostream>
#include "Graph.h"

using namespace std;


void disp(int v)
{
	cout << "\t" << v << endl;
}

int main()
{
	Graph<int, char> myGraph;
	if(myGraph.isEmpty())
		cout << "graph is empty." << endl;
	cout << "adding elements" << endl;

	for(int i=1; i<= 6; i++)
	{	
		myGraph.insert(i);
	}

	//graph diagram
	//
	//(1)----d----(2)
	// | \       / | \
	// |  a     b  |  e
	// |   \   /   |   \
	// i    (4)    f    (3)
	// |       \   |   /
	// |        c  |  g
	// |         \ | /
	//(5)----h----(6)
	//
	myGraph.insertEdge(1, 4, 'a');
	myGraph.insertEdge(2, 4, 'b');
	myGraph.insertEdge(6, 4, 'c');

	myGraph.insertEdge(1,2, 'd');
	myGraph.insertEdge(2,3, 'e');
	myGraph.insertEdge(2,6, 'f');
	myGraph.insertEdge(3,6, 'g');
	myGraph.insertEdge(6,5, 'h');
	myGraph.insertEdge(1,5, 'i');


	cout << myGraph << endl;

	cout << "depth first traversal: " << endl;
	myGraph.depthFirst(disp);
	cout << endl;

	cout << "breadth first traversal: " << endl;
	myGraph.breadthFirst(disp);
	cout << endl;

}

