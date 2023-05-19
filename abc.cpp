#include <iostream>
using namespace std;
int i = 0;

int main(int argc, char const *argv[])
{
 /* code */
 for (i = 0; i < 3; i++)
 {
  cout << (char)('a' + i);
 }

 int j = 3;
 while (j != 0)
 {
  cout << (char)('p' - j--);
 }

 char lettre = 'a';
 do
 {
  cout << lettre;
  lettre++;
 } while (lettre != 'd');

 cout << endl;

 return 0;
}
