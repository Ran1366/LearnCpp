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
//�޲εĹ��캯��
Myclock::Myclock() : Myclock(0,0,0)//ί�й��캯���������������캯��ʵ�ֹ��칦�ܣ����ұ��ֳ����һ����
{
}
//��������
Myclock::~Myclock()
{
}
//�вεĹ��캯��
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