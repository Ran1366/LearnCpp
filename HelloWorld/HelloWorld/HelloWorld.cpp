#include <iostream>
using namespace std;
using uint = unsigned int;
int main()
{
	int num;
	int sum = 0;
	int input = 0;
	int max = 0;
	int min = 9999;
	cout << "������һ��0~100���������������Ҫ����������ĸ�����" << endl;
	cin >> num;
	while (num)
	{
		cout << "��������������" << endl;
		cin >> input;
		if (input > max)
		{
			max = input;
		}
		if (input < min)
		{
			min = input;
		}
		sum += input;
		--num;
	}
	cout << "�ܺ��ǣ�" << sum << "���ֵ�ǣ�" << max << "��Сֵ�ǣ�" << min << endl;
	system("pause");
	return 0;
}