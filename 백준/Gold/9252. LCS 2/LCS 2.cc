// BOJ 9252. LCS 2
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s1, s2;
	cin >> s1 >> s2;

	s1 = " " + s1;
	s2 = " " + s2;

	int n, m;
	n = s1.size(); m = s2.size();

	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			if (s1[i] == s2[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	int i = n - 1; 
	int j = m - 1;
	string common = "";
	while (dp[i][j] != 0)
	{
		if (s1[i] != s2[j])
		{
			if (dp[i - 1][j] == dp[i][j])
				i--;
			else if (dp[i][j - 1] == dp[i][j])
				j--;
		}
		else
		{
			common += s1[i];
			i--;
			j--;
		}
	}
	reverse(common.begin(), common.end());

	std::cout << dp[n-1][m-1] << "\n";
	std::cout << common << "\n";
	return 0;
}