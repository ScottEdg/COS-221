/*
	Scott Edgerly
	COS 221 Assignment #6
	This code tests the Complex class written by the student
	and calculates a complex number given coefficient values
	given from user input.
*/

#include <iostream>
#include <cmath>
#include "Complex.h"
using namespace std;

int main()
{
	Complex c1, c2;				// 2 Complex values
	Complex cr1, cr2;

	double a,b,c,D;				// real and imaginary components
	double r1,r2;
	int n; // number of equations in part 2
	int i; // iterator for part 2
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
	
	if (c1 == c2) cout << c1 << " equals " << c2 << endl;
	else cout << c1 << " does not equal " << c2 << endl;   

	cout << "Enter a new real component to the first complex: ";
	cin >> c1[0];
	cout << "Enter a new imaginary component to the first complex: ";
	cin >> c1[1];
	cout << "The new real component to the first complex is: " << c1[0] << endl;
	cout << "The new imaginary component to the first complex is: " << c1[1] << endl;

	// student writes the code below

	cout<<endl<<"How many equations will be entered? ";
	cin>>n;
	
	for(i=0;i<n;i++){
		cout<<endl<<"Enter Coefficient Values of the quadratic a, b, c: ";
		cin>>a>>b>>c;
		D = pow(b,2) - 4*a*c;
		if(D >= 0){ //the complex number is real
			cr1.setReal((-1*b / 2*a) + (sqrt(D) / 2*a));
			cr2.setReal((-1*b / 2*a) - (sqrt(D) / 2*a));
		}
		else{  //the complex number has an imaginary component
			cr1.setReal((-1*b / 2*a));
			cr1.setImaginary(sqrt(-1*D) / 2*a);
			cr2.setReal((-1*b / 2*a));
			cr2.setImaginary(-1*(sqrt(-1*D) / 2*a));
		}
		cout<<cr1<<" "<<cr2<<endl; //print out the complex number
		
		cr1.setReal(0);  //reset the values for next iteration
		cr1.setImaginary(0);
		cr2.setReal(0);
		cr2.setImaginary(0);
	}
	
	cout << endl;
	return 0;
}

