// exemple de modèle de classe en cpp

#include <iostream>

template <class T>
class Point
{
 T posX;
 T posY;

public:
 Point(T x, T y)
 {
  posX = x;
  posY = y;
 }
 void test();
};

template <class T>

void Point<T>::test()
{
 std::cout << "Position: " << posX << " : " << posY << std::endl;
};
using namespace std;

int main(int argc, char const *argv[])
{
 Point<int> pint(1, 2);
 pint.test();

 return 0;
}
