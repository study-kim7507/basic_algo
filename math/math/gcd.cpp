#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}

int lcm(int a, int b)
{
	return a / gcd(a, b) * b;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int a, b;
	cin >> a >> b;
	cout << gcd(a, b) << "\n";
	cout << lcm(a, b) << "\n";
	return 0;
}