// 1092. 배
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

int n, m;

vector<int> crane;
vector<int> box;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int w;
		cin >> w;
		crane.push_back(w);
	}

	cin >> m;
	for (int j = 0; j < m; j++)
	{
		int w;
		cin >> w;
		box.push_back(w);
	}

	sort(crane.begin(), crane.end());
	sort(box.begin(), box.end());

	if (crane[n-1] < box[m-1])
	{
		cout << -1 << "\n";
		return 0;
	}

	int time = 0;
	
	while (!box.empty())
	{
		for (int i = 0; i < n; i++)
		{
			int curCrane = crane[i];
			auto it = upper_bound(box.begin(), box.end(), curCrane);

			if (it == box.begin()) continue;

			box.erase(--it);
		}

		time++;
	}

	cout << time << "\n";
	return 0;
}