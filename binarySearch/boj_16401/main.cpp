// Parametric Search
#include <iostream>
#include <algorithm>
using namespace std;

int m, n;
long long snack[1000001];

bool solve(long long x)
{
	int cnt = 0;
	for (int i = 0; i < n; i++)
		cnt += (snack[i] / x);
	return cnt >= m;
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

	cin >> m >> n;
	for (int i = 0; i < n; i++)
		cin >> snack[i];

	sort(snack, snack + n);
	int maxLength = bs(1, 1000000000);
	int cnt = 0;
	for (int i = 0; i < n; i++)
		cnt += (snack[i] / maxLength);
	if (cnt < m) cout << 0 << "\n";
	else cout << maxLength << "\n";
	return 0;
}