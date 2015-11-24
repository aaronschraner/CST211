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
#include <iostream>
#include <sstream>
#include <climits>
#include <fstream>
#ifndef MIN
#define MIN(x,y) ((x) < (y) ? (x) : (y))
#endif

using namespace std;

typedef string airport; //supreme laziness

class connection
{
	public:
		string src, dest;
		int cost, duration;
		enum compareVal
		{
			_cost,
			_duration
		} ;
		static compareVal compareval;
		bool operator>(const connection& c) const;
		bool operator<(const connection& c) const;
		bool operator==(const connection& c) const;
		int weight() const;


};

//typedefs, prototypes, forward declaration
typedef Graph<airport,connection> airgraph;
typedef pair<int, airgraph::Vertex*> distpair;
connection::compareVal connection::compareval;

ostream& operator<<(ostream& os, const connection& c);
istream& operator>>(istream& is, connection& c);

vector<airgraph::Edge*> dijkstra(airgraph& graph, 
		airgraph::Vertex* startVert, 
		airgraph::Vertex* endVert, 
		connection::compareVal comp=connection::_duration);
void showDpath(string startval, vector<airgraph::Edge*>& dijpath, airgraph& myGraph);

//main program
int main()
{
	//create a graph with vertex values of type airport and  
	//edge values of type connection
	Graph<airport, connection> myGraph;

	//load the airports and connections from the database file
	string dbfilename = "airports.db";
	cout << "What is the name of the airport database file?\n> ";
	cin >> dbfilename;
	cout << "loading database." << endl;
	stringstream ss;
	ifstream airportstream(dbfilename);
	while(airportstream.good())
	{
		string conntype;
		airportstream >> conntype;
		if (conntype == "airport")
		{
			string apName;
			airportstream >> apName;
			myGraph.insert(apName);
			cout << "loaded airport " << apName << endl;
		}
		else if (conntype == "connection")
		{
			connection c;
			airportstream >> c;
			myGraph.insertEdge(c.src, c.dest, c);
			cout << "loaded connection " << c.src << " -> " << c.dest << endl;

		}
	}
	airportstream.close();

	//start and end values to get in the djikstra algorithm
	string startval,endval;
	cout << "What airport are you leaving from?\n> ";
	cin >> startval;
	cout << "What airport are you going to?\n> ";
	cin >> endval;

	vector<airgraph::Edge*> dijpath = dijkstra(myGraph, myGraph.find(startval), myGraph.find(endval), connection::_duration);
	cout << "Shortest path:" << endl;
	showDpath(startval, dijpath, myGraph);
	cout << "(total duration: ";
	{
		int total=0;
		for(int x=0; x < dijpath.size(); x++)
			total += dijpath[x]->getValue().weight();
		cout << total;
	}
	cout << " minutes)" << endl;
	dijpath.clear();
	dijpath = dijkstra(myGraph, myGraph.find(startval), myGraph.find(endval), connection::_cost);
	cout << "Cheapest path:" << endl;
	showDpath(startval, dijpath, myGraph);

	cout << "(total cost: $";
	{
		int total=0;
		for(int x=0; x < dijpath.size(); x++)
			total += dijpath[x]->getValue().weight();
		cout << total;
	}
	cout << ")" << endl;

	//cout << myGraph << endl;



}

void showDpath(string startval, vector<airgraph::Edge*>& dijpath, airgraph& myGraph)
{
	if (dijpath.size() > 0)
		cout << dijpath[0]->getValue().src << " -> ";
	airgraph::Vertex* prev = myGraph.find(startval);
	for(int i=0; i<dijpath.size(); i++)
	{
		cout << (prev=dijpath[i]->other(prev))->getValue() << (i<dijpath.size()-1 ? " -> " : "\n");
	}
}

vector<airgraph::Edge*> dijkstra(airgraph& graph, 
		airgraph::Vertex* startVert, 
		airgraph::Vertex* endVert, 
		connection::compareVal comp)
{
	//initialization
	int resz = graph.getVertices().size();
	vector<airgraph::Edge*> result;
	connection::compareval = comp;
	map<airgraph::Vertex*, int> index;
	bool visited[resz];
	int distances[resz];
	airgraph::Vertex* vertices[resz];
	airgraph::Vertex* locations[resz];

	//initialize the arrays for Dijkstra's algorithm
	{
		int i=0;
		for (auto it = graph.getVertices().begin(); it != graph.getVertices().end(); ++it)
		{
			distances[i] = INT_MAX; //approximately infinity
			visited[i] = 0;
			locations[i]=0;
			vertices[i] = &*it;
			index[&*it] = i++;

		}
	}
	//visit first vertex
	airgraph::Vertex* cvert = startVert;
	int findex = index[cvert];
	distances[findex] = 0;
	locations[findex] = cvert;

	//run until either the target node is reached or the number
	//of loops exceeds the number of vertices
	for(int runs=0; runs < resz && cvert != endVert; runs++)
	{
		//get the index of the current vertex
		findex = index[cvert];

		//mark it visited
		visited[findex] = true;

		//iterate through all its neighbors
		for(auto it = cvert->getNeighbors().begin(); it != cvert->getNeighbors().end(); ++it)
		{
			//setting the distance and source vertex
			int idx = index[(*it)->other(cvert)];
			int possibleDistance = distances[index[cvert]] + ((*it)->getValue()).weight();
			if (possibleDistance < distances[idx])
			{
				distances[idx]=possibleDistance;
				locations[idx]=cvert;
			}
		}

#ifdef VERBOSE
		for(int i=0; i<resz; i++)
			cout << distances[i] << " [" << (locations[i]?locations[i]->getValue():"N/A") << "], ";
		cout << endl;
#endif

		//find the shortest one-step vertex path from this vertex to its neighbors
		{
			int minindex=0;
			int min=INT_MAX;
			for (int i=0; i<resz; i++)
				if(distances[i] < min && !visited[i])
				{
					min = distances[i];
					minindex = i;
				}
#ifdef VERBOSE
			cout << "shortest path at index " << minindex << endl;
#endif
			cvert = vertices[minindex];
		}

	}
	//stores the path in reverse
	vector<airgraph::Vertex*> revpath;

	//generate the reverse path by following the locations[] array
	for(int outdex = index[cvert]; outdex != index[startVert];)
	{
		revpath.push_back(locations[outdex]);
		outdex=index[locations[outdex]];
	}

	//push the reverse path into the result in the correct order
	for(int i=revpath.size()-2; i >= 0; i--)
		if(revpath[i] && revpath[i+1])
			result.push_back(graph.findEdge(revpath[i], revpath[i+1]));

	//push the last edge onto the result path
	result.push_back(graph.findEdge(revpath[0], endVert));

	//return the result
	return result;
}

//I don't think these are actually used
bool connection::operator>(const connection& c) const
{
	return weight() > c.weight();
}

bool connection::operator<(const connection& c) const
{
	return weight() < c.weight();
}

bool connection::operator==(const connection& c) const
{
	//not sure yet
	return 0;
}

//uses a static member variable to determine if it should calculate
//dijkstra with weight based on cost or duration
int connection::weight() const
{
	switch(connection::compareval)
	{
		case connection::_cost: return cost;
		case connection::_duration: return duration;
	}
}

//displays origin, destination, cost and duration of flight
ostream& operator<<(ostream& os, const connection& c)
{
	return os << "[" << c.src << " -> " << c.dest << "] ($" << c.cost << ", " << c.duration << "min)";
}

istream& operator>>(istream& is, connection& c)
{
	return is >> c.src >> c.dest >> c.duration >> c.cost;
}
