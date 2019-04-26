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

  //string的操作
  //is >> s 将is中读取字符串赋给s, 字符串以空白符分隔, 返回is
  cin >> s1;
  //os << s 将s写到输出流os中, 返回os
  cout << s1 << endl;
  //getline(is, s)  从is中读取一行赋给s, 返回is
  getline(cin, s1);
  //s.empty() s为空返回ture, 否则返回false
  bool re = s1.empty();
  if(re)
  {
    cout << re << endl;
  }
  //s.size() 返回s中字符的个数
  auto size = s1.size();
  if(size)
  {
    cout << "size = " << size << endl;
  }
  //s[n] 返回s中第n个字符的引用, 位置n从0开始
  char n = s1[0];
  if(n)
  {
    cout << "s1[0] = " << n << endl;
  }
  //s1 + s2   返回s1和s2连接后的结果
  string ss = s1 + s2;
  cout << "ss = " << ss << endl;
  //s1 = s2   用s2的副本代替s1中原来的字符
  s1 = s2;
  cout << "s1 = " << s1 << endl;
  //s1 == s2  如果s1的内容和s2相等则返回ture, 否则返回false, 判断对大小写敏感
  if(s1 == s2)
  {
    cout << "s1 = s2" << endl;
  }
  //s1 != s2  判断是否不相等, 对大小写敏感
  if(s1 != s2) 
  {
    cout << "s1 != s2" << endl;
  }
  //<, <=, >, >=  利用字典序进行比较, 对字母大小写敏感
  if(s1 > s2) 
  {
    cout << "s1 > s2" << endl;
  }

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

