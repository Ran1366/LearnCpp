#include <iostream>
#include <map>
using namespace std;
int main()
{
	map<char, int> letter;
	cout << "请输入字母,判断每个字母各出现几次" << endl;
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
		cout << iter->first << " 出现 " << iter->second << " 次" << endl;
	}
	system("pause");
	return 0;
}