#include <iostream>
using namespace std;
class Base
{
public:
	//������������д�ĺ�������Ϊ�麯��ʵ�ֶ�̬��
	virtual void Say() { cout << "���ǵ�һ����" << endl; };
};
class Base1 : public Base
{
public:
	void Say() { cout << "���ǵڶ�����" << endl; };
};
class Base2 : public Base1
{
public:
	void Say() { cout << "���ǵ�������" << endl; };
};
void AllSay(Base &b)
{
	b.Say();
}
int main()
{
	Base a;
	Base1 b;
	Base2 c;
	AllSay(a);
	AllSay(b);
	AllSay(c);
	system("pause");
	return 0;
}