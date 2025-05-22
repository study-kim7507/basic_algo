
// BOJ_1229. 육각수
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<long long> sixAngleNum;
int dp[1000001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	long long st = 1;
	sixAngleNum.push_back(0);
	sixAngleNum.push_back(st);
	for (long long i = 2; ; i++)
	{
		long long cur = st + 4 * i - 3;
		if (cur > 1000000) break;
		sixAngleNum.push_back(cur);
		st = cur;
	}


	int n;
	cin >> n;

	dp[0] = 0;
	for (int i = 1; i <= n; i++)
		dp[i] = 6;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < sixAngleNum.size(); j++)
		{
			if (i >= sixAngleNum[j])
			{
				dp[i] = min(dp[i], dp[i - sixAngleNum[j]] + 1);
			}
			else break;
		}
	}


	std::cout << dp[n] << "\n";
	return 0;
}