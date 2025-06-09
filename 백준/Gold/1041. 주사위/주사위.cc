// BOJ_1041. 주사위
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long n;
vector<long long> planes(6, 0);

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < 6; i++)
		cin >> planes[i];

	if (n == 1)
	{
		long long sum = 0;
		for (auto e : planes)
			sum += e;
		sum -= *max_element(planes.begin(), planes.end());
		std::cout << sum << "\n";
		return 0;
	}

	// 보이는 면이 3개
	long long three = 0;
	for (int i = 0; i < 3; i++)
		three += min(planes[i], planes[5 - i]);
	three *= 4;

	// 보이는 면이 2개
	long long two = 101;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (i == j || i + j == 5) continue;
			two = min(two, planes[i] + planes[j]);
		}
	}
	two *= (8 * n - 12);

	// 보이는 면이 1개
	long long one = ((5 * n * n) - ((8 * n - 12) * 2) - (4 * 3)) * *min_element(planes.begin(), planes.end());

	std::cout << three + two + one << "\n";
	return 0;
}