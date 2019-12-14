#include <iostream>
#include <time.h>
#include "sorts.h"
#include "utils.h"

typedef void (*sortFunc)(double*, int);

void testSort(int size, sortFunc sort, const char name[])
{
	double* sortedArray = new double[size];

	genRandArray(sortedArray, size);
	tic();
	sort(sortedArray, size);
	std::cout << name << " random elapsed time: " << toc() << std::endl;

	genSortedArray(sortedArray, size);
	tic();
	sort(sortedArray, size);
	std::cout << name << " sorted elapsed time: " << toc() << std::endl;

	genReverseSortedArray(sortedArray, size);
	tic();
	sort(sortedArray, size);
	std::cout << name << " reverse elapsed time: " << toc() << std::endl;

	qSortKiller(sortedArray, size);
	tic();
	sort(sortedArray, size);
	std::cout << name << " killer elapsed time: " << toc() << std::endl;

	std::cout << std::endl;
	delete[] sortedArray;
}

int main()
{
	srand(time(NULL));
	int size = 1e6;
	//testSort(size, insertionSortBinary, "InsertionSortBinary");
	testSort(size, mergeSort, "MergeSort");
	testSort(size, qSortIter, "QuickSort");
	testSort(size, heapSort, "HeapSort");

	system("pause");
	return 0;
}