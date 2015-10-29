#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class ArrayContainer
{
	private:
		enum arrayType
		{
			_vector,
			_carray,
			_myarray
		} type;
		void* vptr;
		int length;
	public:
		ArrayContainer(vector<T>* vptr):
			type(_vector), vptr(&vptr), length(vptr->size())
	{}
		ArrayContainer(T* arr, int len):
			type(_carray), vptr(arr), length(len)
	{}
		T& operator[](int index)
		{
			switch(type)
			{
				case _vector:
					return (*((vector<T>)vptr))[index];
				case _carray:
				case _myarray:
					return ((T*)vptr)[index];
			}
		}
};
template <typename T>
int getAt(ArrayContainer<T> ac, int index)
{
	return ac[index];
}

int main()
{
	vector<int> myVec;
	for(int i=0; i<10; i++)
		myVec.push_back(i);
	cout << getAt(ArrayContainer<int>(&myVec), 3) << endl;
}


