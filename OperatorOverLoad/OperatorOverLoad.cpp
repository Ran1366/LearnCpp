#include <iostream>
using namespace std;
class Clock
{
public:
	Clock():second(0),minute(0),hour(0) {};
	Clock(int hour , int minute , int second);
	void ShowTime();
	Clock & operator ++ (); // 重载前置++运算符
	Clock operator ++ (int); //重载后置++运算符
	int GetHour() { return hour; };
	int GetMinute() { return minute; };
private:
	int second;
	int minute;
	int hour;
};
Clock::Clock(int hour, int minute, int second)
{
	if (second >=0 && second <= 59 && 
		minute >= 0 && minute <= 59 &&
		hour >= 0 && hour <= 23)
	{
		this->hour = hour;
		this->minute = minute;
		this->second = second;
	}
}
Clock& Clock::operator ++ ()
{
	++second;
	if (second > 59)
	{
		second = 0;
		++minute;
		if (minute > 59)
		{
			minute = 0;
			++hour;
			hour %= 24;
		}
	}
	return *this;
}
Clock Clock::operator++(int)
{
	Clock old = *this;
	++(*this);
	return old;
}
void Clock::ShowTime()
{
	cout << hour << ":" << minute << ":" << second << endl;
}
int main()
{
	Clock c1(21, 46, 0);
	int lastMin = c1.GetMinute();
	while (c1.GetHour() < 22)
	{
		++c1;
		if (c1.GetMinute() > lastMin)
		{
			c1.ShowTime();
			lastMin = c1.GetMinute();
		}
	}
	system("pause");
	return 0;
}