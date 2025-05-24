// BOJ_1253. 좋다
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int n;
vector<pair<int, int>> inputs;
unordered_map<int, int> numCount;
unordered_map<int, int> counts;

int answer = 0;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		inputs.push_back({ input, i });

		numCount[input]++;
		counts[input]++;
	}
	sort(inputs.begin(), inputs.end());

	for (int i = 0; i < inputs.size() - 1; i++)
	{
		for (int j = i + 1; j < inputs.size(); j++)
		{
			int sum = inputs[i].first + inputs[j].first;
			
			if (inputs[i].first == 0 && inputs[j].first == 0 && numCount[sum] <= 2) continue;
			else if (inputs[i].first == 0 && inputs[j].first != 0 && numCount[sum] < 2) continue;
			else if (inputs[i].first != 0 && inputs[j].first == 0 && numCount[sum] < 2) continue;

			if (counts[sum] != 0)
			{
				answer += counts[sum];
				counts[sum] = 0;
			}			
		}
	}

	std::cout << answer << "\n";
	return 0;
}