#include <iostream>
#include <string>

using std::cout;
using std::string;
using std::endl;
int main()
{
  string s = "helo world";
  for(auto as : s)
  {
    cout << as << endl;
  }
  int arr[5][5];
  int i = 0;
  //要改变元素的值,需要把控制变量row和col声明为引用类型
  for(auto &row : arr)
  {
    for(auto &col : row)
    {
      col = i++;
    }
  }
  //与上面的代码一样, 这里将row声明为引用类型, 这样在内层循环中row就不会自动转换为指针
  //在指针中遍历是不符合预期的
  for(auto &row : arr)
  {
    for(auto cow : row)
    {
      cout << cow << endl;
    }
  }
  return 0;
}
