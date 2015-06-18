/*
	AVR Taskman - Cooperative Multitasking System
	Meant for simple timesharing on systems like AVR microcontrollers
	where an RTOS is overkill.
*/

#include "avrtaskman.h"

Task taskList[NUMTASKS];
unsigned int slot = 0;

// Dispatcher
void dispatch() {
	while (true) {
		if (slot >= NUMTASKS) slot = 0;
		taskList[slot].status = 1;
		taskList[slot].entrypoint();
		taskList[slot].status = 0;
		slot++;
	}
}

// Task Loader
void loadTask(unsigned int slot, void(*function)(void)) {
	Task newtask;
	TaskState state;
	newtask.entrypoint = function;
	newtask.position = NULL;
	newtask.status = 0;
	newtask.state = state;
	taskList[slot] = newtask;
}
