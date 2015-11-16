/********************************************************************************
 * Author:            Aaron Schraner
 * Date Created:      November 15, 2015
 * Last Modified:     November 15, 2015
 * Assignment number: 7 Graph
 * Filename:          main.cpp
 * 
 * Purpose: driver file for Graph class
 * 
 ********************************************************************************/#include <iostream>
#include "Graph.h"

using namespace std;

//display an integer with an indent
//(used for graph traversals)
void disp(int v)
{
	cout << "\t" << v << endl;
}

int main()
{
	//create a graph with vertex values of type int and  
	//edge values of type char
	Graph<int, char> myGraph;

	//check if it's empty
	if(myGraph.isEmpty())
		cout << "graph is empty." << endl;

	//add numbers 1-6 to it
	cout << "adding elements" << endl;

	for(int i=1; i<= 6; i++)
	{	
		myGraph.insert(i);
	}

	//link the graph so it looks like this

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


	//print the graph
	cout << myGraph << endl;


	//test depth-first traversal
	cout << "depth first traversal: " << endl;
	myGraph.depthFirst(disp);
	cout << endl;

	//test breadth-first traversal
	cout << "breadth first traversal: " << endl;
	myGraph.breadthFirst(disp);
	cout << endl;

}

