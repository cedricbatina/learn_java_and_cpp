#include <iostream>

using namespace std;

class Othello1
{
private:
 const static int dim = 10; // 8 x 8 plus les bords
 int othello[dim][dim];     // le jeu

public:
 Othello1();
 void un_test();
};
Othello1::Othello1()
{
 int i = 0; // position horizontale
 int j = 0; // position verticale

 for (i = 0; i < dim; i++)
 { // bord à -1
  othello[i][0] = -1;
  othello[i][dim - 1] = -1;
  othello[0][i] = -1;
  othello[dim - 1][i] = -1;
 }
 ///
 /*for (i = 0; i < dim; i++)
 { // bord à -1
  othello[0][i] = -1;
  othello[dim - 1][i] = -1;
  othello[i][0] = -1;
  othello[i][dim - 1] = -1;
 }*/

 //
 for (j = 1; j < dim; j++)
 {
  // intérieur vide
  for (i = 1; i < dim; i++)
  {
   othello[i][j] = 0;
  }
 }
 othello[4][5] = 1; // blanc
 othello[5][4] = 1; // blanc
 othello[4][4] = 2; // noir
 othello[5][5] = 2; // noir
}
void Othello1::un_test()
{
 int i = 0; // position horizontale
 int j = 0; // position verticale

 for (j = 0; j < dim; j++)
 {
  for (i = 0; i < dim; i++)
  {
   if (othello[i][j] >= 0)
    cout << " ";

   cout << othello[i][j] << " ";
  }
  cout << endl;
 }
}
int main()
{
 /* code */
 Othello1 lejeu;
 lejeu.un_test();
 // system("pause");

 return 0;
}
