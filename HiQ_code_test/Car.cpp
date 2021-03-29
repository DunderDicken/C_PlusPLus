#include "Car.h"
#include <iostream>
using std::cout;

Car::Car(int a, int fwdS, int bwdS, int x, int y, char h):
	area(area),fwdSpeed(fwdSpeed), bwdSpeed(bwdSpeed), 
	xPos(x), yPos(y), heading(h)
{
	cout << "Constructing Car with variables" << std::endl;
}

Car::Car(): area(0), fwdSpeed(0), bwdSpeed(0),xPos(0),yPos(0),heading(' ')
{
	cout << "Constructing Car" << std::endl;
}

Car::~Car()
{
	cout << "Destructing Car" << std::endl;
}

void Car::setPos(int xPos, int yPos)
{
	Car::xPos = xPos >= 0 ? xPos : 0;
	Car::yPos = yPos >= 0 ? yPos : 0;
}


std::pair<int, int> Car::getPos()
{
	return { Car::xPos, Car::yPos };
}




