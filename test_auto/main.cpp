#include <iostream>
using namespace std;

int main()
{
  //auto自动判断类型, 忽略顶层const
  int i = 0;
  const int ci = i, &cr = ci;
  auto int b = ci;
  int *r = &b;
  b = 5;
  std::cout << b << std::endl;
  return 0;
}
