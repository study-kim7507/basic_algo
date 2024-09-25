// dp[i] = i를 1로 만드는데 드는 연산 횟수의 최소값
// if (k % 3 == 0) dp[k] = dp[k / 3] + 1
// if (k % 2 == 0) dp[k] = dp[k / 2] + 1
// else dp[k] = dp[k-1] + 1 
#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000001];
int path[1000001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	dp[1] = 0; path[1] = 0;
	dp[2] = 1; path[2] = 1;
	dp[3] = 1; path[3] = 1;

	for (int i = 4; i <= n; i++)
	{
		dp[i] = dp[i - 1] + 1;
		path[i] = i - 1;
		if (i % 3 == 0)
		{
			if (dp[i / 3] + 1 < dp[i])
			{
				dp[i] = dp[i / 3] + 1;
				path[i] = i / 3;
			}
		}
		if (i % 2 == 0)
		{
			if (dp[i / 2] + 1 < dp[i])
			{
				dp[i] = dp[i / 2] + 1;
				path[i] = i / 2;
			}
		}
	}

	cout << dp[n] << "\n";
	int cur = n;
	while (path[cur] != 0)
	{
		cout << cur << " ";
		cur = path[cur];
	}
	cout << cur << "\n";
	return 0;
}