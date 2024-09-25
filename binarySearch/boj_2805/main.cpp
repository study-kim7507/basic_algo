#include <iostream>
#include <algorithm>
using namespace std;

long long n, m;
long long trees[1000001];

bool solve(long long x)
{
	long long ans = 0;
	for (int i = 0; i < n; i++)
		ans += (trees[i] - x > 0 ? trees[i] - x : 0);
	return ans >= m;
}

long long bs(long long st, long long en)
{
	if (st >= en) return st;
	long long mid = (st + en + 1) / 2;
	if (solve(mid)) return bs(mid, en);
	else return bs(st, mid - 1);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> trees[i];

	sort(trees, trees + n);

	cout << bs(0, 2000000000) << "\n";

	return 0;
}