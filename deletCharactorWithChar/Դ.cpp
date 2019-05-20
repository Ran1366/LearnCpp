#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
bool canPush(const string::iterator it_s1, const string &s2)
{
	for (auto it_s2 = s2.begin(); it_s2 < s2.end(); ++it_s2)
	{
		if (*it_s1 == *it_s2)
		{
			return false;
		}
	}
	return true;
}
int main() {
	string s1,s2,s3, s;
	getline(cin, s1);
	getline(cin, s2);

	for (auto it_s1 = s1.begin(); it_s1 < s1.end(); ++it_s1)
	{
		if (canPush(it_s1, s2))
		{
			s3.push_back(*it_s1);
		}
	}
	cout << s3 << endl;
	system("pause");
	return 0;
}