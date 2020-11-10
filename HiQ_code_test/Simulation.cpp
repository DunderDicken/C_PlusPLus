#include "Simulation.h"

#include <iostream>
#include <sstream>

using namespace std;

Simulation::Simulation(Car car, Room room)
{
	car_ = car;
	room_ = room;
}

void Simulation::initSim()
{
	initRoom();
	initCar();
	initCommands();
}

void Simulation::initRoom()
{
	cout << "Enter the size of the room ( Two integers separated with a space ): \n";
	string input;
	int w, h;
	getline(cin, input);
	istringstream iss(input);

	if (iss >> w >> h)
	{
		room_ = Room(w, h);
	}
	else {
		cout << "ERROR, wrong input \n";
		initRoom();
	}
}

void Simulation::initCar()
{
	cout << "Enter starting position and heading of the car \n" << "( Two integers and one letter separated with spaces, heading is N, S, W or E )\n";
	string input;
	int x, y;
	char heading;
	
	getline(cin, input);
	istringstream iss(input);

	if (iss >> x >> y >> heading)
	{
		car_ = Monster_truck(x, y, heading);
	}
	else {
		cout << "ERROR, wrong input \n";
		initCar();
	}
	
}

void Simulation::initCommands()
{
	cout << "Enter the commands to execute. ( All commands in series, without spaces )\n" << " Available commands are F, B, L or R.\n";
	char input;
	do {
		input = getchar();
		if (isValidCommand(input))
		{
			commands_.push(input); //Add command to queue
		}
		else if (input != '\n')
		{
			cout << "ERROR, -" << input << "- is not a valid command \n";
			/*Clear queue*/
			queue<char> empty;
			std::swap(commands_, empty);
			break;
		}
	} while (input != '\n' && input != ' ') ;

	if (commands_.empty()) //If empty, run again
	{
		initCommands();
	}
}

void Simulation::startSim()
{
	int steps = commands_.size();

	for (int i = 0; i < steps; i++)
	{
		char command = commands_.front();
		commands_.pop();
		cout << "Running command: "<< command << ". Step " << i+1 << "/" << steps << " \n";

		drive(command);
		if(didWeCrash())
		{
			cout << " CRASH! The car hit the wall At step " << i+1 << ". Position X : " << car_.getPos().first << ", Y : " <<car_.getPos().second << ", heading : " << car_.getHeading() << "\n";
			getchar();
			return;
		}
	}
	cout << "Simulation successful, car currently at position X:" << car_.getPos().first << ", Y:" <<car_.getPos().second << ", heading:" << car_.getHeading() << "\n";
	
}

/* Drives the car according to command 'c' */
void Simulation::drive(char c) 
{
	switch (c)
	{
	case 'F': driveFwd();  break;
	case 'B': driveBwd();  break;
	case 'L': turnLeft();  break;
	case 'R': turnRight(); break;
	default:			   break;
	}
}

void Simulation::driveFwd()
{
	int currentX = car_.getPos().first;
	int currentY = car_.getPos().second;
	
	switch (car_.getHeading())
	{
	case 'N': currentY += car_.getFwdSpeed(); break;
	case 'S': currentY -= car_.getFwdSpeed(); break;
	case 'W': currentX -= car_.getFwdSpeed(); break;
	case 'E': currentX += car_.getFwdSpeed(); break;
	default:			   break;
	}

	car_.setPos(currentX, currentY);
}

void Simulation::driveBwd()
{
	int currentX = car_.getPos().first;
	int currentY = car_.getPos().second;

	switch (car_.getHeading())
	{
	case 'N': currentY -= car_.getBwdSpeed(); break;
	case 'S': currentY += car_.getBwdSpeed(); break;
	case 'W': currentX += car_.getBwdSpeed(); break;
	case 'E': currentX -= car_.getBwdSpeed(); break;
	default:			   break;
	}

	car_.setPos(currentX, currentY);
}

void Simulation::turnLeft()
{
	switch (car_.getHeading())
	{
	case 'N': car_.setHeading('W'); break;
	case 'S': car_.setHeading('E'); break;
	case 'W': car_.setHeading('S'); break;
	case 'E': car_.setHeading('N'); break;
	default:			   break;
	}
}

void Simulation::turnRight()
{
	switch (car_.getHeading())
	{
	case 'N': car_.setHeading('E'); break;
	case 'S': car_.setHeading('W'); break;
	case 'W': car_.setHeading('N'); break;
	case 'E': car_.setHeading('S'); break;
	default:			   break;
	}
	
}

/* Checks if command 'c' is a valid command, returns true if it is valid */
bool Simulation::isValidCommand(char c)
{
	if (c != 'F' && c != 'B' && c != 'L' && c != 'R')
		return false;
	else
		return true;
}

/* Checks if the car is out of bounds of the room */
bool Simulation::didWeCrash()
{
	bool crash = false;
	int currentX = car_.getPos().first;
	int currentY = car_.getPos().second;
	
	if (currentX < 0 || currentX >= room_.getWidth())
	{
		crash = true;
	}
	if (currentY < 0 || currentY >= room_.getHeight())
	{
		crash = true;
	}
	
	return crash;
}



