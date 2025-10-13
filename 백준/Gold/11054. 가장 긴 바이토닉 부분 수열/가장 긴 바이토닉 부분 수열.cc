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

	vector<int> v1, v2;
	vector<int> count1, count2;

	// 정방향 LIS
	for (int i = 0; i < n; i++)
	{
		auto it = lower_bound(v1.begin(), v1.end(), inputs[i]);
		if (it == v1.end()) v1.push_back(inputs[i]);
		else *it = inputs[i];

		count1.push_back(v1.size());
	}

	// 역방향 LIS
	for (int i = n - 1; i >= 0; i--)
	{
		auto it = lower_bound(v2.begin(), v2.end(), inputs[i]);
		if (it == v2.end()) v2.push_back(inputs[i]);
		else *it = inputs[i];

		count2.push_back(v2.size());
	}

	reverse(count2.begin(), count2.end());
	
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(ans, count1[i] + count2[i] - 1);
	
	std::cout << ans << "\n";

	return 0;
}