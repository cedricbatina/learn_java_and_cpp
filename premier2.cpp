#include <iostream>

using namespace std;

const int dim = 5;

int main(int argc, char const *argv[])
{
 /* code */
 int premier[] = {1, 2, 3, 5, 7};
 // ou bien aussi
 // int premier[5] = {1, 2, 3, 5, 7};

 for (int i = 0; i < dim; i++)
 {
  cout << premier[i] << " ";
 }
 cout << endl;
 return 0;
}
