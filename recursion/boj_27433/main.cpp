#include <iostream>
using namespace std;

long long fac(int n)
{
	if (n == 1 || n == 0) return 1;
	return n * fac(n - 1);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	cout << fac(n) << "\n";
	return 0;
}