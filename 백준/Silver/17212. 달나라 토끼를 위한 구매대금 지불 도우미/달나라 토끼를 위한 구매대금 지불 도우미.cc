// 17212. 달나라 토끼를 위한 구매대금 지불 도우미

#include <iostream>
#include <algorithm>
using namespace std;

int dp[100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	dp[0] = 0;
	dp[1] = dp[2] = 1;
	dp[3] = dp[4] = 2;
	dp[5] = min({ dp[4], dp[3], dp[0] }) + 1;
	dp[6] = min({ dp[5], dp[4], dp[1] }) + 1;

	for (int i = 7; i <= n; i++)
		dp[i] = min({ dp[i - 1], dp[i - 2], dp[i - 5], dp[i - 7] }) + 1;
		
	cout << dp[n] << "\n";

	return 0;
}
