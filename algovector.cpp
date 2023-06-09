// la classe vector en c++ et l'algorithme

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

bool monAlgo(int nombre1, int nombre2)
{
 int reste1 = nombre1 % 10;
 int reste2 = nombre2 % 10;

 if (reste1 > reste2)
  return true;
 if (reste1 == reste2)
 {
  if (nombre1 < nombre2)
   return true;
 }
 return false;
}

int main(int argc, char const *argv[])
{
 vector<int> v_entier;
 srand((unsigned)time(NULL));

 for (int i = 0; i < 16; i++)
 {
  v_entier.push_back((rand() * 200) / RAND_MAX);
 }

 vector<int>::iterator it_debut = v_entier.begin();
 const vector<int>::iterator it_fin = v_entier.end();

 sort(v_entier.begin(), v_entier.end());

 while (it_debut != it_fin)
 {
  cout << *it_debut++ << " ";
 }
 cout << endl;

 it_debut = v_entier.begin();

 sort(v_entier.begin(), v_entier.end(), monAlgo);
 while (it_debut != it_fin)
 {
  cout << *it_debut++ << " ";
 }
 cout << endl;
 cout << "Dimension du vector v_entier: " << v_entier.size() << endl;
 return 0;
}
