#include <iostream>
using namespace std;
class account
{
public:
	account(int x = 0) :xptr(new int(x)) { cout << "���캯��" << endl; };//���캯��
	account(const account &acc) :xptr(new int(*acc.xptr)){ cout << "���ƹ��캯��" << endl; };//���ƹ��캯��
	~account() //��������
	{
		delete xptr;
		cout << "��������" << endl;
	};
	int GetNum() { return *xptr; };
private:
	int *xptr;
};
class IntNum
{
public:
	IntNum(int x = 0) : xptr(new int(x)){ cout << "���캯��" << endl; };//���캯��
	IntNum(const IntNum &acc) :xptr(new int(*acc.xptr)) { cout << "���ƹ��캯��" << endl; };//���ƹ��캯��
	IntNum(IntNum &&acc) : xptr(acc.xptr) //�ƶ����캯��
	{ 
		acc.xptr = nullptr;
		cout << "�ƶ����캯��" << endl; 
	};
	~IntNum() //��������
	{
		delete xptr;
		cout << "��������" << endl;
	};
	int GetNum() { return *xptr; };
private:
	int *xptr;
};
account GetAcc()
{
	account a; 
	return a;
};
IntNum GetInt()
{
	IntNum a;
	return a;
}
int main()
{
	//����ʵ���кܶ����������ӣ����ǽ�Ǯ��һ���˺�ת�Ƶ���һ���˺ţ�
	//���ֻ�SIM��ת�Ƶ���һ̨�ֻ������ļ���һ��λ�ü��е���һ��λ�á���
	//�ƶ�������Լ��ٲ���Ҫ�ĸ��ƣ����������ϵ�����
	cout << GetAcc().GetNum() << endl;
	cout << "******************************" << endl;
	cout << GetInt().GetNum() << endl;
	system("pause");
	return 0;
}