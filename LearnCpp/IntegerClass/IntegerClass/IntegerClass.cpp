#include <iostream>
using namespace std;
class Integer 
{
public:
	Integer();
	Integer(int a);
	Integer(const Integer &n);
	~Integer();
	int Comdiv(Integer a);  //��Integer���������num�����Լ��
	int GetMin(Integer a);	//��Integer���������num�н�С���Ǹ���
private:
	int num;
};
Integer::Integer()
{
}
Integer::Integer(int a):num(a)
{
}
Integer::~Integer()
{
}
Integer::Integer(const Integer &a):num(a.num)
{
}
int Integer::GetMin(Integer a)
{
	return (this->num > a.num) ? a.num : this->num;
}
int Integer::Comdiv(Integer a)
{
	if (this->num > 0 && a.num > 0)
	{
		int max = 1;
		int counts = a.GetMin(this->num);  //���������н�С���Ǹ�����Ϊѭ������
		for (int i = 1 ; i <= counts ; ++i)
		{
			if (this->num % i == 0 && a.num % i == 0)
			{
				max = i;
			}
		}
		return max;
	}
	return 0;
}
int main()
{
	//������������a �� b�����Լ����Ҫ��ʹ��c++ class��д����
	cout << "����������������" << endl;
	int a = 0;
	int b = 0;
	cin >> a >> b;
	Integer num1(a);
	Integer num2(b);
	cout << "���Լ���ǣ�" << num1.Comdiv(num2) << endl;
	system("pause");
	return 0;
}