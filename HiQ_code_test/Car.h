// Car.h contains the base class 'Car' for the remote controlled vehicles

#pragma once
#include <utility>

class Car // Base class
{
public:
	Car(int area, int fwdSpeed, int bwdSpeed, int turningRatio);
	Car();

	void setPos(int xPos, int yPos);
	void setHeading(char heading);
	
	std::pair<int, int> getPos();
	char getHeading() { return heading_; }
	int getArea() { return area_; }
	int getFwdSpeed() { return fwdSpeed_; }
	int getBwdSpeed() { return  bwdSpeed_; }
	int getTurningRatio() { return  turningRatio_; }

protected:
	int area_; //Area of Car in simulation
	int fwdSpeed_; //Number of meters/step forward
	int bwdSpeed_; //Number of meters/step backwards
	int turningRatio_; //Degrees turned with a turning command (Currently not implemented)
	int xPos_, yPos_; //Cars position in room
	char heading_; //Orientation of the car
};

