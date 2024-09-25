#include <iostream>
using namespace std;

int gcd(const int& a, const int& b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}

int lcm(const int& a, const int& b)
{
	return a / gcd(a, b) * b;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int ans = -1;
		int m, n, x, y;
		cin >> m >> n >> x >> y;
		int l = lcm(m, n);
		
		if (x == m) x = 0;
		if (y == n) y = 0;
		for (int i = x; i <= l; i += m)
		{
			if (i == 0) continue;
			if (i % n == y)
			{
				ans = i;
				break;
			}
		}
		cout << ans << "\n";
	}

	return 0;
}