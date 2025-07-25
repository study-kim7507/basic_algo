// BOJ_1463. 1로 만들기
// 다이나믹 프로그래밍
// 1. 테이블 정의
// 2. 점화식 찾기
// 3. 초기값
#include <iostream>
using namespace std;

int N;
int dp[1000001];

int main()
{
	cin >> N;
	dp[1] = 0;
	for (int i = 2; i <= N; i++)
	{
		dp[i] = dp[i - 1] + 1;
		if (i % 3 == 0) dp[i] = min(dp[i / 3] + 1, dp[i]);
		if (i % 2 == 0) dp[i] = min(dp[i / 2] + 1, dp[i]);
	}

	cout << dp[N] << "\n";
	return 0;
}