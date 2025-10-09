// BOJ 9465. 스티커
#include <iostream>
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
		int n;
		cin >> n;
		vector<vector<int>> inputs(n, vector<int>(2, 0));
		for (int i = 0; i < n; i++)
			cin >> inputs[i][0];
		for (int i = 0; i < n; i++)
			cin >> inputs[i][1];

		vector<vector<int>> dp(n, vector<int>(3, 0));
		dp[0][0] = 0; dp[0][1] = inputs[0][0]; dp[0][2] = inputs[0][1];
		for (int i = 1; i < n; i++)
		{
			dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]);
			dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + inputs[i][0];
			dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + inputs[i][1];
		}

		std::cout << max({ dp[n - 1][0], dp[n - 1][1], dp[n - 1][2] }) << "\n";
	}

	return 0;
}