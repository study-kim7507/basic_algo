// BOJ_11053. 가장 긴 증가하는 부분 수열
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
	vector<int> num(n, 0);
	vector<int> dp(n, 1);

	for (int i = 0; i < n; i++)
		cin >> num[i];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (num[j] < num[i])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	std::cout << *max_element(dp.begin(), dp.end()) << "\n";
	return 0;
}