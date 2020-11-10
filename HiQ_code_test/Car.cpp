#include "Car.h"


Car::Car(){}


Car::Car(int area, int fwdSpeed, int bwdSpeed, int turningRatio)
{
	area_ = area;
	fwdSpeed_ = fwdSpeed; 
	bwdSpeed_= bwdSpeed; 
	turningRatio_ = turningRatio; 
	xPos_ = 0;
	yPos_ = 0;
}

void Car::setPos(int xPos, int yPos)
{
	xPos_ = xPos;
	yPos_ = yPos;
}

void Car::setHeading(char heading)
{
	heading_ = heading;
}

std::pair<int, int> Car::getPos()
{
	return { xPos_, yPos_ };
}




