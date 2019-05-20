#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main() {
	//freopen("1.in","r",stdin);
	size_t n;
	cin >> n;
	vector<int> ret;
	ret.reserve(3 * n);
	for (size_t i = 0; i < 3 * n; i++) {
		size_t x;
		scanf("%d", &x);
		ret.push_back(x);
	}
	sort(ret.begin(), ret.end());
	size_t ans = 0;
	for (size_t i = n; i < ret.size(); i += 2)
	{
		ans += ret[i];
	}
	cout << ans << endl;
	return 0;
	
}