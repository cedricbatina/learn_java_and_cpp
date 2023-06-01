// la fonction sprintf() de la bibliothèque c
#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;
int const protect = 10;

int main(int argc, char const *argv[])
{
 /* code */
 unsigned char protection1[protect];
 char tampon[25];
 unsigned char protection2[protect];
 int i;
 for (i = 0; i < protect; i++)
 {
  protection1[i] = 255;
  protection2[i] = 255;
 }
 sprintf(tampon, "Bonjour Monsieur %s Salut %d\n", "ABCDEFG", atoi("1234"));

 cout << tampon;
 cout << "1234567890123456789901233456789012345" << endl;

 for (i = 0; i < protect; i++)
 {
  if (protection2[i] != 255)
  {
   cout << "Erreur dans protection1 à l'index " << i
        << "(" << protection1[i] << ")" << endl;
  }
 }
 if (protection2[i] != 255)
 {
  cout << "Erreur dans protection2 à l'index " << i << "(" << protection1[i] << ")" << endl;
 }
 return 0;
}
