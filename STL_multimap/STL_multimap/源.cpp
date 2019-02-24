#include <iostream>
#include <map>
#include <string>
using namespace std;
int main()
{
	cout << "查询课表" << endl;
	typedef multimap<string, string> course;
	course lesson;
	lesson.insert(make_pair("C++", "2-6"));
	lesson.insert(make_pair("COMPILER", "3-1"));
	lesson.insert(make_pair("COMPILER", "5-2"));
	lesson.insert(make_pair("OS", "1-2"));
	lesson.insert(make_pair("OS", "4-1"));
	lesson.insert(make_pair("OS", "5-5"));
	string name;
	int count = 0;//课程次数
	course::iterator iter = lesson.begin();
	do
	{
		cin >> name;
		count = lesson.count(name);
		if (count == 0)
		{
			cout << "没找到该课程,请重新输入" << endl;
		}
	} while (count == 0);
	cout << "共有" << count << "节课," << "上课时间:" << endl;
	pair<course::iterator,course::iterator> range = lesson.equal_range(name);
	for (course::iterator iter = range.first; iter != range.second; ++iter)
	{
		cout << iter->second << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}