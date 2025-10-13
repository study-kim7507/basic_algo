// BOJ 1101. Fly me to the Alpha Centauri
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int x, y;
		cin >> x >> y;

		double dist = y - x;

		double distSqrt = sqrt(dist);
		int roundDistSqrt = round(distSqrt);

		if (distSqrt <= roundDistSqrt) std::cout << 2 * roundDistSqrt - 1 << "\n";
		else std::cout << 2 * roundDistSqrt << "\n";
	}

	return 0;
}