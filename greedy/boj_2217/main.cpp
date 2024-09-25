#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);
	
	int ans = -1;
	for (int k = n; k >= 1; k--)
		ans = max(ans, arr[n - k] * k);

	cout << ans << "\n";
	return 0;
}