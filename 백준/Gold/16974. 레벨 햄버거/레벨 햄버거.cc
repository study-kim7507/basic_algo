// 16974. 레벨 햄버거
#include <iostream>
using namespace std;

long long layer[51];
long long patty[51];

long long solve(int n, long long x)
{
	if (n == 0) return 1;
	if (x == 1) return 0;

	long long mid = (layer[n] + 1) / 2;

	if (x == mid) return patty[n - 1] + 1;
	else if (x < mid) return solve(n - 1, x - 1);
	else return patty[n - 1] + 1 + solve(n - 1, x - (layer[n - 1] + 2));
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	long long x;
	cin >> n >> x;
	
	layer[0] = 1;
	patty[0] = 1;

	for (int i = 1; i <= n; i++)
	{
		layer[i] = layer[i - 1] * 2 + 3;
		patty[i] = patty[i - 1] * 2 + 1;
	}
	
	long long result = solve(n, x);
	cout << result << "\n";

	return 0;
}