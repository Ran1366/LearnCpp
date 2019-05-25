#include <iostream>
using namespace std;

int Count(int product)
{
  int num = 0;
  int count = 0;
  for (int i = 0; i < product; ++i)
  {
    if (count < 2)
    {
      ++num;
      ++count;
    }
    else
    {
      count = 0;
      ++i;
    }
  }
  return num;
};
int main()
{
  int row, col;
  cin >> row >> col;
  if (row < 3 && col < 3)
  {
    cout << row * col << endl;
  }
  else if ((row >= 3 && col < 3) || (col >= 3 && row < 3))
  {
    if (col > row)
    {
      int tmp = col;
      col = row;
      row = tmp;
    }
    int num = Count(row);
    cout << num * col << endl;
  }
  else
  {
    int num = Count(row * col);
    cout << num << endl;
  }
  return 0;
}
