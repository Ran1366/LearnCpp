#include <iostream>
using namespace std;
class A
{
public:
  A(int a)
  {
    _a = a;
    cout << _a << endl;
  }
private:
  int _a;
};

class B
{
public:
  B(int a, int b, int c)
    :_a(a)
    ,_b(b)
    ,_c(c)
  {
  }
  A _b;
  A _c;
  A _a;
};

int main()
{
  B b(1,2,3);
  return 0;
}
