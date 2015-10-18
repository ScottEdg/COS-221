#pragma once
#include <iostream>

class Complex
{
public:
	Complex();													//POST: complex number = (1,1)
	Complex(double r, double i);								//POST: user defined complex number
	~Complex();													//POST: destructor
	
	void setReal(double r);										//POST: set real number
	void setImaginary(double i);								//POST: set imaginary number
	double getReal()const;											//POST: returns real number
	double getImaginary()const;										//POST: returns imaginary number
	double absolute();
	
	Complex operator+(const Complex & c);
	Complex operator-(const Complex & c);
	Complex operator*(const Complex & c);
	Complex operator/(const Complex & c);
	bool operator==(const Complex & c);
	double& operator[](int index);
private:
	double real;
	double imaginary;	
};
	std::istream& operator>>(std::istream &stream, Complex & c); 	//POST: returns both real and imaginary numbers
	std::ostream& operator<<(std::ostream &stream, const Complex & c);
