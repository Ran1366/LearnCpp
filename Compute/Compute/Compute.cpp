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
	//ʹ�ú���ָ��,���к����ص�
	int a = 5; 
	int b = 7;
	cout << "a��b�е����ֵ��" << Compute(a, b, &Max) << endl;
	cout << "a��b�е���Сֵ��" << Compute(a, b, &Min) << endl;
	cout << "a��b�еĺ���" << Compute(a, b, &Sum) << endl;
	system("pause");
	return 0;
}