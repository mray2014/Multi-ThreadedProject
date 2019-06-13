#pragma once
#include "TaskManager.h"
#include "MikeThread.h"

class ThreadPool
{
public:

	ThreadPool(TaskManager* manager);
	ThreadPool(TaskManager* manager, unsigned int threadNum);
	~ThreadPool();

	void CreateThreads();
	void ShutDown();

	std::vector<MikeThread*> threadPool;
	TaskManager* _taskManager;
	unsigned int numOfThreads = 4;

};

