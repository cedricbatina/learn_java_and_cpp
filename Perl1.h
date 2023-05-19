#include <string>

using namespace std;

/*void Perl1::splice(string &str, int pos, int longueur)
{
 int posend = pos + longueur;
 int dimension = str.length();
 if ((pos < 0) || (longueur <= 0) || (pos >= dimension))
  return;
 if ((longueur + pos) > dimension)
 {
  str = str.substr(pos, dimension);
 }
 else
 {
  str = str.substr(0, pos) + str.substr(posend, dimension);
 }
}*/

class Perl1
{
private:
 /* data */
public:
 void splice1(string &str, int pos, int longueur = 1);
};
