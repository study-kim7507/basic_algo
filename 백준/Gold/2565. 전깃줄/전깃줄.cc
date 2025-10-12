// BOJ 2565. 전깃줄
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	vector<pair<int, int>> inputs;
	for (int i = 0; i < n; i++)
	{
		int st, en;
		cin >> st >> en;
		inputs.push_back({ st, en });
	}
	sort(inputs.begin(), inputs.end());

	vector<int> lis;
	for (auto input : inputs)
	{
		int cur = input.second;
		auto it = lower_bound(lis.begin(), lis.end(), cur);
		if (it == lis.end()) lis.push_back(cur);
		else *it = cur;
	}

	std::cout << n - lis.size() << "\n";

	return 0;
}