#pragma once
#include <vector>
#include <atomic>

enum PriorityStatus {
	High = 0,
	Medium,
	Low
};
enum ProgressStatus {
	Ready = 0,
	InProgress,
	Done
};

class ITask {
public:
	ITask() {};
	~ITask() {};

	virtual bool CheckForBlockDependencies() = 0;
	virtual void DoWork(void*) = 0;
	virtual void SignalDependenciesDone() = 0;
	virtual void* GetTaskFunction() = 0;

	virtual int GetDependencyCount() { return dependenciesCount; }

	ProgressStatus currentProgressStatus;
	PriorityStatus priorityStatus;
	std::vector<ITask> depeneciesWaitingOnMe;
	std::atomic<int> dependenciesCount = 0;
	int taskNumber = 0;
};