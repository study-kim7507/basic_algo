// 13702. 이상한 술집
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n, k;
vector<int> v;

bool solve(int capacity)
{
	int cnt = 0;
	for (auto e : v)
		cnt += (e / capacity);

	return cnt < k;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;
	
	for (int i = 0; i < n; i++)
	{
		int ml;
		cin >> ml;
		v.push_back(ml);
	}

	sort(v.begin(), v.end());

	if (n == 1)
	{
		cout << v[0] << "\n";
		return 0;
	}

	int st = 0;
	int en = INT_MAX;

	long long ans = 0;
	while (st <= en)
	{
		long long mid = (st + en) / 2;
		if (mid == 0 || k == 0) break;

		if (solve(mid))
			en = mid - 1;
		else
		{
			st = mid + 1;
			ans = mid;
		}
			
	}

	cout << ans << "\n";

	return 0;
}
