#include "pch.h"
#include "SortingAlogrithms.h"


const int ARRAY_SIZE = 10;

SortingAlogrithms::SortingAlogrithms()
{
}


SortingAlogrithms::~SortingAlogrithms()
{
}

void SortingAlogrithms::Swap(int newArr[], int slotSwap1, int slotSwap2)
{
	int swap = newArr[slotSwap2];
	newArr[slotSwap2] = newArr[slotSwap1];
	newArr[slotSwap1] = swap;
}

void SortingAlogrithms::SelectionSort(int newArr[])
{
	//printf("Preforming Selection Sort\n");
}
void SortingAlogrithms::BubbleSort(int newArr[], int arraySize)
{
	//printf("Preforming Bubble Sort\n");

	bool bubbleDone = false;
	while (!bubbleDone)
	{
		bool hasSwaped = false;
		for (int i = 0; i < arraySize - 1; i++)
		{
			if (newArr[i + 1] < newArr[i])
			{
				hasSwaped = true;
				Swap(newArr, i, i + 1);
			}
		}

		if (!hasSwaped)
		{
			bubbleDone = true;
		}
	}
}
void SortingAlogrithms::Merge(int newArr[], int tempArr[], int low, int mid, int high)
{
	for (int i = low; i <= high; i++)
	{
		tempArr[i] = newArr[i];
	}

	int lowest = low;
	int highest = mid + 1;
	int current = low;

	while (lowest <= mid && highest <= high)
	{
		if (tempArr[lowest] <= tempArr[highest])
		{
			newArr[current] = tempArr[lowest];
			lowest++;
		}
		else
		{
			newArr[current] = tempArr[highest];
			highest++;
		}
		current++;
	}

	int remaining = mid - lowest;
	for (int i = 0; i <= remaining; i++)
	{
		newArr[current + i] = tempArr[lowest + i];
	}

}
void SortingAlogrithms::MergeSort(int newArr[], int tempArr[], int low, int high)
{
	//printf("Preforming Merge Sort\n");
	if (low < high)
	{
		int mid = (low + high) / 2;
		//printf("Start: %i, %i, %i\n", low, mid, high);
		MergeSort(newArr, tempArr, low, mid);
		MergeSort(newArr, tempArr, mid + 1, high);
		Merge(newArr, tempArr, low, mid, high);
	}
}
void SortingAlogrithms::MergeSort(int newArr[])
{
	int tempArr[ARRAY_SIZE]{};
	MergeSort(newArr, tempArr, 0, ARRAY_SIZE - 1);
}
int SortingAlogrithms::Partition(int newArr[], int left, int right)
{
	int pivot = newArr[(left + right) / 2];

	while (left <= right)
	{
		while (newArr[left] < pivot) left++;
		while (newArr[right] > pivot) right--;

		if (left <= right)
		{
			Swap(newArr, left, right);
			left++;
			right--;
		}
	}

	return left;
}
void SortingAlogrithms::QuickSort(int newArr[], int left, int right)
{
	//printf("Preforming Quick Sort\n");
	int mid = Partition(newArr, left, right);
	if (left < mid - 1)
	{
		QuickSort(newArr, left, mid - 1);
	}
	if (mid < right)
	{
		QuickSort(newArr, mid, right);
	}
}
void SortingAlogrithms::RadixSort(int newArr[])
{
	//printf("Preforming Radix Sort\n");
}

void SortingAlogrithms::PrintNumbers(int newArr[]) {

	for (int i = 0; i < ARRAY_SIZE; i++) {
		printf("%i, ", newArr[i]);
	}
	printf("\n\n");
}
const int SortingAlogrithms::GetArraySize() {
	return ARRAY_SIZE;
}
