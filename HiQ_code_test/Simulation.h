// Simulation.h contains the Class Simulation.
// This class represent the simulation. This class initializes the
// simulation via user prompts, steps through the simulation and reports the results.
#pragma once

#include <queue>

#include "Room.h"
#include  "Car.h"
#include "Monster_truck.h"

class Simulation
{
public:
	Simulation(Car car, Room room);
	Simulation() = default;

	void initSim();
	void initRoom();
	void initCar();
	void initCommands();
	void startSim();
	
	void drive(char c); 
	void driveFwd();
	void driveBwd();
	void turnLeft();
	void turnRight();
	
	bool isValidCommand(char c);
	bool didWeCrash();
	
protected:
	Car car_;
	Room room_;
	std::queue<char> commands_;
};


