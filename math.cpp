#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main(int argc, char const *argv[])
{
 /* code */
 double a = 2.0;
 double b = 3.0;
 double c = a * b;

 cout << "Multiplication: " << c << endl;
 c = sin(a) * cos(b) + sin(b) * cos(a); // sin(a + b )

 cout << "Sinus(a + b): " << setprecision(16) << c << endl;

 c = pow(a, b);
 cout << "a à la puissance b: " << c << endl;

 double d1 = 5;
 double d2 = 2;
 int i1 = 5;
 int i2 = 2;

 double d3 = d1 / d2; // 2.5
 int i3 = i1 / i2;    // 2
 int i4 = i1 % i2;    // 1
 // d3 = d1 % d2;        // erreur de compilation

 return 0;
}
