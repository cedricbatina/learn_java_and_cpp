// les algorithmes du langage c++
#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
 char pchar1[21] = "<daiKRgAcD1TewQ96Qd>";
 char pchar2[21];

 int table[7] = {5, 5, 5, 4, 3, 2, 1};
 cout << "Test1: " << pchar1 << endl;
 sort(pchar1 + 1, pchar1 + 19);
 cout << "Test2: " << pchar1 << endl;

 copy(pchar1, pchar1 + 10, pchar2 + 10);
 copy(pchar1 + 10, pchar1 + 20, pchar2);
 pchar2[20] = 0;

 cout << "Test3: " << pchar2 << endl;

 sort(table, table + 7);

 cout << "Test4: ";
 for (int i = 0; i < 7; i++)
 {
  cout << table[i] << " ";
 }
 cout << endl;

 cout << "Test5: " << count(table, table + 7, 5) << endl;

 return 0;
}
