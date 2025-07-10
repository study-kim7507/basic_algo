// BOJ_1477. 휴게소 세우기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, l;
vector<int> rest;
vector<int> diff;

bool solve(int cur)
{
	int cnt = 0;
	for (auto e : diff)
	{
		int curCnt = e / cur;
		if (e % cur == 0) curCnt--;
		cnt += curCnt;
	}
	return cnt > m;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> l;
	rest.assign(n + 2, 0);
	rest[n + 1] = l;
	for (int i = 1; i <= n; i++)
		cin >> rest[i];
	sort(rest.begin(), rest.end());
	for (int i = 1; i <= n + 1; i++)
		diff.push_back(rest[i] - rest[i - 1]);
	
	int ans = l;
	int st = 1, en = l - 1;
	while (st <= en)
	{
		int mid = (st + en) / 2;
		if (solve(mid)) st = mid + 1;
		else
		{
			en = mid - 1;
			ans = min(ans, mid);
		}
	}

	std::cout << ans << "\n";

	return 0;
}