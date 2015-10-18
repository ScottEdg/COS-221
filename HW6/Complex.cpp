#include <cmath>
#include "Complex.h"

Complex::Complex()
{
	real = 0;
	imaginary = 0;
}


Complex::Complex(double r, double i)
{
	real = r;
	imaginary = i;
}


Complex::~Complex()
{
}


void Complex::setReal(double r)
{
	real = r;
}


void Complex::setImaginary(double i)
{
	imaginary = i;
}


double Complex::getReal() const
{
	return real;
}


double Complex::getImaginary() const
{
	return imaginary;
}


double Complex::absolute()
{
	return sqrt(pow(real, 2) + pow(imaginary, 2));
}


Complex Complex::operator+(const Complex & c)
{
	double r = this->real + c.real;
	double i = this->imaginary + c.imaginary;
	return Complex(r,i);
}


Complex Complex::operator-(const Complex & c)
{
	double r = this->real - c.real;
	double i = this->imaginary - c.imaginary;
	return Complex(r,i);
}


Complex Complex::operator*(const Complex & c)
{
	double r = (this->real * c.real) - (this->imaginary * c.imaginary);
	double i = (this->real * c.imaginary) + (this->imaginary * c.real);
	return Complex(r,i);
}


Complex Complex::operator/(const Complex & c)
{
	double a = real;
	double b = imaginary;
	double C = c.real;
	double d = c.imaginary;
	double r = (a * C + b * d) / (pow(C,2) + pow(d,2));
//	double r=(real*c.real+imaginary*c.imaginary)/(pow(c.real,2)+pow(c.imaginary,2));
	double i=(imaginary*c.real-real*c.imaginary)/(pow(c.real,2)+pow(c.imaginary,2));
//	int i = ((b * C) - (a * d)) / (pow(C,2) + pow(d,2));
	return Complex(r,i);
}


bool Complex::operator==(const Complex & c)
{
	return (this->real == c.real && this->imaginary == c.imaginary);
}


double& Complex::operator[](int index)
{
	if (index == 0){
		return real;
	}
	else{
		return imaginary;
	}
}


std::istream& operator>>(std::istream &stream, Complex & c)
//POST: returns both real and imaginary numbers
{
	double r,i;
	stream>>r>>i;
	c.setReal(r);
	c.setImaginary(i);
	return stream;
}


std::ostream& operator<<(std::ostream &stream, const Complex & c)
{
	stream<<"("<<c.getReal()<<","<<c.getImaginary()<<")";
	return stream;
}
