#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int arr[10001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	// 오름차순 정렬
	sort(arr, arr + n);

	long long ans = 0;

	// 두 학생을 먼저 뽑고, 두 학생의 코딩 실력의 합을 
	// 0으로 만드는 학생이 있는지 이분탐색
	// O(n^2lgn)
	// 최악의 경우 1.4억번
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int lb = lower_bound(arr + j + 1, arr + n, -arr[i] - arr[j]) - arr;
			int ub = upper_bound(arr + j + 1, arr + n, -arr[i] - arr[j]) - arr;
			ans += (ub - lb);
		}
	}
	cout << ans << "\n";
	return 0;
}
