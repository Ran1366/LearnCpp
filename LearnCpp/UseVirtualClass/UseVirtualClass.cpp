#include <iostream>
#include <string>
using namespace std;
class People
{
public:
	void behave()
	{
		cout << "人活于世,知足常乐" << endl;
	};
	string name;
	string gender;
};
class Student : public  virtual People
{
public:
	void behave()
	{
		cout << "学海无涯苦作舟" << endl;
	}
	string classNM;//班级号
};
class Teacher : public virtual People
{
public:
	void behave()
	{
		cout << "春蚕到死丝方尽,蜡炬成灰泪始干" << endl;
	}
	string position;//职务
	string department;//部门
};
class Graduate : public  Student
{
public:
	void behave()
	{
		cout << "十年寒窗无人问,金榜题名天下知" << endl;
	}
	string subject;//专业
	Teacher adviser;//导师
};
class TA : public Graduate,public Teacher
{
public:
	void behave()
	{
		cout << "百尺竿头更进一步" << endl;
	}
};
int main()
{
	TA ta;
	Teacher t;
	t.name = "龙傲天";
	ta.adviser = t;
	ta.name = "叶良辰";
	cout << ta.adviser.name << endl;
	cout << ta.name << endl;
	system("pause");
	return 0;
}