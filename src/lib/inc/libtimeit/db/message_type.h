//
// Created by hoglet on 22/03/2021.
//

#ifndef TIMEIT_MESSAGE_TYPE_H
#define TIMEIT_MESSAGE_TYPE_H

namespace libtimeit
{

enum message_type
{
	TASK_UPDATED,
	TASK_REMOVED,
	TASK_ADDED,
	TASK_PARENT_CHANGED,
	COMPLETE_UPDATE,
	TASK_NAME_CHANGED,
	TASK_TIME_CHANGED,
	SETTINGS_CHANGED,
	TIME_ENTRY_CHANGED
};

}
#endif //TIMEIT_MESSAGE_TYPE_H
