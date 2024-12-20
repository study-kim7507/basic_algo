#include <iostream>
using namespace std;

int n;
int dp[50];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	dp[0] = 0; dp[1] = 1;
	for (int i = 2; i <= n; i++)
		dp[i] = dp[i - 1] + dp[i - 2];
	cout << dp[n];
	return 0;
}