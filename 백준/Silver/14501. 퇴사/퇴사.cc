// BOJ_14501. 퇴사
#include <iostream>
#include <algorithm>
using namespace std;

int n;
pair<int, int> arr[21];

int dp[21];	

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int t, p;
		cin >> t >> p;
		arr[i] = { t, p };
	}

	for (int i = 1; i <= n; i++)
	{
		int t = arr[i].first;
		int p = arr[i].second;
		
		if (i + t <= n + 1) dp[i + t] = max(dp[i + t], dp[i] + p);
		dp[i + 1] = max(dp[i + 1], dp[i]);
	}

	std::cout << dp[n + 1] << "\n";

	return 0;
}