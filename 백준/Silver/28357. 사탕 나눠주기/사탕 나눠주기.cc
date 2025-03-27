// 23857. 사탕 나눠주기
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long n, k;
vector<long long> scores;

bool solve(long long curScore)
{
	long long result = 0;
	for (long long score : scores)
	{
		if (score > curScore)
			result += (score - curScore);
	}

	return result <= k;
}



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);


	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		long long score;
		cin >> score;
		scores.push_back(score);
	}

	long long st = 0;
	long long en = 1000000000001;

	while (st < en)
	{
		long long mid = (st + en) / 2;
		
		if (solve(mid))
		{
			en = mid;
		}
		else
		{
			st = mid + 1;
		}
			
	}

	cout << en << "\n";

	return 0;
}