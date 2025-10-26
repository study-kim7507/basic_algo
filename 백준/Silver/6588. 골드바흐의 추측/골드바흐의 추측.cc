// BOJ 6588. 골드바흐의 추측
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> oddPrimeNumbers;
vector<int> isPrime(1000001, true);

void findOddPrimeNumbers()
{
	for (int i = 2; i <= 1000; i++)
	{
		if (!isPrime[i]) continue;

		for (int j = i * 2; j <= 1000000; j += i)
			isPrime[j] = false;
	}

	for (int i = 3; i <= 1000000; i += 2)
		if (isPrime[i]) oddPrimeNumbers.push_back(i);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	findOddPrimeNumbers();
	
	while (true)
	{
		int num;
		cin >> num;
		if (num == 0) break;

		bool can = false;
		for (int i = 0; i < oddPrimeNumbers.size(); i++)
		{
			int a = oddPrimeNumbers[i];
			if (a > num / 2) break;

			int b = num - a;
			if (isPrime[b])
			{
				cout << num << " = " << a << " + " << b << "\n";
				can = true;
				break;
			}
		}
		if (!can) std::cout << "Goldbach's conjecture is wrong." << "\n";
	}

	return 0;
}
