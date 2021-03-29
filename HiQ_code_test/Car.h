// Car.h contains the base class 'Car' for the remote controlled vehicles

#pragma once
#include <utility>

class Car // Base class
{

private:
	int const area; //Area of Car in simulation
	int const fwdSpeed; //Number of meters/step forward
	int const bwdSpeed; //Number of meters/step backwards
	int xPos, yPos; //Cars position in room
	char heading; //Orientation of the car

public:
	Car(int area, int fwdSpeed, int bwdSpeed, int x, int y, char h);
	Car();
	virtual ~Car();

	virtual void setPos(int xPos, int yPos);
	virtual void setHeading(char heading) { Car::heading = heading; }


	std::pair<int, int> getPos();
	char getHeading() const { return heading; }
	int getArea() const { return area; }
	int getFwdSpeed() const { return fwdSpeed; }
	int getBwdSpeed() const { return  bwdSpeed; }


};

