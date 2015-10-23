//This File: Box.cpp
#include "Box.h"

Box::Box()
//POST: a 1x1x1 box is created
{
	width = 1;
	length = 1;
	height = 1;
}

Box::Box(int l, int w, int h)
//POST: a user defined box is created
{
	length = l;
	width = w;
	height = h;
}

Box::~Box()
//POST: Destructor
{
}

int Box::getArea() const
//PRE: length and width must be non negative
//POST: return area of the box
{
	return (width * length);
}

int Box::getVolume() const
//PRE: length, width and heigth must be non negative
//POST: return volume of the box
{
	return (width * length * height);
}

int Box::getL() const
//POST: return Length of Box
{
	return length;
}

int Box::getW() const
//POST: return Width of Box
{
	return width;
}

int Box::getH() const
//POST: return Height of Box
{
	return height;
}

void Box::setDim(int l, int w, int h)
//POST: return dimensions of the box
{
	length = l;
	width = w;
	height = h;
}
