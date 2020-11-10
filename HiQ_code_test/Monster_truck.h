// Monster_truck.h contains the class 'Monster_truck', derived from the base class 'Car'
// The values for area, fwdSpeed, bwdSpeed and turningRatio are fixed
// and set in the constructor.

#pragma once
#include "Car.h"

class Monster_truck :
	public Car
{
public:
	Monster_truck(int xPos, int yPos, char heading);
	
};

