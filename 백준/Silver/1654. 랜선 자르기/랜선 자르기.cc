// BOJ_1654. 랜선 자르기
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int k, l;

bool solve(long long length, vector<int>& v)
{
	long long cnt = 0;
	for (int i = 0; i < k; i++)
		cnt += v[i] / length;

	return cnt >= l;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> k >> l;
	vector<int> v(k, 0);
	for (int i = 0; i < k; i++)
		cin >> v[i];

	long long ans = 0;
	long long st = 1, en = INT_MAX;
	while (st <= en)
	{
		long long mid = (st + en) / 2;
		if (solve(mid, v))
		{
			ans = max(ans, mid);
			st = mid + 1;
		}
		else en = mid - 1;
	}

	std::cout << ans << "\n";

	return 0;
}