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

//��ʵ��Base1��Base2, Derived�Ĺ��캯��

int main()
{
	/*������������������Base1��Base2��Ȼ������������ఴ�չ��з�ʽ����
	����Derived������������඼���԰���һ�����г�Աx������Base1��Base2��
	�н���һ�����Ͳ����Ĺ��캯����Derived�Ĺ��캯������Base1��Base2�Ķ���
	����a��b����ʼ��Derived����󣬲���xΪBase1::x��Base2::x֮��*/
	int x, y;
	cin >> x >> y;
	Base1 a(x);
	Base2 b(y);
	Derived d(a, b);
	cout << d.Base1::x << "+" << d.Base2::x << "=" << d.x << endl;
	system("pause");
	return 0;
}