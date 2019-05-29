#include <iostream>
#include <cstdio>
using namespace std;
//动态规划问题n*m的方格,只能靠边沿线走从左上角到右下角有多少种走法
//由于读错题了...最初设计是走方格,现在改成了走边沿线...,原来的m和n
//部分改成了(m + 1)和(n + 1)
int main() {
  size_t n, m;
  cin >> n >> m;
  size_t size = (n - 1)*(m - 1) + (n + m - 2) * 2 + 4;
  size_t *arr = new size_t[size];
  for (size_t i = 0; i < m + 1; ++i)
  {
    arr[i] = 1;
  }
  for (size_t i = 0; i < n + 1; ++i)
  {
    arr[i * (m + 1)] = 1;
  }
  for (size_t i = m + 2; i < (n + 1)*(m + 1); ++i)
  {
    arr[i] = arr[i - 1] + arr[i - m - 1];
    if ((i + 1) % (m + 1) == 0)
    {
      ++i;
    }
  }
  cout << arr[(n + 1)*(m + 1) - 1] << endl;
  system("pause");
  return 0;

}
