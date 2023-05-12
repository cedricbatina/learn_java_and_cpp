#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[])
{
 /* code */
 short int feux = 0xFE;
 short int nfeux = feux;

 cout << "Nos feux: " << hex << nfeux << endl;

 nfeux = feux | 0x01; //(A)
 cout << "Nos feux: " << hex << nfeux << endl;
 nfeux = feux ^ 0x03; //(B)
 cout << "Nos feux: " << hex << nfeux << endl;
 nfeux = (~feux) & 0xFF; //(C)
 cout << "Nos feux: " << hex << nfeux << endl;

 cout << "Le feu: " << hex << (feux & 0xA0); //(D)

 return 0;
}
