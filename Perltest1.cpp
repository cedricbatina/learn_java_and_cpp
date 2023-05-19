#include <iostream>
#include <string>
#include "Perl1.h"

using namespace std;

int main(int argc, char const *argv[])
{
 /* code */
 string mon_string("0123456789abcdef");
 Perl1 mon_perl;

 cout << "0           :" << mon_string << endl;

 mon_perl.splice1(mon_string, 3, 2);
 cout << "1   (3,2)   :" << mon_string << endl;

 mon_perl.splice1(mon_string, 0, 3);
 cout << "2   (0, 3)  :" << mon_string << endl;

 mon_perl.splice1(mon_string, 100, 4);
 cout << "3   (100,4) :" << mon_string << endl;

 mon_perl.splice1(mon_string, 4, 100);
 cout << "4   (4,100) :" << mon_string << endl;

 mon_perl.splice1(mon_string, 2);
 cout << "5   (2)     :" << mon_string << endl;

 return 0;
}
