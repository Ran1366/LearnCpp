#include <iostream>
using namespace std;

bool UglyNum(unsigned int num)
{
	if (num == 1)
	{
		return false;
	}
	else 
	{
		while (true)
		{
			if (num % 2 == 0)
			{
				num /= 2;
				if (num == 1)
				{
					return true;
				}
			}
			else if (num % 3 == 0)
			{
				num /= 3;
				if (num == 1)
				{
					return true;
				}
			}
			else if (num % 5 == 0)
			{
				num /= 5;
				if (num == 1)
				{
					return true;
				}
			}
			else
			{
				return false;
			}
				
		}
	}
}
int main()
{
	/*只包含因子2, 3, 5的正整数被称作丑数，比如4, 10, 12都是丑数，而7, 23, 111则不是丑数，另外1也不是丑数。
	请编写一个函数，输入一个整数n，能够判断该整数是否为丑数，如果是，则输出True，否则输出False。*/
	int result = UglyNum(12);
	cout << result << endl;
	system("pause");
	return 0;
}