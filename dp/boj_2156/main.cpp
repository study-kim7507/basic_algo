// dp[i][j] : i번째 포도주 잔까지, j번 연속으로 마셨을 때의 최대 양
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[10001];
int dp[10001][3];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	dp[1][1] = arr[1];		// 첫번째 포도주를 마셨을 때

	for (int i = 2; i <= n; i++)
	{
		dp[i][0] = max({ dp[i - 1][0], dp[i - 1][1], dp[i - 1][2] });
		dp[i][1] = max({ dp[i - 1][0], dp[i - 2][0], dp[i - 2][1], dp[i - 2][2] }) + arr[i];
		dp[i][2] = dp[i - 1][1] + arr[i];
	}

	cout << *max_element(dp[n], dp[n] + 3) << "\n";
	return 0;
}
