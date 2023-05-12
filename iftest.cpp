#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
 /* code */
 int nombre1 = 0;
 int nombre2 = 0;

 cout << "Entre un premier nombre: ";
 cin >> nombre1;
 cout << nombre1 << endl;

 cout << "Entre un deuxième nombre: ";
 cin >> nombre2;
 cout << nombre2;

 if (nombre1 > nombre2)
 {
  cout << nombre1 << "est plus grad que" << nombre2 << endl;
 }
 else
 {
  cout << nombre1 << "est plus petit que" << nombre2 << endl;
 }

 return 0;
}
