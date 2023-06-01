// options de formatage
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
 /* code */
 ostringstream sortie1;
 sortie1 << "Bonjour Monsieur ";
 sortie1 << "0123456789abcdefg" << endl;
 cout << "Test1: " << sortie1.str() << endl;

 ostringstream sortie3;
 sortie3 << "12345" << ends;
 sortie3 << "6789 " << ends;
 cout << "Test2: " << sortie3.str() << endl;

 stringstream entree_sortie1;
 entree_sortie1 << "abcd\n1234" << endl;
 cout << "Test3: " << sortie3.str() << endl;

 stringstream entree_sortie2;
 int nombre1 = 10;
 int nombre2 = 20;

 string un_string1 = "Bonjour";
 entree_sortie2 << nombre1 << " . " << nombre2 << un_string1 << ends;
 cout << "Test4: " << entree_sortie2.str() << endl;

 double double1;
 entree_sortie2 >> double1;
 cout << "Test5: " << double1 << endl;

 string un_string2;
 entree_sortie2 >> un_string2;
 cout << "Test6: " << un_string2 << endl;

 ostringstream sortie4;
 sortie4.fill('0');
 sortie4.setf(ios::right, ios::adjustfield);
 sortie4.width(10);
 double double2 = 1.234;
 sortie4 << double2;
 sortie4 << "|";
 sortie4.setf(ios::left, ios::adjustfield);
 sortie4.width(8);
 sortie4.precision(3);
 sortie4 << double2;
 sortie4 << "|";
 int nombre5 = 31;
 sortie4 << hex << nombre5 << ":" << oct << nombre5 << ends;

 cout << "Test7: "
      << "[" << sortie4.str() << "]" << endl;

 return 0;
}
