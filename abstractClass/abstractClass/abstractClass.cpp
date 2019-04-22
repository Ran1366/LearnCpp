#include <iostream>
using namespace std;
class Base
{
	//含有纯虚函数的类为抽象
	//其派生类想生成对象需要重写该纯虚函数
public:
	virtual void Say()const = 0;
};
class Base1 : public Base
{
public:
	void Say()const { cout << "Base1 的 Say()函数" << endl; };
};
class Base2 : public Base1
{
public:
	void Say()const { cout << "Base2 的 Say()函数" << endl; };
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