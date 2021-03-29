#include "Room.h"

#include <iostream>
using std::cout;

Room::Room(int w, int h): width(w), height(h)
{
	cout << "Constructing Room with variables" << std::endl;
}

Room::Room(): width(0), height(0)
{
	cout << "Constructing 'empty' Room" << std::endl;
}

Room::~Room()
{
	cout << "Destructing Room" << std::endl;
}

