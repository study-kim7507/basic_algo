// BOJ 1654. 랜선 자르기
#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

int k, n;
vector<int> lines;

bool solve(long long len)
{
	int cnt = 0;
	for (auto line : lines)
		cnt += line / len;

	return cnt >= n;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> k >> n;
	for (int i = 0; i < k; i++)
	{
		int len;
		cin >> len;
		lines.push_back(len);
	}

	long long st = 1;
	long long en = LLONG_MAX - 1;

	while (st + 1 < en)
	{
		long long mid = (st + en) / 2;
		if (solve(mid)) st = mid;
		else en = mid;
	}
	
	std::cout << st << "\n";
	return 0;
}