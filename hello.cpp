// hello.cpp
#include <ctime>
#include <iostream>

using namespace std;
int main()
{
 time_t maintenant;
 time(&maintenant);

 cout << "Hello world en C++: " << ctime(&maintenant) << endl;
 return 0;
}

int valeur1;
// valeur1 = 10;
int valeur2 = 20;
int valeur3(30);
float valeur4 = 1.2;
double valeur5 = 1000000;