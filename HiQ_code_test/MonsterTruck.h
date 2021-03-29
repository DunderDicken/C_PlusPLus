// MonsterTruck.h contains the class 'MonsterTruck', derived from the base class 'Car'
// The values for area, fwdSpeed, bwdSpeed and turningRatio are fixed
// and set in the constructor.

#pragma once
#include "Car.h"

class MonsterTruck :
	public Car
{
public:
	MonsterTruck(int xPos, int yPos, char heading);
	MonsterTruck();
	~MonsterTruck();

private:

};

