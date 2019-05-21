#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

void setBigger(const vector<size_t> &ret, vector<size_t>::iterator &it_pre,
	vector<size_t>::iterator &it_next, bool &bigger)
{
	while (it_next < ret.end())
	{
		if (*it_pre > *it_next)
		{
			bigger = true;
			return;
		}
		else if (*it_pre < *it_next)
		{
			bigger = false;
			return;
		}
		++it_pre;
		++it_next;
	}
}
bool isReverse(const int &a, const int &b, bool &bigger)
{
	if (bigger)
	{
		if (a < b)
		{
			return true;
		}
	}
	if (!bigger)
	{
		if (a > b)
		{
			return true;
		}
	}
	return false;
}
int main() {
	size_t n;
	cin >> n;
	vector<size_t> ret;
	for (size_t i = 0; i < n; i++) {
		size_t x;
		scanf("%d", &x);
		ret.push_back(x);
	}
	auto it_pre = ret.begin();
	auto it_cur = it_pre;
	++it_cur;
	size_t pre = 0;
	int rise = 0;
	size_t count = 1;
	bool bigger;
	setBigger(ret, it_pre, it_cur, bigger);
	while (it_cur < ret.end())
	{
		if (!(it_cur < ret.end() && isReverse(*it_pre, *it_cur, bigger)))
		{
			++it_cur;
			++it_pre;
		}
		else
		{
			++count;
			++it_cur;
			++it_pre;
			setBigger(ret, it_pre, it_cur, bigger);
		}
	}
	cout << count << endl;
	return 0;
}
