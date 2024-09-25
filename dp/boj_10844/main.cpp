#include <iostream>
using namespace std;

long long dp[101][10];			// dp[i][j] : 길이가 i인 계단수 중 j로 끝나는 계단 수의 개수
const long long divNum = 1000000000;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	fill(dp[1], dp[1] + 10, 1);
	dp[1][0] = 0;

	int n; cin >> n;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 0) dp[i][j] += (dp[i - 1][1] % divNum);
			else if (j == 9) dp[i][j] += (dp[i - 1][8] % divNum);
			else
			{
				dp[i][j] += (dp[i - 1][j - 1] % divNum);
				dp[i][j] += (dp[i - 1][j + 1] % divNum);
			}
		}
	}

	long long sum = 0;
	for (int j = 0; j < 10; j++)
	{
		sum = (sum + dp[n][j]) % divNum;
	}
		
	cout << sum << "\n";
	return 0;
}