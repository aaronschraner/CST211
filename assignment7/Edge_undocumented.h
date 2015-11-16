//documentation for every method in Graph::Edge
//here because it was much easier to write many of these functions inline

/********************************************************************************
 * bool operator<(const Graph<V,E>::Edge e) const { return e.first == first ? second < e.second : first < e.first;
 * 	Purpose: 
 * 		comparison operator for comparing Edge classes
 * 		used to maintain a sorted std::set<Edge*> in vertices
 * 		for faster find() operations
 * 	
 * 	Entry: 
 * 		e: the edge to be compared
 * 	
 * 	Exit: 
 * 		If the first pointers in this and e are different, compare the first pointers
 * 		If they are the same, compare the second ones.
 * 	
 ********************************************************************************/
/********************************************************************************
 * Vertex* getFirst() { return first;
 * 	Purpose: 
 * 		Get a pointer to the first end of this Edge
 * 	
 * 	Entry: 
 * 		no parameters
 * 	
 * 	Exit: 
 * 		returns a pointer to the vertex at the first end of this edge
 * 	
 ********************************************************************************/
/********************************************************************************
 * const Vertex* getFirst() const { return first;
 * 	Purpose: 
 * 		Same as other getFirst() but const
 * 	
 * 	Entry: 
 * 		nothing
 * 	
 * 	Exit: 
 * 		returns a const pointer to the vertex at the first end of this edge
 * 	
 ********************************************************************************/
/********************************************************************************
 * Vertex* getSecond() { return second;
 * 	Purpose: 
 * 		Get a pointer to the second end of this Edge
 * 	
 * 	Entry: 
 * 		no parameters
 * 	
 * 	Exit: 
 * 		returns a pointer to the vertex at the second end of this edge
 * 	
 ********************************************************************************/
/********************************************************************************
 * const Vertex* getSecond() const { return second;
 * 	Purpose: 
 * 		same as getSecond() but const
 * 	
 * 	Entry: 
 * 		no parameters
 * 	
 * 	Exit: 
 * 		returns a const pointer to the vertex at the second end of this edge
 * 	
 ********************************************************************************/
/********************************************************************************
 * E& getValue() { return value;
 * 	Purpose: 
 * 		Return a reference to the value of this edge
 * 		(can also be used to set the value of the edge)
 * 	
 * 	Entry: 
 * 		no parameters
 * 	
 * 	Exit: 
 * 		returns a reference to this edge's value
 * 	
 ********************************************************************************/
/********************************************************************************
 * const E& getValue() const { return value;
 * 	Purpose: 
 * 		same as the other getValue() but const
 * 	
 * 	Entry: 
 * 	
 * 	Exit: 
 * 	
 ********************************************************************************/
/********************************************************************************
 * int getWeight() const { return weight;
 * 	Purpose: 
 * 		return the weight of the edge
 * 		(not really used at all because this graph doesn't do shortest path
 * 		or anything like that yet)
 * 	
 * 	Entry: 
 * 		no parameters
 * 	
 * 	Exit: 
 * 		returns the weight of the edge
 * 	
 ********************************************************************************/

//other() and other() const are documented in their implementations

/********************************************************************************
 * void setFirst(const Vertex* f) { first = f;
 * 	Purpose: 
 * 		set the first vertex pointer to <f>
 * 	
 * 	Entry: 
 * 		f: the pointer that first should be set to
 * 	
 * 	Exit: 
 * 		returns nothing
 * 	
 ********************************************************************************/
/********************************************************************************
 * void setSecond(const Vertex* s) { second = s;
 * 	Purpose: 
 * 		set the second vertex pointer to <s>
 * 	
 * 	Entry: 
 * 		s: the pointer that second should be set to
 * 	
 * 	Exit: 
 * 		returns nothing
 * 	
 ********************************************************************************/
/********************************************************************************
 * void setWeight(int w) { weight = w;
 * 	Purpose: 
 * 		set the weight of this edge
 * 		again not used because weights aren't really used in this implementation yet
 * 	
 * 	Entry: 
 * 		w: the weight that the edge should now have
 * 	
 * 	Exit: 
 * 		sets weight to w
 * 		returns nothing
 * 	
 ********************************************************************************/
