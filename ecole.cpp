#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
 /* code */
 int age = 0;
 bool balecole = false;

 cout << "Entre ton âge: ";
 cin >> age;

 if ((age < 17) && (age >= 6))
 {
  cout << "Tu dois aller à l'école, petit!" << endl;
  balecole = true;
 }
 else
 {
  cout << "Tu peux rester à la maison!" << endl;
 }

 return 0;
}
