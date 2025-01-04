// 9657. 돌 게임 3

#include <iostream>
using namespace std;

int n;
int dp[1001];	// dp[i] : i번째 돌을 가지고 가는 사람

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	dp[1] = dp[3] = dp[4] = 1;
	dp[2] = 0;

	for (int i = 5; i <= n; i++)
	{
		if (dp[i - 1] == 0 || dp[i - 3] == 0 || dp[i - 4] == 0) dp[i] = 1;
		else dp[i] = 0;
	}
	if (dp[n] == 1) cout << "SK" << "\n";
	else cout << "CY" << "\n";

	return 0;
}