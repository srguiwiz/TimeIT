#ifndef IPC_SERVER_H_
#define IPC_SERVER_H_

#include <string>
#include <memory>
#include <libtimeit/timer.h>
#include <libtimeit/event_observer.h>
#include <iostream>
#include "libtimeit/misc/ipc.h"

namespace libtimeit
{
using namespace std;
using namespace libtimeit;

class Ipc_server: public Ipc, public Timer_observer
{
public:
	Ipc_server(string socketName, Timer&);
	Ipc_server(const Ipc_server& ) = delete;
	Ipc_server(Ipc_server&& ) = delete;
	Ipc_server& operator=(const Ipc_server& ) = delete;
	Ipc_server& operator=(Ipc_server&& ) = delete;

	~Ipc_server() override;
	void poll();
	void on_signal_1_second() override;
	void attach(Event_observer*);
	void detach(Event_observer*);
	private:
	void on_show_menu();
	string socket_name;
	list<Event_observer*> observers;
	int sock;
};

} /* namespace libtimeit */


#endif /* IPC_SERVER_H_ */
