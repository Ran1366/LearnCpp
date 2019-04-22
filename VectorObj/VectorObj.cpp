#include <iostream>
#include <vector>
using namespace std;
class Point 
{
public:
	Point() : x(0), y(0) { cout << "default constructor" << endl; };
	Point(int i_x, int i_y) : x(i_x), y(i_y) { cout << "custom constructor" << endl; };
	void SetPoint(int i_x, int i_y) { x = i_x; y = i_y; };
	int GetX() { return x; };
	int GetY() { return y; };
private:
	int x;
	int y;
};
int main()
{
	vector<Point>ArrPoints(5); //�Զ�����һ��Point���͵�������,ArrPoints�������
	//�����i����Ϊunsigned����,����Ϊ.size()������Ϊunsigend int����
	//�������ᾯ��:�з���/�޷��Ų�ƥ��
	for (unsigned int i = 0; i < ArrPoints.size() ; ++i)//
	{
		ArrPoints[i].SetPoint(i + 5, i + 6);
	}
	for (auto i = ArrPoints.begin() ; i != ArrPoints.end() ; ++i)
	{
		cout << i->GetX() <<","<< i->GetY() << endl;
	}
	for (auto e : ArrPoints)
	{
		cout << e.GetX() << "," << e.GetY() << endl;
	}
	//vector��װ�κ����͵Ķ�̬���飬�Զ�������ɾ���������±�Խ���顣
	system("pause");
	return 0;
}