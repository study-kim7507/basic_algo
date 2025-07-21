// BOJ_11053. 가장 긴 증가하는 부분 수열
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> v;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;

		auto it = lower_bound(v.begin(), v.end(), num);
		if (it == v.end()) v.push_back(num);
		else *it = num;
	}

	std::cout << v.size() << "\n";
	return 0;
}