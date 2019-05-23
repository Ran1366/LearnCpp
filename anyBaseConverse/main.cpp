#include <iostream>
#include <stack>
using namespace std;
int main() {
  int arr[2];
  for(int i = 0; i < 2; ++i)
  {
    cin >> arr[i];
  }
  char numbers[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
  stack<char> ret;
  int num = arr[0];
  int into = arr[1];
  int quotients = 0;
  int remainder = 0;
  if(num < 0)
  {
    num = -num;
  }
  while(num >= into)
  {
    //quotients英语单词:商
    //remainder:余数
    quotients = num / into;
    remainder = num % into;
    num /= into;
    ret.push(numbers[remainder]);
  }
  ret.push(numbers[quotients]);
  if(arr[0] < 0)
  {
    ret.push('-');
  }
  while(!ret.empty())
  {
    cout << ret.top();
    ret.pop();
  }
  cout << endl;
  return 0;
}
