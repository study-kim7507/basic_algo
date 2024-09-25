// 서로 방향이 반대인 두 개의 그래프를 운용
// 각 정점에서 시작해서 더 이상 연결된 노드가 없는 노드까지의 거리들의 합
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
vector<int> adj1[100], adj2[100];
bool vis[100];
int result[100];

void bfs(int st, vector<int> adj[])
{
	fill(vis, vis + n + 1, false);
	queue<int> q;
	q.push(st);
	vis[st] = true;

	int cnt = 0;
	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		for (auto nxt : adj[cur])
		{
			if (vis[nxt] == true) continue;
			vis[nxt] = true;
			q.push(nxt);
			cnt++;
		}
	}

	result[st] = max(result[st], cnt);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		adj1[u].push_back(v);
		adj2[v].push_back(u);
	}

	for (int i = 1; i <= n; i++)
	{
		bfs(i, adj1);
		bfs(i, adj2);
	}

	int ans = 0;
	for (int i = 1; i <= n; i++)
		if (result[i] >= (n + 1) / 2) ans++;

	cout << ans << "\n";

	return 0;
}