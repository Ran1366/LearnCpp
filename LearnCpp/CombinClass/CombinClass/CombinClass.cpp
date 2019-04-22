#include <iostream>
#include <cmath>
using namespace std;

class Point
{
public:
	Point();//无参的构造函数
	Point(int x , int y);//带参构造函数
	Point(const Point &p);//复制构造函数
	~Point();//析构函数
	int getX()
	{
		return x;
	}
	int getY()
	{
		return y;
	}
private:
	int x; //横坐标x
	int y;//纵坐标y
};

Point::Point():Point(0,0)
{
}

Point::~Point()
{
}
Point::Point(int nx, int ny) :x(nx), y(ny)
{
}
Point::Point(const Point &p):x(p.x),y(p.y)
{
}

class Line
{
public:
	Line();
	Line(Point p1 ,Point p2);//带参的构造函数
	Line(const Line &L);//复制构造函数
	~Line();
	void showLine()
	{
		double len = abs(p2.getX() - p1.getX());
		double hight = abs(p2.getY() - p1.getY());
		double lenth = sqrt((len * len + hight * hight));
		cout << "线条的长度为：" << lenth <<endl;
	}

private:
	Point p1;
	Point p2;
};

Line::Line()
{
}

Line::~Line()
{
}
Line::Line(Point np1 , Point np2):p1(np1),p2(np2)
{
}
Line::Line(const Line &L):p1(L.p1),p2(L.p2)
{
}
int main()
{
	//定义一个组合类，该类是一个直线类，其中包含一个点类
	Point p1(2,3);
	Point p2(5,7);
	Line l2(p1,p2);
	l2.showLine();
	Line l3(l2);
	l3.showLine();
	system("pause");
	return 0;
}