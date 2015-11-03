#ifndef SHELL_H
#define SHELL_H
#include "swap.h"
#include "sortable_polymorphism.h"

POLYMORPHISM(shellSort);

template <typename T>
void shellSort(Sortable<T> array)
{
	T temp;
	int j;
	std::vector<int> gaps = {701, 301, 132, 57, 23, 10, 4, 1};
	for(int gap: gaps)
	{
		for(int i=gap; i < array.size; i++)
		{
			temp = array[i];

			for(j = i; j >= gap && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j-gap];
			}
			array[j] = temp;

		}
	}
}


#endif
