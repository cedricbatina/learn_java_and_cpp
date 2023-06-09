#include <iostream>

using namespace std;

class othello2
{
private:
 /* data */
 static const int dim = 10;
 static const int case_vide = 0;
 static const int case_bord = -1;

 int othello[dim][dim]; // le jeu
 static const int position[8][2];

public:
 static const int pion_blanc = 1;
 static const int pion_noir = 2;

 othello2(/* args */);
 void dessine();
 bool jouable(const int pion, const int posx, const int posy);
};
const int othello2::position[8][2] = {
    {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};

othello2::othello2()
{
 int i = 0; // position horizontale
 int j = 0; // position verticale

 for (i = 0; i < dim; i++)
 { // les bords
  othello[i][0] = case_bord;
  othello[i][dim - 1] = case_bord;
  othello[0][i] = case_bord;
  othello[dim - 1][i] = case_bord;
 }
 for (j = 1; j < dim - 1; j++)
 { // intérieur vide
  for (i = 1; i < dim - 1; i++)
  {
   othello[i][j] = case_vide;
  }
 }
 othello[4][5] = pion_blanc;
 othello[5][4] = pion_blanc;
 othello[6][4] = pion_blanc;
 othello[4][4] = pion_noir;
 othello[5][5] = pion_noir;
}
void othello2::dessine()
{
 int i = 1; // position horizontale
 int j = 1; // position verticale

 cout << " 1 2 3 4 5 6 7 8" << endl;
 for (j = 1; j < dim - 1; j++)
 {
  cout << j;
  for (i = 1; i < dim - 1; i++)
  {
   switch (othello[i][j])
   {
   case pion_noir:
    cout << "N";
    break;
   case pion_blanc:
    cout << "B";
    break;
   default:
    cout << " ";
    break;
   }
  };
  cout << endl;
 }
}
bool othello2::jouable(const int pion, const int posx, const int posy)
{
 if (othello[posx][posy] != case_vide)
  return false;
 int pion_inverse = pion_blanc;
 if (pion == pion_blanc)
  pion_inverse = pion_noir;
 int mult = 2;
 int piont;
 for (int dir = 0; dir < 8; dir++)
 {
  if (othello[posx + position[dir][0]][posy + position[dir][1]] == pion_inverse)
  {
   for (;;)
   {
    piont = othello[posx + (mult * position[dir][0])][posy + (mult * position[dir][1])];
    if (piont == pion)
     return true;
    if (piont != pion_inverse)
     break;
    mult++;
   }
  }
 }
 return false;
}
int main(int argc, char const *argv[])
{
 othello2 lejeu;
 int x, y;
 for (;;)
 {
  lejeu.dessine();
  cout << "Noir joue en x: ";
  cin >> x;
  if (x == 0)
   break;
  cout << "y: ";
  cin >> y;

  bool resultat = lejeu.jouable(othello2::pion_noir, x, y);
  cout << "Jouable en " << x << ":" << y << " = " << resultat << endl;
 }
 return 0;
}
