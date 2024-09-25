#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int a, b, c;
	cin >> a >> b >> c;
	long long mulResult = a * b * c;

	int freq[10] = { 0 };

	while (mulResult != 0)
	{
		freq[mulResult % 10]++;
		mulResult /= 10;
	}

	for (int a : freq)
	{
		cout << a << "\n";
	}

	return 0;
}