#include <iostream>
using namespace std;

long long result[21];

long long fibo(int x)
{
	if (x == 0) return 0;
	else if (x == 1) return 1;
	return fibo(x - 1) + fibo(x - 2);
}

int main()
{
	int n;
	cin >> n;

	cout << fibo(n) << "\n";

	return 0;
}
