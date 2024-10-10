// dp[i] : i를 만드는데 필요한 연산을 사용하는 횟수의 최솟값

#include <iostream>
#include <algorithm>
using namespace std;

int n;
int dp[1000001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	dp[1] = 0;
	dp[2] = dp[3] = 1;
	for (int i = 4; i <= n; i++)
	{
		if (i % 6 == 0)
			dp[i] = min({ dp[i / 3], dp[i / 2], dp[i - 1] }) + 1;
		else if (i % 3 == 0)
			dp[i] = min(dp[i / 3], dp[i - 1]) + 1;
		else if (i % 2 == 0)
			dp[i] = min(dp[i / 2], dp[i - 1]) + 1;
		else
			dp[i] = dp[i - 1] + 1;
	}

	cout << dp[n] << "\n";

	return 0;
}