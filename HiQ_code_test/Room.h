// Room.h contains the class 'Room'.
// This class represents the room in which the simulation takes place,
// with the dimensions of the room indicating the walls of the room in the real world.

#pragma once
class Room
{

private:
	int const width;
	int const height;

public:
	Room(int width, int height);
	Room();
	~Room();

	int  getWidth() const { return width; }
	int  getHeight() const { return height; }


};

