// BOJ 11054. 가장 긴 바이토닉 부분 수열
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> inputs;

int ans = 0;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	inputs = vector<int>(n);
	for (int i = 0; i < n; i++)
		cin >> inputs[i];

	vector<int> v1;
	for (int i = 0; i < n; i++)
	{
		auto it1 = lower_bound(v1.begin(), v1.end(), inputs[i]);
		
		if (it1 == v1.end()) v1.push_back(inputs[i]);
		else *it1 = inputs[i];

		vector<int> v2;
		for (int j = n - 1; j >= i; j--)
		{
			auto it2 = lower_bound(v2.begin(), v2.end(), inputs[j]);

			if (it2 == v2.end()) v2.push_back(inputs[j]);
			else *it2 = inputs[j];
		}

		if (v1[int(v1.size()) - 1] == v2[(int)v2.size() - 1])
			ans = max(ans, int(v1.size()) + int(v2.size()) - 1);
	}

	std::cout << ans << "\n";
	return 0;
}