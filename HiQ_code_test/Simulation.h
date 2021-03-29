// Simulation.h contains the Class Simulation.
// This class represent the simulation. This class initializes the
// simulation via user prompts, steps through the simulation and reports the results.
#pragma once

#include <queue>

#include "Room.h"
#include  "Car.h"
#include "MonsterTruck.h"
#include <memory>


class Simulation
{
public:
	Simulation(Car car, Room room);
	Simulation();
	~Simulation();

	void initSim();
	void startSim();
	
	void setCar(Car const& c);
	void setRoom(Room const & r);
	Car getCar();
	Room getRoom();

	
private:
	std::unique_ptr<Car> car;
	std::unique_ptr<Room> room;
	std::queue<char> commands;


	void initRoom();
	void initCar();
	void initCommands();
	

	void drive(char c);
	void driveFwd();
	void driveBwd();
	void turnLeft();
	void turnRight();

	//Helpers
	bool isValidCommand(char c);
	bool didWeCrash();
};


