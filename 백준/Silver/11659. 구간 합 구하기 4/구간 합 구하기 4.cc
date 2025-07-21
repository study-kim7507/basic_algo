#include <iostream>
using namespace std;

int n, m;
int dp[100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		int num;
		cin >> num;
		dp[i] = dp[i - 1] + num;
	}

	for (int i = 0; i < m; i++)
	{
		int st, en;
		cin >> st >> en;
		cout << dp[en] - dp[st - 1] << "\n";
	}


	return 0;
}