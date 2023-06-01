#ifdef GNU
#define GNU_UNIX
#endif

#ifdef UNIX
#define GNU_UNIX
#endif

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
/* code */
#ifdef GNU
 cout << "Avec GNU" << endl;
#endif

#ifdef GNU_UNIX
 cout << "Avec GNU et UNIX" << endl;
#endif
#ifndef DOS
 cout << "Sans DOS" << endl;
#endif
 cout << "Avec tous" << endl;
 return 0;
}
