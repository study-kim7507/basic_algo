// 접근 : 다이나믹 프로그래밍
// 1. 배열		-> dp[i] : i단계에서 점의 개수
// 2. 점화식	-> dp[i] : i * 3 + 1 + dp[i-1]
// 3. 초기값	-> dp[1] : 5

#include <iostream>
using namespace std;

int n;
int dp[10000001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	dp[1] = 5;
	for (int i = 2; i <= n; i++)
		dp[i] = (i * 3 + 1 + dp[i - 1]) % 45678;

	cout << dp[n];

	return 0;
}