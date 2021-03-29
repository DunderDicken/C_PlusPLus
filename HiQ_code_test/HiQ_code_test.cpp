// ============ HiQ_code_test.cpp ============
// A simple simulator for remote controlled cars.
// 
// This file contains the main function
// which Creates, initializes and start the simulation.  
//
// Version 0.1


#include <iostream>
#include  "Simulation.h"

int main()
{

	Simulation S1;
	S1.initSim();
	S1.startSim();

	
	getchar();
	return 0;

}

