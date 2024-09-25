// 1. 테이블 정의 : dp[i] = i를 1로 만드는데 사용되는 연산의 최소 수
// 2. 점화식 찾기
	//	i % 6 == 0 : min(dp[i / 2], dp[i / 3], dp[i - 1]) + 1
	//  i % 3 == 0 : min(dp[i / 3], dp[i - 1]) + 1
	//  i % 2 == 0 : min(dp[i / 2], dp[i - 1]) + 1
	//	나머지	   : dp[i - 1] + 1
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

	// 3. 초기값
	dp[0] = dp[1] = 0;
	dp[2] = dp[3] = 1;

	for (int i = 4; i <= n; i++)
	{
		if (i % 6 == 0) dp[i] = min({ dp[i / 2], dp[i / 3], dp[i - 1] }) + 1;
		else if (i % 3 == 0) dp[i] = min(dp[i / 3], dp[i - 1]) + 1;
		else if (i % 2 == 0) dp[i] = min(dp[i / 2], dp[i - 1]) + 1;
		else dp[i] = dp[i - 1] + 1;
	}

	cout << dp[n] << "\n";

	return 0;
}