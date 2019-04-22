#include <iostream>
using namespace std;

void Move(char s , char d)
{
	cout << s << "-->" << d << endl;
}
void Harold(int n,char s , char m , char d)
{
	if (n == 1)
	{
		Move(s,d);
	}
	else
	{
		Harold(n - 1, s, d, m);
		Move(s, d);
		Harold(n - 1, m, s, d);
	}

}
int main()
{
	Harold(3, 'A', 'B', 'C');
	system("pause");
	return 0;
}