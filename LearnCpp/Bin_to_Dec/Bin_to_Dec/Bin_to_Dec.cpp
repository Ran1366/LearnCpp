#include <iostream>
using namespace std;
int power(int num , int n)
{
	int sum = 1;
	if (n)
	{
		while (n)
		{
			sum *= num;
			--n;
		}
		return sum;
	}
	else
	{
		return 1;
	}
}
void Trans(int bin,int counts,int sum)
{
	if (bin)
	{
		if (bin % 2 == 1)
		{
			sum += power(2, counts);
		}
		++counts;
		bin /= 10;
		Trans(bin,counts,sum);
	}
	else
	{
		cout << sum << endl;
	}
}
void Bin_to_Dec(int bin)
{
	int counts = 0;
	int sum = 0;
	int temp = bin;
	bool legal = true;
	while (temp)
	{
		if (!(temp % 10 == 0 || temp % 10 == 1))
		{
			legal = false;
		}
		temp /= 10;
	}
	if (legal)
	{
		Trans(bin,0,0);
	}
	else
	{
		cout << "您输入的数据不合法！" << endl;
	}
}
int main()
{
	//已知一个只包含 0 和 1 的二进制数，长度不大于 10 ，将其转换为十进制并输出。
	int input = 0;
	cout << "输入一个二进制数，将其转换为十进制" << endl;
	cin >> input;
	Bin_to_Dec(input);
	system("pause");
	return 0;
}