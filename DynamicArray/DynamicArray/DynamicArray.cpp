#include <iostream>
#include <cassert>
using namespace std;
class Point
{
public:
	Point():x(0),y(0){};
	Point(int ix, int iy) :x(ix), y(iy) {};
	int GetX() { return x; };
	int GetY() { return y; };
	void SetPoint(int ix, int iy) { x = ix; y = iy; };
private:
	int x;
	int y;
};
class ArraysPoint
{
public:
	ArraysPoint(int i_size):P(new Point[i_size]),size(i_size){};//��̬�����ڴ�
	~ArraysPoint()
	{
		cout << "deleting..." << endl;
		delete[] P;//д[]��Ϊ���ͷ����ж���,��д�����ŵĻ�ֻ�ͷ�һ������
	}
	Point& Elements(int index) //�����������Ϳ��Ե���������ĺ���
	{
		assert(index >= 0 && index < size);
		return P[index];
	};
private:
	Point *P;
	int size;
};
int main()
{
	//��Point��Ϊ��,����̬�����װ����,
	int size;
	int input;
	cout << "������Ҫ���ɵ�����ĳ���" << endl;
	cin >> size;
	ArraysPoint arr1(size);
	for (int i = 0 ; i < size ; ++i)
	{
		arr1.Elements(i).SetPoint(i+2, i+3);
	}
	cout << "��������Ҫ�鿴��Ԫ�ص��±�" << endl;
	cin >> input;
	cout << "�õ��Xֵ��:" << arr1.Elements(input).GetX() << endl;
	cout << "�õ��Yֵ��:" << arr1.Elements(input).GetY() << endl;
	system("pause");
	return 0;
}