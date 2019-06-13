
#include "pch.h"
#include "ThreadPool.h"
#include "SortingAlogrithms.h"
#include <iostream>
#include <Windows.h>


void SortingStuff()
{
	SortingAlogrithms sorting = SortingAlogrithms();
	const int size = sorting.GetArraySize();
	int myArray[10];

	for (int i = 0; i < size; i++) {
		myArray[i] = rand() % 100;
	}
	printf("Unsorted numbers\n");
	sorting.PrintNumbers(myArray);

	//printf("Preforming Selection Sort\n");
	// sorting.SelectionSort(myArray);

	// printf("Preforming Bubble Sort\n");
	// sorting.BubbleSort(myArray, ARRAY_SIZE);

	printf("Preforming Merge Sort\n");
	sorting.MergeSort(myArray);

	// printf("Preforming Quick Sort\n");
	// sorting.QuickSort(myArray, 0, size - 1);

	// printf("Preforming Radix Sort\n");
	// sorting.RadixSort(myArray);

	printf("\nSorted numbers\n");
	sorting.PrintNumbers(myArray);
}

void Add(int x, int y)
{
	int finalNum = x + y;
	printf(""+finalNum);
}

class NewTask : public ITask {

	bool CheckForBlockDependencies() override
	{
		return dependenciesCount > 0;
	}
	void DoWork(void*) override
	{
	
	}
	void SignalDependenciesDone() override
	{
	
	}
	void* GetTaskFunction() override
	{
	
	}

	ProgressStatus currentProgressStatus;
	PriorityStatus priorityStatus;
	std::vector<ITask> depeneciesWaitingOnMe;
	std::atomic<int> dependenciesCount = 0;
	int taskNumber = 0;
};

int main()
{

	srand(time(NULL));
	//SortingStuff();


	TaskManager* taskManager = new TaskManager();
	ThreadPool* threadPool = new ThreadPool(taskManager, 4);






	while (!GetAsyncKeyState(VK_RETURN))
	{
	}
	threadPool->ShutDown();
	delete threadPool;
	delete taskManager;
}




