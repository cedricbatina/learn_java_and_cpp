#include "SalutCPP.h";
#include <iostream>

using namespace std;

JNIEXPORT void JNICALL Java_SalutCPP_salutations(JNIEnv *, jobject)
{
 cout << "c++; salutations depuis la bibliothèque salut.dll" << endl;
}
