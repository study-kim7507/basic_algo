#include <iostream>
using namespace std;

int n, k;
int arr[11];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int ans = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		if (k / arr[i] != 0)
		{
			ans += (k / arr[i]);
			k -= ((k / arr[i]) * arr[i]);
		}
		
		if (k == 0) break;
	}

	cout << ans << "\n";
	return 0;
}