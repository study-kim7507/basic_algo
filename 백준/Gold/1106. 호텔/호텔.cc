
// BOJ_1106. 호텔
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// dp[i] : i명의 고객을 늘어나게 하는데 드는 최소 비용
int dp[1101];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int c, n;
	cin >> c >> n;

	dp[0] = 0;
	for (int i = 1; i <= 1100; i++)
		dp[i] = 987654321;

	for (int i = 0; i < n; i++)
	{
		int cost, num;
		cin >> cost >> num;
		
		for (int j = num; j <= 1100; j++)
			dp[j] = min(dp[j], dp[j - num] + cost);
	}

	int answer = INT_MAX;
	for (int i = c; i <= 1100; i++)
		answer = min(answer, dp[i]);

	std::cout << answer << "\n";


	return 0;
}