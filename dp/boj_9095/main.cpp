#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int dp[20];
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;

		int n;
		cin >> n;

		for (int i = 4; i <= n; i++)
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		cout << dp[n] << "\n";
	}

	return 0;
}