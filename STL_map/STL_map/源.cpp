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
		cout << iter->first << " ѧ��:" << iter->second << endl;
		++iter;
	}
	int n = 2;//ѡ�δ���
	int score = 0;//��ѧ����
	cout << "����ѡ2�ſ�" << endl;
	
	while (n > 0)
	{
		cout << "��ѡ��γ�" << endl;
		string name;
		cin >> name;
		iter = lesson.find(name);
		if (iter == lesson.end())
		{
			cout << "û�ҵ�Ҫѡ��Ŀγ�" << endl;
		}
		else
		{
			--n;
			score += iter->second;
			lesson.erase(iter);
			cout << "ѡ�γɹ�" << endl;
		}
	}
	cout << "����ѡ��Ŀγ̵���ѧ��Ϊ:" << score << endl;
	system("pause");
	return 0;
}