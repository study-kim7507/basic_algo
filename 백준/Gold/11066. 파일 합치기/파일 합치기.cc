// BOJ_11066. 파일합치기
#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int k;
		cin >> k;
		vector<int> arr(k + 1, 0);
		vector<int> prefixSum(k + 1, 0);
		for (int i = 1; i <= k; i++)
		{
			cin >> arr[i];
			prefixSum[i] = prefixSum[i - 1] + arr[i];
		}

		vector<vector<int>> dp(k + 1, vector<int>(k + 1, 0));
		for (int len = 2; len <= k; len++)
		{
			for (int st = 1; st + len - 1 <= k; st++)
			{
				int en = st + len - 1;
				dp[st][st + len - 1] = INT_MAX;
				for (int cur = st; cur < en; cur++)
				{
					dp[st][en] = min(dp[st][en], dp[st][cur] + dp[cur + 1][en] + prefixSum[en] - prefixSum[st - 1]);
				}
			}
		}

		std::cout << dp[1][k] << "\n";
	}

	return 0;
}