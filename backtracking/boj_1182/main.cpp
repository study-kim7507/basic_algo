#include <iostream>
using namespace std;

int n, s;
int arr[21];
int ans = 0;

void func(int cur, int sum)
{
	if (cur == n)
	{
		if (sum == s)
			ans++;
		return;
	}

	func(cur + 1, sum + arr[cur]);
	func(cur + 1, sum);
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	func(0, 0);
	if (s == 0) ans--; // 크기가 양수인 부분수열만 카운트
					       // 공집합 제외

	cout << ans << "\n";
	return 0;
}