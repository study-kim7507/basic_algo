#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, c;
vector<pair<long long, int>> inputs;

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
	return a.second > b.second;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> c;
	for (int i = 0; i < n; i++)
	{
		long long num;
		cin >> num;

		bool isIn = false;
		for (int j = 0; j < inputs.size(); j++)
		{
			if (num == inputs[j].first)
			{
				inputs[j].second++;
				isIn = true;
				break;
			}
		}
		if (!isIn) inputs.push_back({ num, 1 });
	}
	
	stable_sort(inputs.begin(), inputs.end(), cmp);

	for (int i = 0; i < inputs.size(); i++)
	{
		for (int j = 0; j < inputs[i].second; j++)
			cout << inputs[i].first << " ";
	}

	return 0;
}