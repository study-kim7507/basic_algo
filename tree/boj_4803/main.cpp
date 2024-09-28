// 주어진 그래프에서 트리의 개수를 세는 문제
// 모든 정점을 순회 

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int parent[501];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for(int t = 1; ; t++)
	{
		int n, m;						// 입력으로 주어질 그래프의 정점, 간선의 개수
		cin >> n >> m;
		if (n == 0 && m == 0) break;

		vector<int> adj[501];
		for (int i = 0; i < m; i++)
		{
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		
		int cnt = 0;
		bool vis[501];
		fill(vis, vis + 501, false);
		for (int i = 1; i <= n; i++)
		{
			if (vis[i] == true) continue;
			bool isTree = true;
			queue<int> q;
			q.push(i);
			vis[i] = true;
			while (!q.empty())
			{
				auto cur = q.front(); q.pop();
				for (auto nxt : adj[cur])
				{
					if (parent[cur] == nxt) continue;
					if (vis[nxt] == true)
					{
						isTree = false;
						continue;
					}
					q.push(nxt);
					parent[nxt] = cur;
					vis[nxt] = true;
				}
			}
			if (isTree) cnt++;
		}

		cout << "Case " << t << ": ";
		if (cnt == 0) cout << "No trees." << "\n";
		else if (cnt == 1) cout << "There is one tree." << "\n";
		else cout << "A forest of " << cnt << " trees." << "\n";
	}
	return 0;
}



