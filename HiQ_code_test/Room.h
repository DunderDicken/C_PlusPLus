// Room.h contains the class 'Room'.
// This class represents the room in which the simulation takes place,
// with the dimensions of the room indicating the walls of the room in the real world.

#pragma once
class Room
{
public:
	Room(int w, int h)
	{
		width = w;
		height = h;
	};
	
	Room() = default;
	
	int getWidth() { return width; }
	int getHeight() { return height; }
	
private:
	int width, height;
};

