// BOJ_11067. 모노톤길
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <set>
#include <map>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		
		vector<pair<int, pair<int, int>>> routes;
		map<int, vector<pair<int, int>>> cafes;
		int maxX = INT_MIN;
		for (int i = 0; i < n; i++)
		{
			int x, y;
			cin >> x >> y;
			cafes[x].push_back({ x, y });
			maxX = max(maxX, x);
		}

		pair<int, int> curPos = { 0, 0 };
		for (int i = 0; i <= maxX; i++)
		{
			if (cafes[i].empty()) continue;
		
			vector<pair<int, pair<int, int>>> dists;
			for (const auto& e : cafes[i])
			{
				int diff = abs(curPos.first - e.first) + abs(curPos.second - e.second);
				dists.push_back({ diff, e });
			}
			sort(dists.begin(), dists.end());

			for (int i = 0; i < dists.size(); i++)
				routes.push_back({ routes.size() + 1, dists[i].second });
					
			curPos = dists[dists.size() - 1].second;
		}

		int m;
		cin >> m;
		for (int i = 0; i < m; i++)
		{
			int k;
			cin >> k;
			std::cout << routes[k - 1].second.first << " " << routes[k - 1].second.second << "\n";
		}
	}

	
	return 0;
}