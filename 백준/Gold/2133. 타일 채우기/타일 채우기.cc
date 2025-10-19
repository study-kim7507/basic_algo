// BOJ 2133. 타일 채우기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	if (n % 2 != 0)
	{
		std::cout << 0 << "\n";
		return 0;
	}

	vector<long long> dp(n + 1, 0);
	dp[0] = 1;
	dp[2] = 3;
	for (int i = 4; i <= n; i++)
	{
		dp[i] = dp[i - 2] * 3;
		for (int j = i - 4; j >= 0; j -= 2)
			dp[i] += dp[j] * 2;
	}

	std::cout << dp[n] << "\n";
	return 0;
}