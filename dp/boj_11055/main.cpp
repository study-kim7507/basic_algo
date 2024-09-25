#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[1001];
int dp[1001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		dp[i] = arr[i];
	}
	
	int ans = -1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (arr[j] < arr[i])
			{
				dp[i] = max(dp[i], dp[j] + arr[i]);
			}
		}
		ans = max(ans, dp[i]);
	}

	cout << ans << "\n";
	return 0;
}