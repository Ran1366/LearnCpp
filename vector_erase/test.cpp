#include <iostream>
#include <vector>

using namespace std;
int main()
{
  //由于erase擦除数据后,返回的是当前迭代器的下一个位置,
  //相当于++it,当前条件结束后,又++it所以相当于遇到300,++两次it
  //循环只执行了4次
  vector<int> v;
  //v.push_back(100);
  //v.push_back(300);
  //v.push_back(300);//被跳过判断
  //v.push_back(300);
  //v.push_back(300);//被跳过判断
  //v.push_back(500);
  
  //为了验证,可以改变由擦除行为++it的部分的数字 
  //第一个for循环中依然是打印100 300 300 500
  v.push_back(100);
  v.push_back(300);
  v.push_back(200);//被跳过判断
  v.push_back(300);
  v.push_back(200);//被跳过判断
  v.push_back(500);
  vector<int>::iterator it;
  int i = 0;
  for(it = v.begin(); it != v.end(); ++it)
  {
    ++i;
    cout << i << " " << *it << endl; 
    if(*it == 300)
    {
      it = v.erase(it);
    }
  }
  for(it = v.begin(); it != v.end(); ++it)
  {
    cout << *it << " ";
  }
  cout << endl;
  return 0;
}
