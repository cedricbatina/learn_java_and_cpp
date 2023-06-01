#include <iostream>
#include <string>

using namespace std;

class Tirenumero
{
private:
 /* data */
 static int nombre_sorti;
 static bool *ptirage;
 int quel_numero;

public:
 Tirenumero()
 {
  if (ptirage == 0)
  { // premier usage
   ptirage = new bool[10];
   for (int i = 0; i < 10; i++)
   {
    *(ptirage + i) = false;
   }
   quel_numero = 1;
   *ptirage = true;
   nombre_sorti = 1;
   return;
  }
  if (nombre_sorti == 10)
  {
   quel_numero = 0;
  }
  else
  {
   nombre_sorti++;
   for (int i = 0; i < 10; i++)
   {
    if (*(ptirage + i) == false)
    {
     *(ptirage + i) = true;
     quel_numero = i + 1;
     break;
    }
   }
  }
 }
 ~Tirenumero()
 {
  if (quel_numero != 0)
  {
   nombre_sorti--;
   *(ptirage + quel_numero - 1) = false;
   if (nombre_sorti == 0)
   {
    delete ptirage;
    ptirage = 0;
    cout << "Tous les numéros sont rentrés: " << endl;
   }
  }
 }
 int get_numero()
 {
  return quel_numero;
 }
 static int get_nombre_sorti()
 {
  return nombre_sorti;
 }
 static void message1()
 {
  cout << "Nombre sorti: " << get_nombre_sorti() << endl;
 }
 void message2()
 {
  cout << "Nombre actuel: " << get_numero() << endl;
 };

 // int Tirenumero::nombre_sorti = 0;
 // bool *Tirenumero::ptirage = 0;

 int main(int argc, char const *argv[])
 {
  /* code */
  Tirenumero *ptn;

  Tirenumero tn1;
  Tirenumero::message1();
  tn1.message2();

  Tirenumero tn2;
  Tirenumero::message1();
  tn2.message2();

  ptn = new Tirenumero();
  Tirenumero::message1();
  ptn->message2();
  delete ptn;
  Tirenumero::message1();

  ptn = new Tirenumero();
  Tirenumero ttn[20];

  Tirenumero::message1();
  ttn[19].message2();

  delete ptn;

  Tirenumero tn3;
  tn3.message1();
  tn3.message2();
  ttn[5].message2();

  cout << "Fin des tests" << endl;
  return 0;
 }
};