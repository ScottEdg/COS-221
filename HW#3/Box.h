//This File: Box.h
#pragma once

class Box
{
public:
	Box();								//POST: a 1x1x1 box is created
	Box(int l, int w, int h);			//POST: a user defined box is created
	~Box();								//POST: Destructor
	
	int getArea() const;				//PRE: length and width must be non negative
										//POST: return area of the box
	int getVolume() const;				//PRE: length, width and heigth must be non negative
										//POST: return volume of the box
	int getL() const;					//POST: return Length of Box
	int getW() const;					//POST: return Width of Box
	int getH() const;					//POST: return Height of Box
	void setDim(int l, int w, int h);	//POST: return dimensions of the box
private:
	int width;
	int length;
	int height;
};
