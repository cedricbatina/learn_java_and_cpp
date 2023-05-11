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
