#include <iostream>
using namespace std;
class YueBao 
{
public:
	YueBao():balance(0),days(0), interest_rate(0.00255){};
	YueBao(double money): balance(money), days(0), interest_rate(0.00255) {};
	void SaveMoney(double money);  //��Ǯ
	void DrawMoney(double money);  //ȡǮ
	void ShowMoney();				//�û��鿴�Լ���ǰ�����
	void AddDate(); //��������
private:
	double balance;		//�û����
	double interest_rate;//��ǰ������
	int days;			//�û���Ǯ������
	//double GetMoney();	//���ڲ��õ�Ǯ����Ŀ
	void SetInterest_rate(double interest); // ���ڲ���������
	void Interest(int days); //������Ϣ�����ӵ��û������ȥ
};
void YueBao::AddDate()
{
	cout << "������ִ�е�����" << endl;
	int in_days = 0;
	cin >> in_days;
	days += in_days;
	Interest(in_days);
}
void YueBao::SetInterest_rate(double interest)
{
	interest_rate = interest;
}
/*double YueBao::GetMoney()
{
	return balance;
}*/
void YueBao::ShowMoney()
{
	cout << "�û���ǰ�˻����Ϊ:" << balance << endl;
}
void YueBao::Interest(int days)
{
	while (days)
	{
		balance += balance * interest_rate;
		--days;
	}
}
void YueBao::SaveMoney(double money)
{
	balance += money;
}
void YueBao::DrawMoney(double money)
{
	if (money <= balance)
	{
		balance -= money;
		cout << "����ȡ��" << money << "Ԫ" << "��ǰʣ��" << balance << "Ԫ" << endl;
	}
	else
	{
		cout << "�������㣡" << endl;
	}
}
class Operate
{
public:
	Operate(YueBao newuser){};
	void Operater(); //���û��ṩ�Ĳ���
private:
	int Menu(); //���û���ʾ�Ĳ˵�
	YueBao user;
};
void Operate::Operater()
{
	int choice = 0;
	while (choice = Menu())
	{
		user.AddDate();
		if (choice == 1)
		{
			user.ShowMoney();
		}
		if (choice == 2)
		{
			cout << "��������Ҫ�����Ǯ��" << endl;
			double money = 0;
			cin >> money;
			user.SaveMoney(money);
			cout << "���Ѵ���" << money << "Ԫ" << endl;
		}
		if (choice == 3)
		{
			cout << "��������Ҫȡ����Ǯ��" << endl;
			double money = 0;
			cin >> money;
			user.DrawMoney(money);
		}
	}
	cout << "ллʹ��,�ټ�!" << endl;
}
int Operate::Menu()
{
	cout << "********��ӭʹ����*********" << endl;
	cout << "********1.��ѯ���    *********" << endl;
	cout << "********2.���        *********" << endl;
	cout << "********3.ȡ��        *********" << endl;
	cout << "********4.�˳�        *********" << endl;
	int input = 0;
	cin >> input;
	if (input != 4 && input <= 4 && input >= 1)
	{
		return input;
	}
	return 0;
}
int main()
{
	/*��ʵ��һ���������࣬�����Ѹ�������ģ�壬�����main�����жԸ���Ĳ�����������ʵ�ֲ�����ɴ��롣
	����������Լ�¼�˻�����Ǯ��ȡǮ��������Ϣ����������һ��˽�о�̬��Ա����profitRate
	�洢�����������ʣ������ù��о�̬��Ա����setProfitRate�޸����ʵ�ֵ����������Ϊ��1����
	��n������n����˻�������ÿ��ֻ�ܽ���һ���˻�����������ȡ��ÿһ���������Ϣ��ǰһ����˻�
	����롰�������ʵĳ˻�����������Ϣ����Ҳ�������˻������ڵ�1��֮ǰ�˻������ڣ����Ե�1��
	һ�����½��˻�����Ǯ���ҵ��첻������Ϣ�����������ڽ���n������������Ҫ��������n��
	������ɺ���˻��������*/
	YueBao user1(1000);
	Operate operater1(user1);
	operater1.Operater();
	system("pause");
	return 0;
}