#ifndef DUALSTREAM_H
#define DUALSTREAM_H

#include <iostream>

//class for outputting to two streams at once
//used for logging output to files and cout simultaneously
class dualstream
{
	private:
		std::ostream& os1;
		std::ostream& os2;
	public:
		dualstream(std::ostream& os1, std::ostream& os2):
			os1(os1), os2(os2) {}
		template <typename T>
			dualstream& operator<<(const T& item) 
			{
				os1 << item;
				os2 << item;
				return *this;
			}

};

#endif
