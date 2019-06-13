#include "pch.h"
#include "MikeThread.h"


MikeThread::MikeThread(TaskManager* manager)
{
	_taskManager = manager;
}


MikeThread::~MikeThread()
{
}
void MikeThread::Init(MikeThread* thread)
{
	std::thread* newThread1 = new std::thread(&MikeThread::Update, this);
	myThread = newThread1;
}
void MikeThread::Update()
{
	while (!TaskManager::shutDown)
	{
		if(currentTask == nullptr)
		{
			currentTask = _taskManager->GrabTask();
		}
		else 
		{
			if (currentTask->currentProgressStatus == ProgressStatus::Ready) 
			{
				if(currentTask->CheckForBlockDependencies())
				{
					currentTask = _taskManager->SwapTask(currentTask);
				}
				else
				{
					currentTask->currentProgressStatus = ProgressStatus::InProgress;
					currentTask->DoWork(currentTask->GetTaskFunction());
					currentTask->SignalDependenciesDone();
					currentTask->currentProgressStatus = ProgressStatus::Done;
				}
			}
			else if(currentTask->currentProgressStatus == ProgressStatus::Done)
			{
				delete currentTask;
				currentTask = nullptr;
			}
		}
	}
}