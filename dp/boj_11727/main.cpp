// 1. 테이블 정의
	// dp[i] : 2 x i 직사각형을 타일로 채우는 방법의 수
// 2. 점화식
	// dp[k] = dp[k-1] + dp[k-2] + dp[k-2]
// 3. 초기값
	// dp[1] = 1, dp[2] = 3, dp[3] = 5


#include <iostream>
using namespace std;

int n;
int dp[1001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	dp[1] = 1;
	dp[2] = 3;
	dp[3] = 5;
	for (int i = 4; i <= n; i++)
		dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 2]) % 10007;
		

	cout << dp[n] << "\n";
	return 0;
}