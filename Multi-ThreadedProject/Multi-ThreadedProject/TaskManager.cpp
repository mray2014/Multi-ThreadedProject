#include "pch.h"
#include "TaskManager.h"

bool TaskManager::shutDown = false;

TaskManager::TaskManager()
{
	
	highPriorityTasks = std::queue<ITask*>();
	medPriorityTasks = std::queue<ITask*>();
	lowPriorityTasks = std::queue<ITask*>();
}


TaskManager::~TaskManager()
{
}

void TaskManager::AddTask(ITask * newTask)
{
	switch (newTask->priorityStatus)
	{
	case PriorityStatus::High:
	{
		highPriorityTasks.push(newTask);
		break;
	}
	case PriorityStatus::Medium:
	{
		medPriorityTasks.push(newTask);
		break;
	}
	case PriorityStatus::Low:
	{
		lowPriorityTasks.push(newTask);
		break;
	}
	}
	newTask->taskNumber = tasksCount;
	tasksCount++;
}

ITask * TaskManager::GrabTask()
{
	ITask* task = nullptr;

	if (highPriorityTasks.size() > 0)
	{
		task = highPriorityTasks.front();
		highPriorityTasks.pop();
	}
	else if (medPriorityTasks.size() > 0)
	{
		task = medPriorityTasks.front();
		medPriorityTasks.pop();
	}
	else if (lowPriorityTasks.size() > 0)
	{
		task = lowPriorityTasks.front();
		lowPriorityTasks.pop();
	}


	if (task != nullptr)
	{
		task->currentProgressStatus = ProgressStatus::Ready;
	}
	else
	{
		printf("No availiable tasks!\n");
	}

	return task;
}

ITask * TaskManager::SwapTask(ITask * newTask)
{
	AddTask(newTask);
	return GrabTask();
}

int TaskManager::GetNumOfAvailableTasks()
{
	return highPriorityTasks.size() + medPriorityTasks.size() + lowPriorityTasks.size();
}

void TaskManager::ShutDown()
{
	while (highPriorityTasks.size() > 0)
	{
		delete highPriorityTasks.front();
		highPriorityTasks.pop();
	}
	highPriorityTasks.empty();

	while (medPriorityTasks.size() > 0)
	{
		delete medPriorityTasks.front();
		medPriorityTasks.pop();
	}
	medPriorityTasks.empty();

	while (lowPriorityTasks.size() > 0)
	{
		delete lowPriorityTasks.front();
		lowPriorityTasks.pop();
	}
	lowPriorityTasks.empty();
}
