#include <iostream>
using namespace std;
class account
{
public:
	account(int x = 0) :xptr(new int(x)) { cout << "构造函数" << endl; };//构造函数
	account(const account &acc) :xptr(new int(*acc.xptr)){ cout << "复制构造函数" << endl; };//复制构造函数
	~account() //析构函数
	{
		delete xptr;
		cout << "析构函数" << endl;
	};
	int GetNum() { return *xptr; };
private:
	int *xptr;
};
class IntNum
{
public:
	IntNum(int x = 0) : xptr(new int(x)){ cout << "构造函数" << endl; };//构造函数
	IntNum(const IntNum &acc) :xptr(new int(*acc.xptr)) { cout << "复制构造函数" << endl; };//复制构造函数
	IntNum(IntNum &&acc) : xptr(acc.xptr) //移动构造函数
	{ 
		acc.xptr = nullptr;
		cout << "移动构造函数" << endl; 
	};
	~IntNum() //析构函数
	{
		delete xptr;
		cout << "析构函数" << endl;
	};
	int GetNum() { return *xptr; };
private:
	int *xptr;
};
account GetAcc()
{
	account a; 
	return a;
};
IntNum GetInt()
{
	IntNum a;
	return a;
}
int main()
{
	//在现实中有很多这样的例子，我们将钱从一个账号转移到另一个账号，
	//将手机SIM卡转移到另一台手机，将文件从一个位置剪切到另一个位置……
	//移动构造可以减少不必要的复制，带来性能上的提升
	cout << GetAcc().GetNum() << endl;
	cout << "******************************" << endl;
	cout << GetInt().GetNum() << endl;
	system("pause");
	return 0;
}