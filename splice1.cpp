#include <iostream>
#include <cstring>

using namespace std;

void splice1(char *pstr, int pos, int longueur);
char *splice2(const char *ptstr, int pos, int longueur);

int main(int argc, char const *argv[])
{
 /* code */
 // char *pmon_string = "0123456789";
 char pmon_string[11];
 char *pmon_nouveau;
 strcpy(pmon_string, "0123456789");
 cout << "0: " << pmon_string << endl;

 splice1(pmon_string, 3, 2);
 cout << "11: " << pmon_string << endl;
 if ((pmon_nouveau = splice2(pmon_string, 3, 2)) == 0)
  return 0;
 cout << "12: " << pmon_nouveau << endl;
 delete pmon_nouveau;

 splice1(pmon_string, 0, 2);
 cout << "21: " << pmon_string << endl;
 if ((pmon_nouveau = splice2(pmon_string, 0, 2)) == 0)
  return 0;
 cout << "22: " << pmon_nouveau << endl;
 delete pmon_nouveau;

 splice1(pmon_string, 3, 100);
 cout << "31: " << pmon_nouveau << endl;
 if ((pmon_nouveau = splice2(pmon_string, 3, 100)) == 0)
  return 0;
 cout << "32: " << pmon_nouveau << endl;
}
void splice1(char *pstr, int pos, int longueur)
{
 // code ci-dessus
}
char *splice2(const char *pstr, int pos, int longueur)
{
 // code ci-dessus
 return nullptr; // Ajout d'une instruction return appropriée
}