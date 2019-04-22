#include <iostream>
#include <string>
using namespace std;
class Arrays
{
public:
	Arrays(int x) :pArr(new int[x]), size(x) { cout << "构造..." << endl; };//构造函数
	Arrays(const Arrays &x) :pArr(new int(x.size)),size(x.size){ cout << "复制构造..." << endl; };//复制构造函数
	~Arrays() 
	{
		delete []pArr;
		cout << "析构" << endl;
	};
	void SetElements(int *elem);
	int SumOfMaxSub();
private:
	int *pArr;
	int size;
};
int Arrays::SumOfMaxSub()
{
	int sum = 0;
	int i = 0;
	int max = -9999;
	while (i < size)
	{
		if (*(pArr + i) >= 0)
		{
			sum += *(pArr + i);
			++i;
		}
		if (*(pArr + i) < 0)
		{
			if (*(pArr + i) > max)
			{
				max = *pArr;
				++i;
			}
		}
	}
	if (sum == 0)
	{
		return max;
	}
	else
	{
		return sum;
	}
}
void Arrays::SetElements(int *elem)
{
	for (int i = 0; i < size; ++i)
	{
		*(pArr + i) = elem[i];
	}
}
void SetArr()
{
	cout << "请输入你要生成的数组的长度" << endl;
	int size;
	cin >> size;
	if (size >=1)
	{
		Arrays arr(size);
		int *elem = new int[size];
		cout << "请依次输入数组的每个元素[-5000~5000]" << endl;
		for (int i = 0 ; i < size ; ++i)
		{
			cin >> *(elem + i);
		}
		arr.SetElements(elem);
		cout << "最大子串和:" << arr.SumOfMaxSub() << endl;
	}
}
int main()
{
	//给定一个数组a[0, ..., n - 1], 求其最大子数组(长度 >= 1)和
	//第一行一个整数n(1<=n<=5000)，然后依次输入n个整数（每个整数范围[-5000, 5000]）
	//输出一个整数表示最大子数组和
	//new 类型名T（初始化参数列表）
	//功能：在程序执行期间，申请用于存放T类型对象的内存空间，并依初值列表赋以初值
	//delete 指针p
	//功能：释放指针p所指向的内存。p必须是new操作的返回值
	//分配：new 类型名T [ 数组长度 ]
	//数组长度可以是任何表达式，在运行时计算
	//释放：delete[] 数组名p
	//释放指针p所指向的数组。
	//p必须是用new分配得到的数组首地址。
	SetArr();
	system("pause");
	return 0;
}