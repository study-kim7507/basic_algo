#include <iostream>
#include <algorithm>
#include <vector>
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
		cin >> arr[i];

	fill(dp, dp + n + 1, 1);
	for (int i = 1; i <= n; i++)
	{
		int ans = 1;
		for (int j = 1; j <= i; j++)
		{
			if ((arr[j] < arr[i]) && (dp[i] < dp[j] + 1))
			{
				dp[i] = dp[j] + 1;
			}
		}
	}
	int ans = *max_element(dp, dp + n + 1);
	cout << ans << "\n";

	vector<int> result;
	int j = n;
	for (int i = ans; i >= 1; i--)
	{
		for (; j >= 1; j--)
		{
			if (dp[j] == i)
			{
				result.push_back(arr[j]); 
				break;
			}
		}
	}
	
	for (int i = result.size() - 1; i >= 0; i--)
		cout << result[i] << " ";
	cout << "\n";
	return 0;
}