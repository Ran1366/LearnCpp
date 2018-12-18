#include <iostream>
#include <cassert>
#include <vector>
#include "ARR.h"
using namespace std;
template<class T>
void SetArr(T * p , int num)
{
	for (int i = 0; i < num ; ++i)
	{
		cin >> p[i];
	}
}
template<class T>
void ShowArr(Arr<T> &p)
{
	for (int i = 0; i < p.GetSize(); ++i)
	{
		cout << p[i];
	}
	cout << endl;
}
int main()
{
	//设计一个类似于vector的模板,用于生成动态数组
	Arr<int> a(6);
	SetArr<int>(a, a.GetSize());
	ShowArr<int>(a);
	a.ResetSize(3);
	ShowArr<int>(a);
	a.ResetSize(6);
	ShowArr<int>(a);
	system("pause");
	return 0;
}