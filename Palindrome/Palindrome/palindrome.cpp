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
	//判断0~999内的数是否回文
	//条件:假设这个数为n如果n,n*n,n*n*n的结果都是回文则输出这个数
	FindPalind(9999999);
	system("pause");
	return 0;
}