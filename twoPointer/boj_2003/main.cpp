// 시간 제한이 0.5초, 배열의 크기가 10,000이므로 O(n^2)에 풀게되면 시간초과
// 연속합이 M이 되는 경우의 수를 계산
// 투포인터를 이용하면 O(2N)만에 해결이 가능해진다
	// st부터 en까지의 합이 M보다 작은 경우 en을 계속 늘려나감
	// st부터 en까지의 합이 M보다 크거나 같아질 때 en을 늘려가던 것을 멈추고
	// st부터 하나씩 합에서 빼나가면서 경우의 수를 모두 카운트

#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[10001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];


	int ans = 0;
	// 투포인터
	int en = 0;
	int sum = arr[0];
	for (int st = 0; st < n; st++)
	{
		while (en < n && sum < m)
		{
			++en;
			sum += arr[en];
		}
		if (en == n) break;
		if (sum == m) ans++;
		sum -= arr[st];
	}

	cout << ans << "\n";
	return 0;
}