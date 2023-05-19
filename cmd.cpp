#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
 /* code */
 for (int i = 1; i < argc; i++)
 {
  if (argv[i][0] != '-')
  {
   cerr << "Caractère - du paramètre manquant" << endl;
   return -1;
  }
  else
  {
   if (argv[i][2] != 0)
   {
    cerr << "Paramètre invalide, trop long";
    return -1;
   }
   switch (argv[i][1])
   {
   case 'l':
    cout << "Le paramètre l est présent";
    break;
   case 'g':
    cout << "Le paramètre g est présent";
    break;
   case 's':
    cout << "Le premier s est présent";
    break;
   default:
    cerr << "Paramètre invalide" << endl;
    return -1;
   }
  }
 }
 return 0;
}
