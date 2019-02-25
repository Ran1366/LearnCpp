#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
	//输入n个数，对这n个数排序之后去重，并输出从小到大排序结果
	vector<int> arr;
	istream_iterator<int> x1(cin),x2;
	arr.assign(x1, x2);
	sort(arr.begin(), arr.end());
	vector<int>::iterator iter;
	iter = unique(arr.begin(), arr.end());
	arr.resize(distance(arr.begin(), iter));
	for (iter = arr.begin(); iter != arr.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}