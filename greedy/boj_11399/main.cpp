#include <iostream>
#include <algorithm>
using namespace std;

int n;
int p[1001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> p[i];

	sort(p, p + n);
	long long ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			ans += p[j];
		}
		ans += p[i];
	}
		
	cout << ans << "\n";
	return 0;
}