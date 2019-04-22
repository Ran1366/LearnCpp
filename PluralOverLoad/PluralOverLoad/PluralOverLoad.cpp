#include <iostream>
#include <string>
using namespace std;
class Plural
{
public:
	Plural():real(0),imag(0) {};
	Plural(int real , int imag):real(real),imag(imag) {};
	//两个复数相加
	friend Plural operator + (const Plural &left, const Plural &right);
	//两个复数相减
	friend Plural operator - (const Plural &left, const Plural &right);
	//复数与实数相加
	friend Plural operator + (const Plural &left, int num);
	//复数与实数相减
	friend Plural operator - (const Plural &left, int num);
	//输出复数对象
	friend ostream& operator << (ostream &out , Plural &plu);
private:
	int real;
	int imag;
};
Plural operator + (const Plural &left, const Plural &right)
{
	return Plural(left.real + right.real,left.imag + right.imag);
}
Plural operator - (const Plural &left, const Plural &right)
{
	return Plural(left.real - right.real, left.imag - right.imag);
}
Plural operator + (const Plural &left, int num)
{
	return Plural(left.real + num,left.imag);
}
Plural operator - (const Plural &left, int num)
{
	return Plural(left.real - num, left.imag);
}
ostream & operator << (ostream &out, Plural &plu)
{
	out << plu.real << "+" << plu.imag << "j" << endl;
	return out;
}
int main()
{
	Plural plu1(5,6);
	Plural plu2(4,8);
	cout << plu1 << endl << plu2 << endl;
	cout << "复数plu1 + 复数plu2 为:" <<plu1 + plu2 << endl;
	cout << "复数plu1 - 复数plu2 为:" << plu1 - plu2 << endl;
	cout << "plu1 + 5 = " << plu1 + 5 << endl;
	cout << "plu2 - 3 = " << plu2 - 3 << endl;
	system("pause");
	return 0;
}