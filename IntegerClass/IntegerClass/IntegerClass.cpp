#include <iostream>
using namespace std;
class Integer 
{
public:
	Integer();
	Integer(int a);
	Integer(const Integer &n);
	~Integer();
	int Comdiv(Integer a);  //求Integer类的两个数num的最大公约数
	int GetMin(Integer a);	//求Integer类的两个数num中较小的那个数
private:
	int num;
};
Integer::Integer()
{
}
Integer::Integer(int a):num(a)
{
}
Integer::~Integer()
{
}
Integer::Integer(const Integer &a):num(a.num)
{
}
int Integer::GetMin(Integer a)
{
	return (this->num > a.num) ? a.num : this->num;
}
int Integer::Comdiv(Integer a)
{
	if (this->num > 0 && a.num > 0)
	{
		int max = 1;
		int counts = a.GetMin(this->num);  //以两个数中较小的那个数作为循环次数
		for (int i = 1 ; i <= counts ; ++i)
		{
			if (this->num % i == 0 && a.num % i == 0)
			{
				max = i;
			}
		}
		return max;
	}
	return 0;
}
int main()
{
	//求两个正整数a 和 b的最大公约数。要求使用c++ class编写程序
	cout << "请输入两个正整数" << endl;
	int a = 0;
	int b = 0;
	cin >> a >> b;
	Integer num1(a);
	Integer num2(b);
	cout << "最大公约数是：" << num1.Comdiv(num2) << endl;
	system("pause");
	return 0;
}