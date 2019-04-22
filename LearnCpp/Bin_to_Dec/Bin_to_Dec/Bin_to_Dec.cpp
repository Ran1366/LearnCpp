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
		cout << "����������ݲ��Ϸ���" << endl;
	}
}
int main()
{
	//��֪һ��ֻ���� 0 �� 1 �Ķ������������Ȳ����� 10 ������ת��Ϊʮ���Ʋ������
	int input = 0;
	cout << "����һ����������������ת��Ϊʮ����" << endl;
	cin >> input;
	Bin_to_Dec(input);
	system("pause");
	return 0;
}