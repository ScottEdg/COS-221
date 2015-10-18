#include <cmath>
#include "Complex.h"

Complex::Complex()
//POST: complex number = (0,0)
{
	real = 0;
	imaginary = 0;
}


Complex::Complex(double r, double i)
//POST: user defined complex number
{
	real = r;
	imaginary = i;
}


Complex::~Complex()
//POST: destructor
{
}


void Complex::setReal(double r)
//POST: set real number
{
	real = r;
}


void Complex::setImaginary(double i)
//POST: set imaginary number
{
	imaginary = i;
}


double Complex::getReal() const
//POST: returns real number
{
	return real;
}


double Complex::getImaginary() const
//POST: returns imaginary number
{
	return imaginary;
}


double Complex::absolute()
//POST: returns absolute value of complex number
{
	return sqrt(pow(real, 2) + pow(imaginary, 2));
}


Complex Complex::operator+(const Complex & c)
//POST: return sum of two Complex numbers
{
	double a = this->real;
	double b = this->imaginary;
	double C = c.real;
	double d = c.imaginary;
	
	double r = a + C;
	double i = b + d;
	return Complex(r,i);
}


Complex Complex::operator-(const Complex & c)
//POST: return difference of two Complex numbers
{
	double a = this->real;
	double b = this->imaginary;
	double C = c.real;
	double d = c.imaginary;
	
	double r = a - C;
	double i = b - d;
	return Complex(r,i);
}


Complex Complex::operator*(const Complex & c)
//POST: return product of two Complex numbers
{
	double a = this->real;
	double b = this->imaginary;
	double C = c.real;
	double d = c.imaginary;
	
	double r = (a * C) - (b * d);
	double i = (a * d) + (b * C);
	return Complex(r,i);
}


Complex Complex::operator/(const Complex & c)
//POST: return differnce of two Complex numbers
{
	double a = this->real;
	double b = this->imaginary;
	double C = c.real;
	double d = c.imaginary;
	
	double r = (a * C + b * d) / (pow(C,2) + pow(d,2));
	double i = ((b * C) - (a * d)) / (pow(C,2) + pow(d,2));
	return Complex(r,i);
}


bool Complex::operator==(const Complex & c)
//POST: returns 1 or 0 if two Complex number are equal or not
{
	return (this->real == c.real && this->imaginary == c.imaginary);
}


double& Complex::operator[](int index)
//POST: Value of real(index 0) or imaginary(index 1) is changed
{
	if (index == 0){
		return real;
	}
	else{
		return imaginary;
	}
}


std::istream& operator>>(std::istream &stream, Complex & c)
//POST: changes real and imaginary from istream
{
	double r,i;
	stream>>r>>i;
	c.setReal(r);
	c.setImaginary(i);
	return stream;
}


std::ostream& operator<<(std::ostream &stream, const Complex & c)
//POST: outputs real and imaginary to ostream
{
	stream<<"("<<c.getReal()<<", "<<c.getImaginary()<<")";
	return stream;
}
