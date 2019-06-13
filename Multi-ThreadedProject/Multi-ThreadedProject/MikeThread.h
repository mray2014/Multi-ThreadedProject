#pragma once
#include "TaskManager.h"
#include <thread>

class MikeThread
{
public:
	MikeThread(TaskManager* manager);
	~MikeThread();

	void Init(MikeThread* thread);

	void Update();


	TaskManager* _taskManager = nullptr;
	ITask* currentTask = nullptr;

	std::thread* myThread;
};

