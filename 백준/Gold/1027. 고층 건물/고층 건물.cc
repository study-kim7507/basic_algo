// BOJ_1027. 고층건물
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	vector<int> buildings(n);
	for (int i = 0; i < n; i++)
	{
		int height;
		cin >> height;
		buildings[i] = height;
	}

	vector<int> answer(n);
	for (int i = 0; i < n; i++)
	{
		double maxGradient = -1000000000;
		for (int j = i + 1; j < n; j++)
		{
			int dx = j - i;
			int dy = buildings[j] - buildings[i];
			double curGradient = double(dy) / dx;

			if (maxGradient >= curGradient) continue;

			maxGradient = curGradient;
			answer[i]++; answer[j]++;
		}
	}

	std::cout << *max_element(answer.begin(), answer.end()) << "\n";

	return 0;
}