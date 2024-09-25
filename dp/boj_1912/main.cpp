#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

int n;
int dp[100001];
int arr[100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i<= n; i++)
		cin >> arr[i];

	dp[1] = arr[1];
	for (int i = 2; i <= n; i++)
	{
		dp[i] = max(0, dp[i - 1]) + arr[i];
	}
	cout << *max_element(dp + 1, dp + n + 1) << "\n";
	

	return 0;
}