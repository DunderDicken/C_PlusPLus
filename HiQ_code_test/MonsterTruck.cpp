#include "MonsterTruck.h"
#include <iostream>

enum M_TRUCK {mTruckA = 2, mTruckFwd = 3, mTruckBwd = 1};

MonsterTruck::MonsterTruck(int xPos, int yPos, char heading):
	Car(mTruckA, mTruckFwd, mTruckBwd, xPos, yPos, heading)
{
	
	std::cout << "Constructing Monster Truck with variables" << std::endl;
}

MonsterTruck::MonsterTruck(): Car()
{
	std::cout << "Constructing Monster Truck" << std::endl;
}

MonsterTruck::~MonsterTruck()
{
	std::cout << "Destructing Monster Truck" << std::endl;
}
