#include <iostream>
#include <algorithm>
using namespace std;

int n, s;
int arr[100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	

	int ans = 987654321;

	// 투 포인터
	int en = 0;
	int tot = arr[0];
	for (int st = 0; st < n; st++)
	{
		while (en < n && tot < s)
		{
			en++;
			tot += arr[en];
		}
		if (en == n) break;
		ans = min(ans, en - st + 1);
		tot -= arr[st];
	}

	if (ans == 987654321) ans = 0;
	cout << ans << "\n";
	return 0;
}