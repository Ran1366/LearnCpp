#include <iostream>
using namespace std;

struct Base1
{
	int x;
	Base1(int x): x(x) {};
};

struct Base2
{
	int x;
	Base2(int x) :x(x){};
};

struct Derived :public Base1, public Base2
{
	int x;
	Derived(Base1& a, Base2& b):Base1(a.x),Base2(b.x)
	{
		x = a.x + b.x;
	};
};

//请实现Base1，Base2, Derived的构造函数

int main()
{
	/*代码声明了两个基类Base1和Base2，然后从这两个基类按照公有方式派生
	出类Derived。基类和派生类都各自包含一个公有成员x，并且Base1和Base2各
	有接受一个整型参数的构造函数，Derived的构造函数接受Base1和Base2的对象
	引用a，b来初始化Derived类对象，并令x为Base1::x和Base2::x之和*/
	int x, y;
	cin >> x >> y;
	Base1 a(x);
	Base2 b(y);
	Derived d(a, b);
	cout << d.Base1::x << "+" << d.Base2::x << "=" << d.x << endl;
	system("pause");
	return 0;
}