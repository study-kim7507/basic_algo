// BOJ_10942. 팰린드롬?
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool dp[2001][2001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	vector<int> nums(n + 1, 0);
	for (int i = 1; i <= n; i++)
		cin >> nums[i];

	for (int i = 1; i <= n; i++)
		dp[i][i] = true;

	for (int i = 1; i < n; i++)
		dp[i][i + 1] = nums[i] == nums[i + 1];

	for (int diff = 2; diff < n; diff++)
	{
		for (int st = 1; st + diff <= n; st++)
		{
			int en = st + diff;
			if (dp[st + 1][en - 1] && nums[st] == nums[en])
				dp[st][en] = true;
			else dp[st][en] = false;
		}
	}

	int m;
	cin >> m;
	while (m--)
	{
		int s, e;
		cin >> s >> e;
		std::cout << dp[s][e] << "\n";
	}
	return 0;
}