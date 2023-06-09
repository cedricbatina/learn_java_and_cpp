#include <string>
class Operation
{
private:
 string loperation;

public:
 Operation(const char *loper);
 int execute(int num1, int num2);
};