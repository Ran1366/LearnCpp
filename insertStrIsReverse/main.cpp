#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>
using namespace std;

bool isReverse(const string &str)
{
  auto begin = str.begin();
  auto end = str.end();
  --end;
  while (begin < end)
  {
    if (*begin != *end)
    {
      return false;

    }
    ++begin;
    --end;

  }
  return true;

}
int main() {
  string A, B;
  cin >> A >> B;
  int res = 0;
  for (int i = 0; i <= (int)A.size(); ++i)
  {
    string tmp = A;
    tmp.insert(i,B);
    if (isReverse(tmp))
    {
      ++res;
    }
  }
  cout << res << endl;
  system("pause");
  return 0;
}
