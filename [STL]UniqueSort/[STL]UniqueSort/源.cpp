#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
	//����n����������n��������֮��ȥ�أ��������С����������
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