#ifndef MASTER_H
#define MASTER_H

template <typename T>
class Master
{
	public:
		friend int main();
		//blah
		class SubClassA;
		void add(const SubClassA sc) { if(member) delete member; member = new SubClass(sc); }
	private:
		SubClassA* member;
};
#include "subc1.h"

#endif
