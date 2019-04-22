#include <iostream>
using namespace std;

class Myclock
{
public:
	void setTime(int hour = 0,int minute = 0,int second = 0);
	void showTime();

private: 
	int hour, minute, second;
};
void Myclock::setTime(int hour, int minute , int second)
{
	this->hour = hour;
	this->minute = minute;
	this->second = second;
}
void Myclock::showTime()
{
	cout << hour <<':'<< minute <<':'<< second << endl;
}

int main()
{
	Myclock c1;
	c1.setTime(10);
	c1.showTime();
	system("pause");
	return 0;
}