// BOJ_1976. 여행가자
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;

vector<int> edges[201];
vector<int> plan;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int num;
			cin >> num;
			if (num == 1)
			{
				edges[i].push_back(j);
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		int num;
		cin >> num;
		plan.push_back(num - 1);
	}

	for (int i = 0; i < m - 1; i++)
	{
		int st = plan[i];
		int dest = plan[i + 1];
		vector<bool> vis(n, false);
		
		queue<int> q;
		q.push(st);
		vis[st] = true;

		bool can = false;
		while (!q.empty())
		{
			auto cur = q.front(); q.pop();
			if (cur == dest)
			{
				can = true;
				break;
			}
			for (auto nxt : edges[cur])
			{
				if (vis[nxt]) continue;
				vis[nxt] = true;
				q.push(nxt);
			}
		}

		if (!can)
		{
			std::cout << "NO" << "\n";
			return 0;
		}
	}

	std::cout << "YES" << "\n";
	return 0;
}