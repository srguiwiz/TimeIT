#ifndef AUTOTRACKER_H_
#define AUTOTRACKER_H_
#include <iostream>
#include <libtimeit/Timer.h>
#include <libtimeit/logic/TimeKeeper.h>
#include <libtimeit/db/database.h>
#include <libtimeit/db/autotrack_accessor.h>
#include <libtimeit/logic/Workspace.h>

namespace libtimeit
{
using namespace std;

class AutoTracker : public libtimeit::TimerObserver
{
public:
	AutoTracker(ITimeKeeper &timeKeeper,  Database &database, Timer &timer);
	virtual ~AutoTracker();
private:
	void check4Changes();
	void doTaskSwitching(int oldWorkspace, int newWorkspace);
	//TimerObserver
	virtual void on_signal_1_second();

	int oldWorkspace;
	ITimeKeeper        &time_keeper;
	Timer              &timer;
	Autotrack_accessor  autotrack_accessor;
	Task_accessor       task_accessor;
	Workspace          workspace;
};

}
#endif /*AUTOTRACKER_H_*/
