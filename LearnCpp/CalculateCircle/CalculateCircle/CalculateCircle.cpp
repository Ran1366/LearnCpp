#include <iostream>
using namespace std;

const double pi = 3.14;

class Shape {
public:
	Shape() {}
	~Shape() {}
	virtual double getArea() = 0;
	virtual double getPerim() = 0;
};

class Circle : public Shape {
public:
	Circle(double rad) :radius(rad) {}
	~Circle() {}

	/*��������������*/
	double getArea()override;
	double getPerim()override;
private:
	double radius;
};

double Circle::getArea()
{
	return pi * radius * radius;
}

double Circle::getPerim()
{
	return 2 * pi * radius;
}
int main() {
	double radius;
	cin >> radius;
	Circle c(radius);
	cout << c.getArea() << " " << c.getPerim() << endl;
	system("pause");
	return 0;
}