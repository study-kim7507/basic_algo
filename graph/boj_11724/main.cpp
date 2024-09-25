#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
vector<int> adj[1001];
bool vis[1001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;								// ������ ����, ������ ����

	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);					// ������ �׷���
		adj[v].push_back(u);
	}


	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (vis[i] == true) continue;			// �̹� �湮�� ����
		queue<int> q;
		q.push(i);
		vis[i] = true;

		while (!q.empty())
		{
			auto cur = q.front(); q.pop();
			for (auto nxt : adj[cur])
			{
				if (vis[nxt] == true) continue;
				vis[nxt] = true;
				q.push(nxt);
			}
		}

		ans++;
	}

	cout << ans << "\n";

	return 0;
}