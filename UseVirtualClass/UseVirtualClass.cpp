#include <iostream>
#include <string>
using namespace std;
class People
{
public:
	void behave()
	{
		cout << "�˻�����,֪�㳣��" << endl;
	};
	string name;
	string gender;
};
class Student : public  virtual People
{
public:
	void behave()
	{
		cout << "ѧ�����Ŀ�����" << endl;
	}
	string classNM;//�༶��
};
class Teacher : public virtual People
{
public:
	void behave()
	{
		cout << "���ϵ���˿����,����ɻ���ʼ��" << endl;
	}
	string position;//ְ��
	string department;//����
};
class Graduate : public  Student
{
public:
	void behave()
	{
		cout << "ʮ�꺮��������,�����������֪" << endl;
	}
	string subject;//רҵ
	Teacher adviser;//��ʦ
};
class TA : public Graduate,public Teacher
{
public:
	void behave()
	{
		cout << "�ٳ߸�ͷ����һ��" << endl;
	}
};
int main()
{
	TA ta;
	Teacher t;
	t.name = "������";
	ta.adviser = t;
	ta.name = "Ҷ����";
	cout << ta.adviser.name << endl;
	cout << ta.name << endl;
	system("pause");
	return 0;
}