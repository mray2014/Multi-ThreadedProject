#pragma once
#include <stdio.h>
#include <random>
#include <time.h>

class SortingAlogrithms
{
public:
	SortingAlogrithms();
	~SortingAlogrithms();

	void Swap(int newArr[], int slotSwap1, int slotSwap2);
	void SelectionSort(int newArr[]);
	void BubbleSort(int newArr[], int arraySize);
	void Merge(int newArr[], int tempArr[], int low, int mid, int high);
	void MergeSort(int newArr[], int tempArr[], int low, int high);
	void MergeSort(int newArr[]);
	int Partition(int newArr[], int left, int right);
	void QuickSort(int newArr[], int left, int right);
	void RadixSort(int newArr[]);
	void PrintNumbers(int newArr[]);
	const int GetArraySize();
};

