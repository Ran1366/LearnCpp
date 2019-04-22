#include <iostream>
using namespace std;
int TenPow(int a)     
{
	int result = 1;
	while (a)
	{
		result *= 10;
		--a;
	}
	return result;
}
class Integer
{
public:
	Integer() {};
	Integer(int a) :num(a) {};
	Integer(const Integer &a) :num(a.num) {};
	~Integer() {};
	int Reverse();
	int GetLen();
private:
	int num;
};
int Integer::GetLen()
{
	int a = this->num;
	if (a >= 0)
	{
		int len = 0;
		while (a)
		{
			a /= 10;
			++len;
		}
		return len;
	}
	return -1;
}
int Integer::Reverse()
{
	int a = this->num;
	int power = this->GetLen() - 1; //10的power次幂
	if (a> 0)
	{
		int remain = -1; // 余数
		int sum = 0;	//逆置后的数
		while (a)
		{
			remain = a % 10;
			sum += remain * TenPow(power);
			a /= 10;
			--power;
		}
		return sum;
	}
	return -1;
}
int main()
{
	//对于输入的一个正整数，输出其反转形式,要求使用c++ class编写程序
	cout << "请输入一个正整数,将输出它的反转形式" << endl;
	int a = 0;
	cin >> a;
	Integer num(a);
	cout << num.Reverse() << endl;
	system("pause");
	return 0;
}