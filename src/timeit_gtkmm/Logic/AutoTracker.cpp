#include <AutoTracker.h>
#include <Timer.h>
#include <iostream>
#include <vector>
#include <TimeKeeper.h>
#include <Timer.h>

AutoTracker::AutoTracker(std::shared_ptr<ITimeKeeper> &timekeeper, const std::shared_ptr<DB::IDatabase> &database,
		const std::shared_ptr<Timer> &timer)
{
	m_timekeeper = timekeeper;
	m_timer = timer;
	m_autotrackAccessor = database->getAutotrackAccessor();
	m_taskAccessor = database->getTaskAccessor();
	oldWorkspace = -1;
	on_signal_1_second(); //check if we should start anything;
	m_timer->attach(this);
}

AutoTracker::~AutoTracker()
{
	m_timer->detach(this);
}

void AutoTracker::on_signal_1_second()
{
	check4Changes();
}

void AutoTracker::check4Changes()
{
	//Check for changes
	int newWorkspace;
	newWorkspace = m_workspace.get_active();
	if (newWorkspace >= 0 && oldWorkspace != newWorkspace)
	{
		doTaskSwitching(oldWorkspace, newWorkspace);
		oldWorkspace = newWorkspace;
	}
}

bool contains(std::vector<int64_t> vec, int64_t item)
{
	if (std::find(vec.begin(), vec.end(), item) != vec.end())
	{
		return true;
	}
	else
	{
		return false;
	}

}

void AutoTracker::doTaskSwitching(int oldWorkspace, int newWorkspace)
{
	std::vector<int64_t> tasksToStop = m_autotrackAccessor->getTaskIDs(oldWorkspace);
	std::vector<int64_t> tasksToStart = m_autotrackAccessor->getTaskIDs(newWorkspace);
	for (int64_t taskID : tasksToStop)
	{
		if (false == contains(tasksToStart, taskID))
		{
			m_timekeeper->StopTask(taskID);
		}
	}
	for (int64_t taskID : tasksToStart)
	{
		try
		{
			m_timekeeper->StartTask(taskID);
		}
		catch (...)
		{

		}
	}

}

//http://library.gnome.org/devel/libwnck/stable/WnckScreen.html#wnck-screen-calc-workspace-layout