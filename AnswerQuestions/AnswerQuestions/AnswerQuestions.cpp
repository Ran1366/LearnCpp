#include <iostream>
using namespace std;
int main()
{
	/*ѭ���Ӽ��̶���������ѡ����𰸣����㲢���ÿ��𰸵���ȷ�ʣ�ֱ������ctrl + zΪֹ��
	ÿ����������5���𰸣�ÿ���𰸿�����'a'..'d'*/
	const char answer[] = {'a','b','a','c','d'};
	const int num = 5;
	int head = 0;
	int right = 0;
	char input;
	cout << "��������Ĵ�" << endl;
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