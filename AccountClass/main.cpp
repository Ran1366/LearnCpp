#include <iostream>
#include <string>
using namespace std;

class Account
{
	string userName;
public:
	Account() {};
	Account(string name) :userName(name){};
	void  PrintUserName()
	{
		cout << "姓名:" << userName << endl;
	};
};

class CreditAccount : public Account
{
public:
	CreditAccount(string name, int credit) :Account(name),credit(credit){};
	void PrintInfo()
	{
		Account::PrintUserName();
		cout << "信用额度:" << credit << endl;
	};
private:
	int credit;
};

//请实现Account构造函数Account(char *name)
//请实现Account的PrintUserName()函数
//请实现CreditAccount类的构造函数CreditAccount(char* name, long number)
//请实现CreditAccount类的PrintInfo()函数
int main()
{
	/*定义一个基类Account，数据成员包含string类变量userName用于保存账户主人姓名，
	函数成员包括默认构造函数、带参构造函数用于初始化数据成员和输出姓名的成员函PrintName()。
	从Account类派生出CreditAccount类，增加整型数据成员credit用于记录该用户信用额度，
	函数成员包括带参构造函数用于初始化数据成员和输出账户信息的成员函数PrintInfo().
	要求：在函数PrintInfo()中需要调用基类的成员函数PrintName()*/
	string a;
	int credit = 0;
	cout << "请输入姓名" << endl;
	getline(cin, a);
	cout << "请输入用户信用额度" << endl;
	cin >> credit;
	CreditAccount user1(a,credit);
	user1.PrintInfo();
	system("pause");
	return 0;
}