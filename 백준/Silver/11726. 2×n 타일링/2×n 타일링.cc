// 11726. 2xn 타일링
// DP
	// 1. 배열 정의
	// 2. 초기값 찾기
	// 3. 점화식 정의

#include <iostream>
#include <algorithm>
using namespace std;


// dp[i] : 2xi 크기의 직사각형을 1x2, 2x1 타일로 채우는 방법의 수
int dp[1001];

int main()
{
	int n;
	cin >> n;

	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	}

	cout << dp[n] << "\n";
	return 0;
}