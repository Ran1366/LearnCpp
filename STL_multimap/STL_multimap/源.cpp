#include <iostream>
#include <map>
#include <string>
using namespace std;
int main()
{
	cout << "��ѯ�α�" << endl;
	typedef multimap<string, string> course;
	course lesson;
	lesson.insert(make_pair("C++", "2-6"));
	lesson.insert(make_pair("COMPILER", "3-1"));
	lesson.insert(make_pair("COMPILER", "5-2"));
	lesson.insert(make_pair("OS", "1-2"));
	lesson.insert(make_pair("OS", "4-1"));
	lesson.insert(make_pair("OS", "5-5"));
	string name;
	int count = 0;//�γ̴���
	course::iterator iter = lesson.begin();
	do
	{
		cin >> name;
		count = lesson.count(name);
		if (count == 0)
		{
			cout << "û�ҵ��ÿγ�,����������" << endl;
		}
	} while (count == 0);
	cout << "����" << count << "�ڿ�," << "�Ͽ�ʱ��:" << endl;
	pair<course::iterator,course::iterator> range = lesson.equal_range(name);
	for (course::iterator iter = range.first; iter != range.second; ++iter)
	{
		cout << iter->second << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}