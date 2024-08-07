// quadratic.cpp
// Calculate roots of a quadratic equation using complex numbers

#include <iostream>
#include <complex> // Include the complex header

using namespace std;
using ComplexFloat = complex<float>; // Create an alias for complex<float>

int main()
{
    float a, b, c;
    char choice = ' '; // To store user's choice for repeating calculations
    while (choice != 'q')
    {
        cout << "Enter coefficients a, b, and c: ";
        cin >> a >> b >> c;

        // Calculate discriminant
        float discriminant = b * b - 4 * a * c;

        if (discriminant > 0)
        {
            // Real and different roots
            float x1 = (-b + sqrt(discriminant)) / (2 * a);
            float x2 = (-b - sqrt(discriminant)) / (2 * a);
            cout << "Roots are real and different." << endl;
            cout << "x1 = " << x1 << endl;
            cout << "x2 = " << x2 << endl;
        }
        else if (discriminant == 0)
        {
            // Real and equal roots
            float x1 = -b / (2 * a);
            cout << "Roots are real and same." << endl;
            cout << "x1 = x2 = " << x1 << endl;
        }
        else
        {
          // Complex roots
            ComplexFloat root1(-b / (2 * a), sqrt(-discriminant) / (2 * a));
            cout << "Roots are complex and different." << endl;
            cout << "x1 = " << root1.real() << " + " << root1.imag() << "j" << endl;
            cout << "x2 = " << root1.real() << " - " << root1.imag() << "j" << endl;
        }
        // Ask if the user wants to calculate again
        cout << "Do you want to calculate another set of coefficients? (y/q): ";
        cin >> choice;
    }

    return 0;
}
