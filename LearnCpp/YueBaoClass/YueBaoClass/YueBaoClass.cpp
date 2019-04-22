#include <iostream>
using namespace std;
class YueBao 
{
public:
	YueBao():balance(0),days(0), interest_rate(0.00255){};
	YueBao(double money): balance(money), days(0), interest_rate(0.00255) {};
	void SaveMoney(double money);  //存钱
	void DrawMoney(double money);  //取钱
	void ShowMoney();				//用户查看自己当前的余额
	void AddDate(); //增加天数
private:
	double balance;		//用户余额
	double interest_rate;//当前的利率
	int days;			//用户存钱的天数
	//double GetMoney();	//类内部得到钱的数目
	void SetInterest_rate(double interest); // 类内部设置利率
	void Interest(int days); //计算利息并增加到用户余额中去
};
void YueBao::AddDate()
{
	cout << "请输入执行的天数" << endl;
	int in_days = 0;
	cin >> in_days;
	days += in_days;
	Interest(in_days);
}
void YueBao::SetInterest_rate(double interest)
{
	interest_rate = interest;
}
/*double YueBao::GetMoney()
{
	return balance;
}*/
void YueBao::ShowMoney()
{
	cout << "用户当前账户余额为:" << balance << endl;
}
void YueBao::Interest(int days)
{
	while (days)
	{
		balance += balance * interest_rate;
		--days;
	}
}
void YueBao::SaveMoney(double money)
{
	balance += money;
}
void YueBao::DrawMoney(double money)
{
	if (money <= balance)
	{
		balance -= money;
		cout << "您已取出" << money << "元" << "当前剩余" << balance << "元" << endl;
	}
	else
	{
		cout << "您的余额不足！" << endl;
	}
}
class Operate
{
public:
	Operate(YueBao newuser){};
	void Operater(); //给用户提供的操作
private:
	int Menu(); //给用户显示的菜单
	YueBao user;
};
void Operate::Operater()
{
	int choice = 0;
	while (choice = Menu())
	{
		user.AddDate();
		if (choice == 1)
		{
			user.ShowMoney();
		}
		if (choice == 2)
		{
			cout << "请输入您要存入的钱数" << endl;
			double money = 0;
			cin >> money;
			user.SaveMoney(money);
			cout << "您已存入" << money << "元" << endl;
		}
		if (choice == 3)
		{
			cout << "请输入您要取出的钱数" << endl;
			double money = 0;
			cin >> money;
			user.DrawMoney(money);
		}
	}
	cout << "谢谢使用,再见!" << endl;
}
int Operate::Menu()
{
	cout << "********欢迎使用鱼额宝*********" << endl;
	cout << "********1.查询余额    *********" << endl;
	cout << "********2.存款        *********" << endl;
	cout << "********3.取款        *********" << endl;
	cout << "********4.退出        *********" << endl;
	int input = 0;
	cin >> input;
	if (input != 4 && input <= 4 && input >= 1)
	{
		return input;
	}
	return 0;
}
int main()
{
	/*请实现一个“鱼额宝”类，下面已给出代码模板，请根据main函数中对该类的操作，补充类实现部分完成代码。
	“鱼额宝”类可以记录账户余额、存钱、取钱、计算利息。该类中有一个私有静态成员变量profitRate
	存储“鱼额宝”的利率，可以用共有静态成员函数setProfitRate修改利率的值。程序输入为第1天至
	第n天连续n天的账户操作，每天只能进行一次账户操作，或存或取，每一天产生的利息是前一天的账户
	余额与“鱼额宝”利率的乘积，产生的利息当天也将存入账户余额，由于第1天之前账户不存在，所以第1天
	一定是新建账户并存钱，且当天不会有利息存入余额。程序在接受n天操作的输入后，要求计算出第n天
	操作完成后的账户余额并输出。*/
	YueBao user1(1000);
	Operate operater1(user1);
	operater1.Operater();
	system("pause");
	return 0;
}