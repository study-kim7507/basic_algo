// 모든 정점을 순회, 인접한 정점이 현재 방문한 정점과 동일한 색이면 이분그래프가 될 수 없음
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int k;
	cin >> k;
	while (k--)
	{
		int n, m;
		vector<int> adj[20001];
		char vis[20001];
		
		cin >> n >> m;
		fill(vis, vis + n + 1, 'Y');		// 아직 방문하지 않음

		for (int i = 0; i < m; i++)
		{
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		bool ans = true;
		for (int i = 1; i <= n; i++)
		{
			if (vis[i] != 'Y') continue;
			queue<int> q;
			q.push(i);
			vis[i] = 'B';
			while (!q.empty())
			{
				auto cur = q.front(); q.pop();
				for (auto nxt : adj[cur])
				{
					if (vis[nxt] != 'Y')
					{
						if (vis[nxt] == vis[cur])
						{
							ans = false;
							continue;
						}
						continue;
					}
					vis[nxt] = vis[cur] == 'B' ? 'R' : 'B';
					q.push(nxt);
				}
			}
		}
		if (ans) cout << "YES" << "\n";
		else cout << "NO" << "\n";

	}

	return 0;
}