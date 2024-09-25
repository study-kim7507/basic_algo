#include <iostream>
using namespace std;

int main()
{
	int freq[10] = { 0 };
	int input;
	cin >> input;

	while (input != 0)
	{
		freq[input % 10]++;
		input /= 10;
	}

	int max = 0;
	int sum6and9 = 0;
	for (int i = 0; i < 10; i++)
	{
		if (i == 6 || i == 9)
		{
			sum6and9 += freq[i];
		}
		else if (max < freq[i])
		{
			max = freq[i];
		}
	}

	int result = 0;
	sum6and9 = (sum6and9 + 1) / 2;
	if (max > sum6and9) result = max;
	else result = sum6and9;

	cout << result << "\n";
	return 0;
}