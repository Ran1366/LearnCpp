#include <iostream>
#include <map>
using namespace std;
int main()
{
	map<char, int> letter;
	cout << "��������ĸ,�ж�ÿ����ĸ�����ּ���" << endl;
	char c;
	do 
	{
		cin >> c;
		if (isalpha(c))
		{
			c = tolower(c);
			letter[c]++;
		}
	} while (c != '.');
	for (map<char, int>::iterator iter = letter.begin(); iter != letter.end(); ++iter)
	{
		cout << iter->first << " ���� " << iter->second << " ��" << endl;
	}
	system("pause");
	return 0;
}