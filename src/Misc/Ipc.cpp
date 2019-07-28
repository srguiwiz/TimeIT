/*
 * Ipc.cpp
 *
 *  Created on: 17 Jul 2019
 *      Author: hoglet
 */

#include "Ipc.h"
#include <sys/un.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <fcntl.h>
#include <sys/stat.h>
namespace Utils
{

using namespace std;

Ipc::Ipc()
{
	// Nothing to do
}

Ipc::~Ipc()
{
	// Nothing to do
}

std::string Ipc::prepareSocketDir()
{
	string runtimeDir;
	char *s = getenv("XDG_RUNTIME_DIR");
	if (s != NULL)
	{
		runtimeDir = s;
	}
	else
	{
		std::cerr << "XDG_RUNTIME_DIR is not defined, fallback to /tmp\n";
		runtimeDir = "/tmp";
	}
	runtimeDir = runtimeDir + "/timeit/";

	mkdir(runtimeDir.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

	return runtimeDir;
}

} /* namespace Utils */