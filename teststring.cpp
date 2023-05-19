#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
 /* code */
 string aref = "<a href =\"mailto:cedricbatina2021@gmail.com\">";

 for (int i = 0; i < aref.length(); i++)
 {
  if ((aref[i] >= 'A') && (aref[i] <= 'Z'))
  {
   aref[i] += 32;
  }

  /*if (isupper(aref[i])) // Vérifier si le caractère est en majuscule
  {
   aref[i] = tolower(aref[i]); // Convertir en minuscule
  }*/
 }
 int index1 = aref.find("href=\"");
 if (index1 >= 0)
 {
  index1 += 6;
  int index2 = aref.find("\"", index1);
  if (index2 >= 0)
  {
   string urlstr = aref.substr(index1, index2 - index1);

   if (urlstr.find("mailto:") == 0)
   {
    string emaila = urlstr.substr(7);
    int indexa = emaila.find("@");
    if (indexa <= 0)
    {
     cout << "Adresse email invalide: " << emaila << endl;
    }
    else
    {
     cout << "Adresse email: " << emaila << endl;
    }
   }
  }
 }
}
