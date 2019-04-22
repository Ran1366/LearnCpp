#include <iostream>
using namespace std;
class Base
{
public:
	//将被派生类重写的函数定义为虚函数实现动态绑定
	virtual void Say() { cout << "这是第一基类" << endl; };
};
class Base1 : public Base
{
public:
	void Say() { cout << "这是第二基类" << endl; };
};
class Base2 : public Base1
{
public:
	void Say() { cout << "这是第三基类" << endl; };
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