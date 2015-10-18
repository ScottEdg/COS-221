#include <iostream>
#include <cmath>
#include "Complex.h"
using namespace std;

int main()
{
	Complex c1, c2;				// 2 Complex values
	Complex cr1, cr2;

	double a,b,c;				// real and imaginary components
	double r1,r2;

	// the test program is given to student

	// get data for first Complex from keyboard
	cout  << "Enter first Complex parts: a and b: "; 
	cin >> c1;
		
	// get data for first Complex from keyboard
	cout  << "Enter second Complex parts: a and b: "; 
	cin >> c2;
	
	// output section
	cout << "\nComplex test program by Scott Edgerly:\n\n";
	cout << "\nThe first complex is: " << c1 << endl;
	cout << "The second complex is: " << c2 << endl;
	
	cout << "\nAbsolute value of " << c1 << " is " << c1.absolute() << endl;
	cout << "Absolute value of " << c2 << " is " << c2.absolute() << endl;
	
	cout << "\nThe sum of " << c1 << " and " << c2 << " is " << (c1 + c2) << endl;
	cout << "\nThe difference of " << c1 << " and " << c2 << " is " << (c1 - c2) << endl;
	cout << "\nThe product of " << c1 << " and " << c2 << " is " << (c1 * c2) << endl;
	cout << "\nThe quotient of " << c1 << " and " << c2 << " is " << (c1 / c2) << endl << endl;
	
	if (c1 == c2) cout << c1 << "equals " << c2 << endl;
	else cout << c1 << "does not equal " << c2 << endl;   

	cout << "Enter a new real component to the first complex: ";
	cin >> c1[0];
	cout << "Enter a new imaginary component to the first complex: ";
	cin >> c1[1];
	cout << "The new real component to the first complex is: " << c1[0] << endl;
	cout << "The new imaginary component to the first complex is: " << c1[1] << endl;

	// student writes the code below

	
	
	cout << endl;
	return 0;
}

