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
	ArraysPoint(int i_size):P(new Point[i_size]),size(i_size){};//动态分配内存
	~ArraysPoint()
	{
		cout << "deleting..." << endl;
		delete[] P;//写[]是为了释放所有对象,不写方括号的话只释放一个对象
	}
	Point& Elements(int index) //返回引用类型可以调用所属类的函数
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
	//以Point类为例,将动态数组封装成类,
	int size;
	int input;
	cout << "请输入要生成的数组的长度" << endl;
	cin >> size;
	ArraysPoint arr1(size);
	for (int i = 0 ; i < size ; ++i)
	{
		arr1.Elements(i).SetPoint(i+2, i+3);
	}
	cout << "请输入想要查看的元素的下标" << endl;
	cin >> input;
	cout << "该点的X值是:" << arr1.Elements(input).GetX() << endl;
	cout << "该点的Y值是:" << arr1.Elements(input).GetY() << endl;
	system("pause");
	return 0;
}