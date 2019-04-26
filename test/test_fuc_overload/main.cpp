//顶层const不影响传入函数的对象, 一个拥有顶层const的形参无法和另一个没有
//顶层const的形参区分开来
int fuc(int a, int b)
{
  //something...
}
//下面函数有重定义错误
//int fuc(const int a, const int b)
//{
//  //something...
//}

//如果参数是某种类型的指针或引用,则可通过分析其指向的是常量对象还是
//非常量对象实现重载
//对于接受引用或指针的函数来说,对象是常量还是非常量对应的形参不同
int fuc(int *a, int *b)
{
  //something...
}
int fuc(const int *a, const int *b)
{
  //something...
}

int fuc(int &a, int &b)
{
  //something...
}
int fuc(const int &a, const int &b)
{
  //something...
}
