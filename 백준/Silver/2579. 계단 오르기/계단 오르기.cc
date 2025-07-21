// BOJ_2579. 계단 오르기
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[301];
int dp[301][3];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	dp[1][1] = arr[1];
	dp[2][1] = arr[2];
	dp[2][2] = arr[1] + arr[2];
	for (int i = 3; i <= n; i++)
	{
		dp[i][1] = max(dp[i - 2][1], dp[i - 2][2]) + arr[i];
		dp[i][2] = dp[i - 1][1] + arr[i];
	}
		
	std::cout << max(dp[n][1], dp[n][2]) << "\n";


	return 0;
}