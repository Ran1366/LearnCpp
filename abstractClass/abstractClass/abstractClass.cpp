#include <iostream>
using namespace std;
class Base
{
	//���д��麯������Ϊ����
	//�������������ɶ�����Ҫ��д�ô��麯��
public:
	virtual void Say()const = 0;
};
class Base1 : public Base
{
public:
	void Say()const { cout << "Base1 �� Say()����" << endl; };
};
class Base2 : public Base1
{
public:
	void Say()const { cout << "Base2 �� Say()����" << endl; };
};
void AllSay(Base *ba)
{
	ba->Say();
}
int main()
{
	Base1 b;
	Base2 c;
	AllSay(&b);
	AllSay(&c);
	system("pause");
	return 0;
}