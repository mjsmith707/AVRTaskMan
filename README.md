AVR Taskman - Cooperative Multitasking System v0.001

Meant for simple timesharing on systems like AVR microcontrollers
where an RTOS is overkill.

MODE OF OPERATION:
loadTask() loads a function pointer into a static array (default 4 tasks).
dispatch() will in round-robin style start and restart execution in each task.
This functionality is achieved in a platform independent way (initially written on x86, tested on atmega328p
through the use of two macros. yield() places a label at the current position in the code, saves it into the task
structure, and returns to the dispatcher. When the dispatcher re-executes the function, start() will issue a jump to the
saved label to resume execution from that point.

Each task can run to completion or yield at certain specified locations back to the dispatcher.
All tasks must have start() immediately following their state resume code (optional) at the top of the entry point,
otherwise they will simply run to completion or endlessly to a yield() point.
An else block can also optionally initialize fields.
yield()'s argument must be a scope local unique label name.

LIMITATIONS:
- Each task must manage its own volatile (i.e. stack) variables.
- As this a cooperative round-robin style system you have zero guarantee 
  that a faulting section of code will not nuke the entire system.
- You also have no guarantees on the timing of each code section unless you 
  manually inspect the generated machine code or otherwise measure time.
- Finally, yield probably cannot be called in a subroutine as the dispatch does 
  not perform any real stack unwinding. You will just mangle the stack on return most likely.
  
TODO:
- Task priorities
- Task status (waiting, terminated, etc.)
- Eventually add a yield_until()
- See about supporting yield in nested functions (unlikely)

TESTED ON:
- working on atmega328p using Atmel Studio 6 and avrdude
- Doesn't appear to work with Arduino IDE (macro expansion errors)
