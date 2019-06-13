#pragma once
#include "ITask.h"
#include <queue>

class TaskManager
{
public:
	static bool shutDown;

	TaskManager();
	~TaskManager();

	void AddTask(ITask* newTask);
	ITask* GrabTask();
	ITask* SwapTask(ITask* newTask);

	int GetNumOfAvailableTasks();

	void ShutDown();

	std::queue<ITask*> highPriorityTasks;
	std::queue<ITask*> medPriorityTasks;
	std::queue<ITask*> lowPriorityTasks;

	unsigned int tasksCount = 1;

};

