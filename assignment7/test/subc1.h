#ifndef SUBC1_H
#define SUBC1_H

template <typename T>
class Master<T>::SubClassA
{
	friend int main();
	//stuff
	private:
		int v;
	public:
		SubClassA():v=0;
};
#endif
