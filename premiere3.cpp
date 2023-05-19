#include <iostream>

using namespace std;

const int dim = 5;

int main(int argc, char const *argv[])
{
 /* code */
 int premier[5] = {1, 2, 3, 5, 7};
 int **ppremier1;
 int **ppremier2;
 int i = 0;

 ppremier1 = (int **)new int[dim];
 ppremier2 = ppremier1;

 for (i = 0; i < dim; i++)
 {
  ppremier1[i] = new int(0);
  *ppremier1[i] = premier[i];
 }
 for (i = 0; i < dim; i++)
 {
  cout << *ppremier2[i] << " ";
  delete ppremier2[i];
 }
 cout << endl;
 delete[] ppremier1;
 return 0;
}
