#include <iostream>
using namespace std;
bool ispalindrome(int temp)
{
	int sum = 0;
	int n = temp;
	if (n > 10)
	{
		while (n)
		{
			sum = sum * 10 + n % 10;
			n /= 10;
		}
		return (sum == temp) ? true : false;
	}
	else 
	{
		return false;
	}
}
void FindPalind(int max)
{
	while (max > 10)
	{
		if (ispalindrome(max) && ispalindrome(max * max) && ispalindrome(max * max * max))
		{
			cout << max << endl;
		}
		--max;
	}
}
int main()
{
	//�ж�0~999�ڵ����Ƿ����
	//����:���������Ϊn���n,n*n,n*n*n�Ľ�����ǻ�������������
	FindPalind(9999999);
	system("pause");
	return 0;
}