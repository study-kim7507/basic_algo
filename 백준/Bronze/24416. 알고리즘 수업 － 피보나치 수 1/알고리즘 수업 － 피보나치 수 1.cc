#include <iostream>
using namespace std;

long long dp[41];

int cnt1 = 0;
int fibo(int n)
{
	if (n == 1 || n == 2)
		return 1;
	cnt1++;
	return fibo(n - 1) + fibo(n - 2);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	dp[0] = 0; dp[1] = dp[2] = 1;
	int cnt2 = 0;
	for (int i = 3; i <= n; i++, cnt2++)
		dp[i] = dp[i - 1] + dp[i - 2];
	fibo(n);

	cout << cnt1 + 1 << " " << cnt2 << "\n";

	return 0;
}