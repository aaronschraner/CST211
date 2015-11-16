//documentation for inline Graph member functions
/********************************************************************************
 * void insertEdge(V from, V to, E value) { insertEdge(find(from), find(to), value) ;
 * 	Purpose: 
 * 		Add an edge from <from> to <to> with value <value> in the graph
 * 		Checks if an edge with the same start and end vertices exists (regardless of order)
 * 		if one does exist, returns without doind anything.
 * 		All this is handled by insertEdge(Vertex*, Vertex*, E)
 * 	
 * 	Entry: 
 * 		V from: the value to link the edge from
 * 		V to: the value to link the edge to
 * 		E value: the value to be assigned to the edge
 * 	
 * 	Exit: 
 * 		returns void
 * 	
 ********************************************************************************/
/********************************************************************************
 * bool isEmpty() { return vertices.empty();
 * 	Purpose: 
 * 		return true if the graph is empty (has no vertices)
 * 		if there are no vertices, there should automatically be no edges
 * 		because remove() also deletes edges pointing to the vertex being removed
 * 	
 * 	Entry: 
 * 		nothing
 * 	
 * 	Exit: 
 * 		returns true if graph is empty
 * 	
 ********************************************************************************/
/********************************************************************************
 * void removeEdge(V from, V to) { removeEdge(find(from), find(to));
 * 	Purpose: 
 * 		remove a vertex with the specified to and from values from the graph
 * 		uses find() and calls removeEdge(Vertex*, Vertex*);
 * 	
 * 	Entry: 
 * 		V from: the value of the first vertex in the edge to be removed
 * 		V to: the value of the second vertex in the edge to be removed
 * 	
 * 	Exit: 
 * 		returns void
 * 	
 ********************************************************************************/
