#include <iostream>
using namespace std;

class Base1
{
public:
	Base1(int x);
	~Base1();
};

class Base2
{
public:
	Base2(int x) { cout << "Base2 constructor called " << x << endl; };
	~Base2() { cout << "Base2 destructor called" << endl; };
};
class Base3
{
public:
	Base3(int x) { cout << "Base3 constructor called " << x << endl; };
	~Base3() { cout << "Base3 destructor called" << endl; };
};

class Derived : public virtual Base2 , public virtual Base1 , public virtual Base3//�̳�����3����
{
public:
	Derived(int x1, int x2, int x3, int x4):Base1(x2),Base2(x3),Base3(x4){ cout << "Derived constructor called " << x1 << endl; };
	~Derived() { cout << "Derived destructor called" << endl; };
};

Base1::Base1(int x)
{
	cout << "Base1 constructor called " << x << endl;
}

Base1::~Base1()
{
	cout << "Base1 destructor called" << endl;
}
//����Base1���еĴ���ʵ��������Ĺ��캯������������ 


int main()
{
	/*
	������:
	Base2 constructor called 3
	Base1 constructor called 2
	Base3 constructor called 4
	Derived constructor called 1
	Derived destructor called
	Base3 destructor called
	Base1 destructor called
	Base2 destructor called*/
	Derived d(1, 2, 3, 4);
	return 0;
}