// la classe list en c++
#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>

using namespace std;

int main(int argc, char const *argv[])
{
 int tableau1[] = {1, 2, 4, 8, 16, 32, 64};
 int tableau2
     [] = {9, 8, 7, 6, 5, 4, 3, 2, 1};

 list<int> liste1(tableau1, tableau1 + 7);
 list<int> liste2(tableau2, tableau2 + 9);

 liste1.merge(liste2);
 liste1.remove(32);
 liste1.sort();
 liste1.unique();
 liste1.reverse();
 ostream_iterator<int> out(cout, " ");
 copy(liste1.begin(), liste1.end(), out);
 cout << endl;
 return 0;
}
