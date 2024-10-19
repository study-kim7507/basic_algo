#include <iostream>
using namespace std;

int dp[1001][1001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string input1, input2;
	cin >> input1 >> input2;

	for (int i = 1; i <= input1.size(); i++)
	{
		if (input1[i - 1] == input2[0]) dp[1][i] = 1;
		else dp[1][i] = dp[1][i - 1];
	}

	for (int i = 1; i <= input2.size(); i++)
	{
		if (input2[i - 1] == input1[0]) dp[i][1] = 1;
		else dp[i][1] = dp[i-1][1];
	}

	for (int i = 2; i <= input2.size(); i++)
	{
		for (int j = 2; j <= input1.size(); j++)
		{
			if (input2[i - 1] == input1[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else 
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}	
	}

	cout << dp[input2.size()][input1.size()];
	return 0;
}