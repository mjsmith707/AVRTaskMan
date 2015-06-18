// AVR Task Manager Example Code
// Load 4 basic tasks and go

#include "avrtaskman.h"
#include <iostream>

// Some function prototypes
void task0();
void task1();
void task2();
void task3();

// Load each task into their respective array slots
int main() {
	loadTask(0, task0);
	loadTask(1, task1);
	loadTask(2, task2);
	loadTask(3, task3);

	dispatch();
}

// Task 0 Entry Point
void task0() {
        // State Reload Code
        // Otherwise you could operate
        // on struct members directly
        int a = taskList[slot].state.a;
        int b = taskList[slot].state.b;
        int c = taskList[slot].state.c;

        // Code Resume
        start()
        else {
                // Variable Initialization
                a = 0;
                b = 1;
                c = 0;
        }

        // Actual Code Goes Here
        while (true) {
                a++;
                b++;
                c++;

                // State Save Code
                taskList[slot].state.a = a;
                taskList[slot].state.b = b;
                taskList[slot].state.c = c;

                // Yield to dispatcher
		std::cout << "t0 save0" << std::endl;
                yield(s0)
		std::cout << "t0 resume0" << std::endl;

                a++;
                b++;
                c++;

                // State Save Code
                taskList[slot].state.a = a;
                taskList[slot].state.b = b;
                taskList[slot].state.c = c;

                // Yield to dispatcher
		std::cout << "t0 save1" << std::endl;
                yield(s1)
		std::cout << "t0 resume1" << std::endl;
        }
}

// Task 1 Entry Point
void task1() {
        // State Reload Code
        int a = taskList[slot].state.a;
        int b = taskList[slot].state.b;
        int c = taskList[slot].state.c;

        // Code Resume
	start()
        else {
                // Variable Initialization
                a = 0;
                b = 1;
                c = 0;
        }

        while (true) {
                a++;
                b++;
                c++;

                // State Save Code
                taskList[slot].state.a = a;
                taskList[slot].state.b = b;
                taskList[slot].state.c = c;

                // Yield to dispatcher
		std::cout << "t1 save0" << std::endl;
                yield(s0)
		std::cout << "t1 resume0" << std::endl;

                a++;
                b++;
                c++;

                // State Save Code
                taskList[slot].state.a = a;
                taskList[slot].state.b = b;
                taskList[slot].state.c = c;

                // Yield to dispatcher
		std::cout << "t1 save1" << std::endl;
                yield(s1)
		std::cout << "t1 resume1" << std::endl;
        }
}

// Task 2 Entry Point
void task2() {
        // State Reload Code
        int a = taskList[slot].state.a;
        int b = taskList[slot].state.b;
        int c = taskList[slot].state.c;

        // Code Resume
	start()
        else {
                // Variable Initialization
                a = 0;
                b = 1;
                c = 0;
        }

        while (true) {
                a++;
                b++;
                c++;

                // State Save Code
                taskList[slot].state.a = a;
                taskList[slot].state.b = b;
                taskList[slot].state.c = c;

                // Yield to dispatcher
		std::cout << "t2 save0" << std::endl;
                yield(s0)
		std::cout << "t2 resume0" << std::endl;


                a++;
                b++;
                c++;

                // State Save Code
                taskList[slot].state.a = a;
                taskList[slot].state.b = b;
                taskList[slot].state.c = c;

                // Yield to dispatcher
		std::cout << "t2 save1" << std::endl;
                yield(s1)
		std::cout << "t2 resume1" << std::endl;
        }
}

// Task 4 Entry Point
void task3() {
        // State Reload Code
        int a = taskList[slot].state.a;
        int b = taskList[slot].state.b;
        int c = taskList[slot].state.c;

        // Code Resume
	start()
        else {
                // Variable Initialization
                a = 0;
                b = 1;
                c = 0;
        }

        while (true) {
                a++;
                b++;
                c++;

                // State Save Code
                taskList[slot].state.a = a;
                taskList[slot].state.b = b;
                taskList[slot].state.c = c;

                // Yield to dispatcher
		std::cout << "t3 save0" << std::endl;
                yield(s0)
		std::cout << "t3 resume0" << std::endl;

                a++;
                b++;
                c++;

                // State Save Code
                taskList[slot].state.a = a;
                taskList[slot].state.b = b;
                taskList[slot].state.c = c;

                // Yield to dispatcher
		std::cout << "t3 save1" << std::endl;
                yield(s1)
		std::cout << "t3 resume1" << std::endl;

        }
}
