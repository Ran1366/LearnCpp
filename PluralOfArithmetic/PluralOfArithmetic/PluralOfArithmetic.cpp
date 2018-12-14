#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

class Complex {
public:
	Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {};
	Complex operator+ (const Complex &c2) const;
	Complex operator- (const Complex &c2) const;

	/*ʵ��������������*/
	Complex operator* (const Complex &c2) const;
	Complex operator/ (const Complex &c2) const;
	friend ostream & operator<< (ostream &out, const Complex &c);

private:
	double real;
	double imag;
};
//��z1=a+bi��z2=c+di(a��b��c��d��R)����������������
//��ô���ǵĻ�(a+bi)(c+di)=(ac-bd)+(bc+ad)i��
Complex Complex::operator*(const Complex &c2)const
{
	Complex result;
	result.real = this->real * c2.real - this->imag * c2.imag;
	result.imag = this->imag * c2.real + this->real * c2.imag;
	return result;
}
//(a+bi)/(c+di)=(ac+bd)/(c+d) +((bc-ad)/(c+d))i
Complex Complex::operator/ (const Complex &c2) const
{
	Complex result;
	result.real = (this->real * c2.real + this->imag * c2.imag) / (c2.real + c2.imag);
	result.imag = (this->imag * c2.real - this->real * c2.imag) / (c2.real + c2.imag);
	return result;
}

Complex Complex::operator+ (const Complex &c2) const {
	return Complex(real + c2.real, imag + c2.imag);
}

Complex Complex::operator- (const Complex &c2) const {
	return Complex(real - c2.real, imag - c2.imag);
}

ostream & operator<< (ostream &out, const Complex &c)
{
	out << c.real << " + " << "(" << c.imag << ")j" << endl;
	return out;
}
int main() {
	cout << "�������һ������" << endl;
	double real, imag;
	cin >> real >> imag;
	Complex c1(real, imag);
	cout << "������ڶ�������" << endl;
	cin >> real >> imag;
	Complex c2(real, imag);
	cout << c1 + c2;
	cout << c1 - c2;
	cout << c1 * c2;
	cout << c1 / c2;
	system("pause");
	return 0;
}