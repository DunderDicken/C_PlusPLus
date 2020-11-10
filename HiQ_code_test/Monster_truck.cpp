#include "Monster_truck.h"

Monster_truck::Monster_truck(int xPos, int yPos, char heading)
	: Car( 1,  1,  1,  90)
{
	setPos(xPos, yPos);
	setHeading(heading);
}
