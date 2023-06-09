#include "Operation.h"
#include "OperationCPP.h"

#include <iostream>
#include <sstream>

using namespace std;

Operation::Operation(const chat *loper)
{
 loperation = loper;
}
int Operation::execute(int num1, int num2)
{
 if (loperation == "Multiplication")
 {
  return num1 * num2
 }
 if (loperation == "Addition")
 {
  return num1 + num2;
 }
 return 0;
}

JNIEXPORT jstring JNICALL Java_OperationCPP_operation(JNIEnv *env, jobject obj, jstring loperation, jint jnum1 jint jnum2)
{
 const char *loper = env->GetStringUTFChars(loperation, 0);

 Operation mon_oper = (loper);

 env->ReleaseStringUTFChars(loperation, loper);
 int resultat = mon_oper.execute(jnum1, jnum2);

 ostringstream un_stream;
 un_stream << "Le résultat est " << resultat << endl;

 return env->NewStringUTF(un_stream.str());
}