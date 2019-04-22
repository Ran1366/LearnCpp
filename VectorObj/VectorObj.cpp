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
	vector<Point>ArrPoints(5); //自动生成一个Point类型的数组类,ArrPoints是其对象
	//这里的i定义为unsigned类型,是因为.size()被定义为unsigend int类型
	//否则程序会警告:有符号/无符号不匹配
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
	//vector封装任何类型的动态数组，自动创建和删除。数组下标越界检查。
	system("pause");
	return 0;
}