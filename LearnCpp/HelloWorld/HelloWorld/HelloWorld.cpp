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
	cout << "请输入一个0~100整数，代表接下来要输入的整数的个数！" << endl;
	cin >> num;
	while (num)
	{
		cout << "请输入任意整数" << endl;
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
	cout << "总和是：" << sum << "最大值是：" << max << "最小值是：" << min << endl;
	system("pause");
	return 0;
}