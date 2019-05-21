#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

void Reverse(string::iterator begin, string::iterator end)
{
	auto pos = find(begin, end, ' ');
	auto cur_begin = begin;
	auto cur_end = end;
	cur_end = pos;
	while (cur_end != end)
	{
		reverse(cur_begin, cur_end);
		++pos;
		cur_begin = pos;
		pos = find(cur_begin, end, ' ');
		cur_end = pos;
	}
	reverse(cur_begin, end);
}

int main() {
	//freopen("1.in","r",stdin);
	string ret;
	getline(cin, ret);
	//Reverse(ret);
	//solution(ret, ret.begin, ret.end);
	reverse(ret.begin(), ret.end());
	Reverse(ret.begin(), ret.end());
	cout << ret << endl;
	return 0;
}
