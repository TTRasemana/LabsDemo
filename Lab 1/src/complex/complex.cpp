// complex.cpp
// Multiplying complex numbers

#include <iostream>	// contains the definition of cout, endl
#include <complex>	// contains the complex class definition

using namespace std; // cout, endl, complex are all part of this namespace

using ComplexFloat = complex<float>;// Create an alias for complex<float>

int main()
{
    ComplexFloat num1{2.0, 2.0};
    ComplexFloat num2{4.0, -2.0};

    ComplexFloat answer = num1 * num2;

	cout << "The answer is: " << answer << endl;
	cout << "Or in a more familiar form: " << answer.real()
			<< " + " << answer.imag() << "j"
			<< endl	<< endl;
			
// Uncommenting the following line will result in a compilation error:
//Complex numbers do not directly support the increment operator (++). 
//Unlike integers or floating-point numbers, complex numbers cannot be incremented in the same way.

   //answer++;

	return 0;
}

