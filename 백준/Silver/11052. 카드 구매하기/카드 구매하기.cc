// BOJ 11052. 카드 구매하기
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

	vector<int> dp(n + 1, 0);
	for (int i = 1; i <= n; i++)
		cin >> dp[i];

	for (int i = 1; i <= n; i++)
	{
		int curMax = 0;
		for (int j = 0; j < i; j++)
			curMax = max(curMax, dp[j] + dp[i - j]);
		dp[i] = max(dp[i], curMax);
	}

	std::cout << dp[n] << "\n";

	return 0;
}