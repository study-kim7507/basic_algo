#include <iostream>
using namespace std;

long long fibo[91];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	fibo[0] = 0;
	fibo[1] = fibo[2] = 1;
	for (int i = 3; i <= n; i++)
		fibo[i] = fibo[i - 1] + fibo[i - 2];

	cout << fibo[n] << "\n";
	return 0;
}