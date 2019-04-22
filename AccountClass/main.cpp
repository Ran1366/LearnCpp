#include <iostream>
#include <string>
using namespace std;

class Account
{
	string userName;
public:
	Account() {};
	Account(string name) :userName(name){};
	void  PrintUserName()
	{
		cout << "����:" << userName << endl;
	};
};

class CreditAccount : public Account
{
public:
	CreditAccount(string name, int credit) :Account(name),credit(credit){};
	void PrintInfo()
	{
		Account::PrintUserName();
		cout << "���ö��:" << credit << endl;
	};
private:
	int credit;
};

//��ʵ��Account���캯��Account(char *name)
//��ʵ��Account��PrintUserName()����
//��ʵ��CreditAccount��Ĺ��캯��CreditAccount(char* name, long number)
//��ʵ��CreditAccount���PrintInfo()����
int main()
{
	/*����һ������Account�����ݳ�Ա����string�����userName���ڱ����˻�����������
	������Ա����Ĭ�Ϲ��캯�������ι��캯�����ڳ�ʼ�����ݳ�Ա����������ĳ�Ա��PrintName()��
	��Account��������CreditAccount�࣬�����������ݳ�Աcredit���ڼ�¼���û����ö�ȣ�
	������Ա�������ι��캯�����ڳ�ʼ�����ݳ�Ա������˻���Ϣ�ĳ�Ա����PrintInfo().
	Ҫ���ں���PrintInfo()����Ҫ���û���ĳ�Ա����PrintName()*/
	string a;
	int credit = 0;
	cout << "����������" << endl;
	getline(cin, a);
	cout << "�������û����ö��" << endl;
	cin >> credit;
	CreditAccount user1(a,credit);
	user1.PrintInfo();
	system("pause");
	return 0;
}