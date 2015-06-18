#ifndef __AVR_TASKMAN_H_
#define __AVR_TASKMAN_H_

/*
        AVR Taskman - Cooperative Multitasking System v0.001
        Meant for simple timesharing on systems like AVR microcontrollers
        where an RTOS is overkill.

        Each task must manage its own volatile (i.e. stack) variables.
        Additionally each task can run to completion or yield at certain
        specified locations back to the dispatcher.

        All tasks must have start() immediately following their state
        resume code (optional) at the top of the entry point.
        An else block can also optionally initialize fields.

        yield()'s argument must be a scope local unique label name.

        LIMITATIONS:
        As this a cooperative round-robin style system you have zero
        guarantee that a faulting section of code will not nuke the
        entire system.
        You also have no guarantees on the timing of each code section
        unless you manually inspect the generated machine code.
	Finally, yield probably cannot be called in a subroutine as the
	dispatch does not perform any real stack unwinding. You will just
	mangle the stack on return most likely.
*/


#ifndef NULL
#define NULL 0
#endif

#define NUMTASKS 4      // The number of tasks available

// Dispatch Macros
#define start()         if (taskList[slot].position != NULL) goto *taskList[slot].position;
#define yield(label)    taskList[slot].position = &&label; return; label: taskList[slot].position = NULL;

// Generic Task State Structure
// Replace with task specific stack variables
typedef struct {
        int a;
        int b;
        int c;
} TaskState;

// Task Structure
typedef struct {
        void (*entrypoint)(void);       // Startup entry point
        unsigned char status;           // 0 = Stopped, 1 = Running
        void* position;                 // Program Position
        TaskState state;                // Structure holding saved state
} Task;

// Task Array
extern Task taskList[NUMTASKS];

// Current Task
extern unsigned int slot;

extern void dispatch();
extern void loadTask(unsigned int slot, void(*function)(void));

#endif
