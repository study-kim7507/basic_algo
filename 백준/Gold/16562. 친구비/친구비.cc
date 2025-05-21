// BOJ_16562. 친구비
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;


vector<int> friends[10001];
int cost[10001];
bool vis[10001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++)
		cin >> cost[i];
	for (int i = 0; i < m; i++)
	{
		int v, w;
		cin >> v >> w;
		friends[v].push_back(w);
		friends[w].push_back(v);
	}

	int allCost = 0;
	for (int i = 1; i <= n; i++)
	{
		if (vis[i]) continue;

		queue<int> q;
		q.push(i);
		vis[i] = true;
		int curCost = cost[i];

		while (!q.empty())
		{
			auto cur = q.front(); q.pop();
			for (auto nxt : friends[cur])
			{
				if (vis[nxt]) continue;

				curCost = min(curCost, cost[nxt]);
				vis[nxt] = true;
				q.push(nxt);
			}
		}
		// std::cout << i << " " << curCost << "\n";
		allCost += curCost;
	}

	if (allCost > k) std::cout << "Oh no" << "\n";
	else std::cout << allCost << "\n";

	return 0;
}