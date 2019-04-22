#include <iostream>
using namespace std;
class Myclock 
{
public : 
	Myclock();
	~Myclock();
	Myclock(int newh, int newm, int news);
	void setTime(int newh, int newm, int news);
	void showTime();
private :
	int hour, minute, second;
};
//无参的构造函数
Myclock::Myclock() : Myclock(0,0,0)//委托构造函数：调用其他构造函数实现构造功能，并且保持程序的一致性
{
}
//析构函数
Myclock::~Myclock()
{
}
//有参的构造函数
Myclock::Myclock(int newh,int newm , int news):
			hour(newh),minute(newm),second(news)
{
	
}
void Myclock::setTime(int newh, int newm, int news)
{
	hour = newh;
	minute = newm;
	second = news;
}
void Myclock::showTime()
{
	cout << hour << ":" << minute << ":" << second << endl;
}
int main()
{
	Myclock c1(0,0,0);
	Myclock c2;
	c2.showTime();
	c1.showTime();
	c1.setTime(12, 0, 0);
	c1.showTime();
	system("pause");
	return 0;
}