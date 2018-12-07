#include <iostream>
using namespace std;
int Compute(int a , int b , int(*func)(int x , int y))
{
	return func(a, b);
}
int Min(int a ,int b)
{
	return (a < b) ? a : b;
}
int Max(int a ,int b)
{
	return (a < b) ? b : a;
}
int Sum(int a ,int b)
{
	return a + b;
}
int main()
{
	//使用函数指针,进行函数回调
	int a = 5; 
	int b = 7;
	cout << "a和b中的最大值是" << Compute(a, b, &Max) << endl;
	cout << "a和b中的最小值是" << Compute(a, b, &Min) << endl;
	cout << "a和b中的和是" << Compute(a, b, &Sum) << endl;
	system("pause");
	return 0;
}