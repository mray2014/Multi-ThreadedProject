
#include "pch.h"
#include "ThreadPool.h"
#include <iostream>

int main()
{

	//int(*addFucn)(int, int) = Add;
	//int result = addFucn(2, 3);

	//

	//void* voidFucnPointer = Add;
	//int result2 = reinterpret_cast<int(*)(int, int)>(voidFucnPointer)(2,3);

	TaskManager* taskManager = new TaskManager();
	ThreadPool* threadPool = new ThreadPool(taskManager, 4);


    std::cout << "Hello World!\n"; 

	threadPool->ShutDown();
	delete threadPool;
	delete taskManager;
}

//int Add(int x, int y)
//{
//	return x + y;
//}

