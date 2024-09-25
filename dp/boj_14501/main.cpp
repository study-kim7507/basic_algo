#include <iostream>
#include <algorithm>
using namespace std;

#define D first
#define C second

int n;
pair<int, int> arr[1001];
int dp[1001];

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
		if (t + i - 1 <= n)
			dp[i] = p;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (j + arr[j].D <= i)
			{
				if (i + arr[i].D - 1 <= n)
					dp[i] = max(dp[i], dp[j] + arr[i].C);
			}
		}
	}

	cout << *max_element(dp, dp + n + 1) << "\n";
	return 0;
}