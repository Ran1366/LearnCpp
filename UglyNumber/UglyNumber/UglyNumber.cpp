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
	/*ֻ��������2, 3, 5������������������������4, 10, 12���ǳ�������7, 23, 111���ǳ���������1Ҳ���ǳ�����
	���дһ������������һ������n���ܹ��жϸ������Ƿ�Ϊ����������ǣ������True���������False��*/
	int result = UglyNum(12);
	cout << result << endl;
	system("pause");
	return 0;
}