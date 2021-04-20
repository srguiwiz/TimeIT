/*
 * Ipc.h
 *
 *  Created on: 11 Jul 2019
 *      Author: hoglet
 */

#ifndef SRC_MISC_IPCCLIENT_H_
#define SRC_MISC_IPCCLIENT_H_

#include <string>
#include <memory>
#include <libtimeit/timer.h>
#include <libtimeit/event_observer.h>
#include <iostream>
#include "ipc.h"

namespace libtimeit
{

class IpcClient: public Ipc
{
public:
	IpcClient(std::string socketName);
	virtual ~IpcClient();
	void window2front();
private:
	std::string socketName;
};

} /* namespace libtimeit */

#endif /* SRC_MISC_IPCCLIENT_H_ */