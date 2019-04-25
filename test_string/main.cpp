#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
int main()
{
  //初始化string对象的方式
  string s1;//默认初始化, s1是一个空串
  string s2(s1);//s2是s1的副本
  string s3 = s1;//等价于s3(s1), s3是s1的副本
  string s4("string");//s5是字面值常量"string"的副本,除了字面值最后那个空字符外
  string s5 = "string";//等价于s4("string"),s3是字面值常量"string"的副本
  string s6(10, 's');//把s6初始化为由连续10个字符s组成的串
  
  string s7 = "hello world";
  cout << s7 << endl;

  //循环读取字符串, 直到文件结束
  while(cin >> s1)
  {
    //如果输入不为空则打印
    if(!s1.empty())
    {
      cout << s1 << endl;
    }
  }

  //按行循环读取字符串, 直到文件结束
  while(getline(cin, s1))
  {
    //如果输入不为空则打印
    if(!s1.empty())
    {
      cout << s1 << endl;
    }
  }
  //两者区别在于, 前者忽略起始的空白符, 从第一个字符开始读取直到下一个空白字符
  //后者读取内容,直到遇到换行符为止,(换行符也被读取了),然后把读入的内容存入sting对象中(不存换行符)
  //如果只读到一个换行符, 就得到空字符串
  return 0;
}

