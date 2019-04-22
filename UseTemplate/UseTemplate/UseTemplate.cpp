#include <iostream>
using namespace std;
template <class T>
T Max(T a, T b)
{
	return (a > b) ? a : b;
}
template <typename T>
T abs(T num)
{
	return (num > 0) ? num : -num;
}
int main()
{
	cout << abs(-5.5) << endl;
	cout << abs(-5) << endl;
	cout << Max(-3.2, 5.6) << endl;
	system("pause");
	return 0;
}