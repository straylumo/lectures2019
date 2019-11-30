#pragma once
#include <stdlib.h>
#include <iostream>
#include <chrono>

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::milliseconds;

static high_resolution_clock::time_point start;

void tic()
{
	start = high_resolution_clock::now();
}

long toc()
{
	return duration_cast<milliseconds>(high_resolution_clock::now() - start).count();
}

template <typename Type>
void Swap(Type& a, Type& b)
{
	Type tmp = a;
	a = b;
	b = tmp;
}

void genRandArray(double arr[], int size)
{
	for (int i = 0; i < size; ++i)
		arr[i] = (double) rand() / RAND_MAX;
}

void genSortedArray(double arr[], int size)
{
	for (int i = 0; i < size; ++i)
		arr[i] = (double)i / size;
}

void genReverseSortedArray(double arr[], int size)
{
	genSortedArray(arr, size);
	for (int i = 0; i < size / 2; ++i)
		Swap(arr[i], arr[size - i - 1]);
}

template <typename Type>
void printArray(Type arr[], int size)
{
	for (int i = 0; i < size; ++i)
		std::cout << arr[i] << ' ';
	std::cout << std::endl;
}

template <typename Type>
void copyArray(Type source[], Type destination[], int size)
{
	for (int i = 0; i < size; ++i)
		destination[i] = source[i];
}

template <typename Type>
bool Greater(Type left, Type right)
{
	return left > right;
}

template <typename Type>
int binarySearchRecursive(Type arr[], int size, Type val)
{
	if (size == 0) return -1;
	int middle = size / 2;
	if (arr[middle] == val)
		return middle;

	if (middle == 0)
		return -1;

	if (arr[middle] > val)
		return binarySearchRecursive(arr, middle, val);
	
	int idx = binarySearchRecursive(arr + middle + 1, size - middle - 1, val);
	return idx >=0 ? middle + 1 + idx : idx;
}

template <typename Type>
int binarySearchIterative(Type arr[], int size, Type val)
{
	int leftBound = 0;
	int rightBound = size - 1;
	int middle = (leftBound + rightBound) / 2;
	while (leftBound <= rightBound)
	{
		if (arr[middle] == val) 
			return middle;
		if (arr[middle] > val)
			rightBound = middle - 1;
		else
			leftBound = middle + 1;
		middle = (leftBound + rightBound) / 2;
	}
	return -1;
}

template <typename Type>
int binarySearchForSort(Type arr[], int size, Type val)
{
	int leftBound = 0;
	int rightBound = size - 1;
	int middle = (leftBound + rightBound) / 2;
	while (leftBound < rightBound)
	{
		if (arr[middle] > val)
			rightBound = middle - 1;
		else
			leftBound = middle + 1;
		middle = (leftBound + rightBound) / 2;
	}
	return middle;
}