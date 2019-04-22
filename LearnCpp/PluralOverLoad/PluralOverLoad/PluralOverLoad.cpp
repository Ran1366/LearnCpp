#include <iostream>
#include <string>
using namespace std;
class Plural
{
public:
	Plural():real(0),imag(0) {};
	Plural(int real , int imag):real(real),imag(imag) {};
	//�����������
	friend Plural operator + (const Plural &left, const Plural &right);
	//�����������
	friend Plural operator - (const Plural &left, const Plural &right);
	//������ʵ�����
	friend Plural operator + (const Plural &left, int num);
	//������ʵ�����
	friend Plural operator - (const Plural &left, int num);
	//�����������
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
	cout << "����plu1 + ����plu2 Ϊ:" <<plu1 + plu2 << endl;
	cout << "����plu1 - ����plu2 Ϊ:" << plu1 - plu2 << endl;
	cout << "plu1 + 5 = " << plu1 + 5 << endl;
	cout << "plu2 - 3 = " << plu2 - 3 << endl;
	system("pause");
	return 0;
}