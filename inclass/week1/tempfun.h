template <typename T>
T* mkArray(const T& value, int numCells)
{
	T* res = new T[numCells];
	for(int i=0; i<numCells; i++)
		res[i]=value;
	return res;
}

template <typename T>
void fillArray(T* array, T value, int numCells)
{
	for(int i=0; i<numCells; i++)
		array[i]=value;
}

