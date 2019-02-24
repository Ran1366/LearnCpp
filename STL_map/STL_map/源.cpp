#include <iostream>
#include <map>
#include <string>
using namespace std;
int main()
{
	map<string, int> lesson;
	lesson.insert(make_pair("chinese", 5));
	lesson.insert(make_pair("math", 5));
	lesson.insert(make_pair("english", 4));
	lesson.insert(make_pair("physical", 5));
	map<string, int>::iterator iter = lesson.begin();
	while (iter != lesson.end())
	{
		cout << iter->first << " 学分:" << iter->second << endl;
		++iter;
	}
	int n = 2;//选课次数
	int score = 0;//总学分数
	cout << "您可选2门课" << endl;
	
	while (n > 0)
	{
		cout << "请选择课程" << endl;
		string name;
		cin >> name;
		iter = lesson.find(name);
		if (iter == lesson.end())
		{
			cout << "没找到要选择的课程" << endl;
		}
		else
		{
			--n;
			score += iter->second;
			lesson.erase(iter);
			cout << "选课成功" << endl;
		}
	}
	cout << "您所选择的课程的总学分为:" << score << endl;
	system("pause");
	return 0;
}