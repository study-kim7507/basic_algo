#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	if (n == 1) return 0;

	vector<int> result;
	int i = 2;
	while (n >= i * i)
	{
		if (n % i == 0)
		{
			result.push_back(i);
			n /= i;
			continue;
		}
		i++;
	}
	result.push_back(n);

	for (const int& a : result)
		cout << a << "\n";

	return 0;
}