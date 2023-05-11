#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
 /* code */
 if (argc != 3)
 {
  cerr << "Nombre invalide de paramètres" << endl;
  return -1;
 }
 cout << "argv[0]: " << argv[0] << endl;
 cout << "argv[1]: " << argv[1] << endl;
 cout << "argv[2]: " << argv[2] << endl;
 cout << "Adresse de argv[0]: " << &argv[0] << endl;
 return 0;
}
