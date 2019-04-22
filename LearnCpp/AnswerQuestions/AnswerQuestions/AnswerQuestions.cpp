#include <iostream>
using namespace std;
int main()
{
	/*循环从键盘读入若干组选择题答案，计算并输出每组答案的正确率，直到输入ctrl + z为止。
	每组连续输入5个答案，每个答案可以是'a'..'d'*/
	const char answer[] = {'a','b','a','c','d'};
	const int num = 5;
	int head = 0;
	int right = 0;
	char input;
	cout << "请输入你的答案" << endl;
	while (cin.get(input))
	{
		if (input != '\n' && input != ' ')
		{
				if (input == answer[head++])
				{
					cout << "  ";
					++right;
				}
				else
				{
					cout << "x ";
				}
		}
		else if(input == '\n')
		{
			cout << "Score" << static_cast <float>(right)/ num * 100 << "%"  << endl;
			head = 0;
			right = 0;
		}
	}
	system("pause");
	return 0;
}