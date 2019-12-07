#pragma once
#include "utils.h"
//���������� ���������
template <typename Type>
void insertionSort(Type Array[], int size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		Type key = Array[i + 1];
		int j = i;
		for (; j >= 0; --j)
		{
			if (Array[j] > key)
				Array[j + 1] = Array[j];
			else
				break;
		}
		Array[j + 1] = key;
	}
}

//���������� ��������� � �������� �������
template <typename Type>
void insertionSortBinary(Type Array[], int size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		if (Array[i + 1] >= Array[i]) continue;
		Type key = Array[i + 1];
		int idx = binarySearchForSort(Array, i + 1, key);
		int rightBound = key < Array[idx] ? idx : idx + 1;
		int j = i;
		for (; j >= rightBound; --j)
		{
			Array[j + 1] = Array[j];
		}
		Array[j + 1] = key;
	}
}