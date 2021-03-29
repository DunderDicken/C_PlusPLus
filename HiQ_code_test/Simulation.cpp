#include "Simulation.h"

#include <iostream>
#include <sstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::istringstream;
using std::getline;

Simulation::Simulation(Car car, Room room)
{
	Simulation::car = std::make_unique<Car>(car);
	Simulation::room = std::make_unique<Room>(room);

	cout << "Constructing Simulation" << endl;

}

Simulation::Simulation() 
{
	cout << "Constructing Simulation without args" << endl;
}

Simulation::~Simulation()
{
	cout << "Deconstructing Simulation" << endl;
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
		setRoom(Room(w, h));
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
		setCar(MonsterTruck(x, y, heading));
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
			commands.push(input); //Add command to queue
		}
		else if (input != '\n')
		{
			cout << "ERROR, -" << input << "- is not a valid command \n";
			/*Clear queue*/
			std::queue<char> empty;
			std::swap(commands, empty);
			break;
		}
	} while (input != '\n' && input != ' ') ;

	if (commands.empty()) //If empty, run again
	{
		initCommands();
	}
}

void Simulation::startSim()
{
	int steps = commands.size();

	for (int i = 0; i < steps; i++)
	{
		char command = commands.front();
		commands.pop();
		cout << "Running command: "<< command << ". Step " << i+1 << "/" << steps << " \n";

		drive(command);
		if(didWeCrash())
		{
			cout << " CRASH! The car hit the wall At step " << i+1 << ". Position X : " << car->getPos().first << ", Y : " << car->getPos().second << ", heading : " << car->getHeading() << "\n";
			getchar();
			return;
		}
	}
	cout << "Simulation successful, car currently at position X:" << car->getPos().first << ", Y:" << car->getPos().second << ", heading:" << car->getHeading() << "\n";
	
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
	int currentX = car->getPos().first;
	int currentY = car->getPos().second;
	
	switch (car->getHeading())
	{
	case 'N': currentY += car->getFwdSpeed(); break;
	case 'S': currentY -= car->getFwdSpeed(); break;
	case 'W': currentX -= car->getFwdSpeed(); break;
	case 'E': currentX += car->getFwdSpeed(); break;
	default:			   break;
	}

	car->setPos(currentX, currentY);
}

void Simulation::driveBwd()
{
	int currentX = car->getPos().first;
	int currentY = car->getPos().second;

	switch (car->getHeading())
	{
	case 'N': currentY -= car->getBwdSpeed(); break;
	case 'S': currentY += car->getBwdSpeed(); break;
	case 'W': currentX += car->getBwdSpeed(); break;
	case 'E': currentX -= car->getBwdSpeed(); break;
	default:			   break;
	}

	car->setPos(currentX, currentY);
}

void Simulation::turnLeft()
{
	switch (car->getHeading())
	{
	case 'N': car->setHeading('W'); break;
	case 'S': car->setHeading('E'); break;
	case 'W': car->setHeading('S'); break;
	case 'E': car->setHeading('N'); break;
	default:			   break;
	}
}

void Simulation::turnRight()
{
	switch (car->getHeading())
	{
	case 'N': car->setHeading('E'); break;
	case 'S': car->setHeading('W'); break;
	case 'W': car->setHeading('N'); break;
	case 'E': car->setHeading('S'); break;
	default:			   break;
	}
	
}

void Simulation::setCar(Car const& c)
{
	Simulation::car = std::make_unique<Car>(c);
}

void Simulation::setRoom(Room const& r)
{
	Simulation::room = std::make_unique<Room>(r);
}

Car Simulation::getCar()
{
	return *car;
}

Room Simulation::getRoom()
{
	return *room;
}

/* Checks if command 'c' is a valid command, returns true if it is valid */
bool Simulation::isValidCommand(char c)
{
	if (c != 'F' && c != 'B' && c != 'L' && c != 'R') //Add lower case
		return false;
	else
		return true;
}

/* Checks if the car is out of bounds of the room */
bool Simulation::didWeCrash()
{
	bool crash = false;
	int currentX = car->getPos().first;
	int currentY = car->getPos().second;
	
	if (currentX < 0 || currentX >= room->getWidth())
	{
		crash = true;
	}
	if (currentY < 0 || currentY >= room->getHeight())
	{
		crash = true;
	}
	
	return crash;
}



