#pragma once
#include <iostream>

class Complex
{
public:
	Complex();								//POST: complex number = (0,0)
	Complex(double r, double i);			//POST: user defined complex number
	~Complex();								//POST: destructor
	
	void setReal(double r);					//POST: set real number
	void setImaginary(double i);			//POST: set imaginary number
	double getReal()const;					//POST: returns real number
	double getImaginary()const;				//POST: returns imaginary number
	double absolute();						//POST: returns absolute value of complex number
	
	Complex operator+(const Complex & c);	//POST: return sum of two Complex numbers
	Complex operator-(const Complex & c);	//POST: return difference of two Complex numbers
	Complex operator*(const Complex & c);	//POST: return product of two Complex numbers
	Complex operator/(const Complex & c);	//POST: return differnce of two Complex numbers
	bool operator==(const Complex & c);		//POST: returns 1 or 0 if two Complex number are equal or not
	double& operator[](int index);			//POST: Value of real(index 0) or imaginary(index 1) is changed
private:
	double real;							//real component of Complex
	double imaginary;						//imaginary component of Complex
};
	std::istream& operator>>(std::istream &stream, Complex & c); 	//POST: changes real and imaginary from istream
	std::ostream& operator<<(std::ostream &stream, const Complex & c);	//POST: outputs real and imaginary to ostream
