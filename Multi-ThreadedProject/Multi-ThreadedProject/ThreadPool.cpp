#include "pch.h"
#include "ThreadPool.h"


ThreadPool::ThreadPool(TaskManager* manager)
{
	_taskManager = manager;
	numOfThreads = std::thread::hardware_concurrency();
	CreateThreads();
}
ThreadPool::ThreadPool(TaskManager* manager, unsigned int threadNum)
{
	_taskManager = manager;
	numOfThreads = threadNum;
	CreateThreads();
}


ThreadPool::~ThreadPool()
{
}

void ThreadPool::CreateThreads()
{
	for (unsigned int i = 0; i < numOfThreads; i++)
	{
		MikeThread* newThread = new MikeThread(_taskManager);
		newThread->Init(newThread);
		threadPool.push_back(newThread);
	}
}

void ThreadPool::ShutDown()
{
	TaskManager::shutDown = true;
	for(unsigned int i = 0; i < threadPool.size(); i++)
	{
		threadPool[i]->myThread->join();
	}
	_taskManager->ShutDown();
}
