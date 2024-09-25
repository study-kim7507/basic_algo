#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
vector<int> adj[10001];
bool vis[10001];
int result[10001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[v].push_back(u);
	}
	for (int i = 1; i <= n; i++)
	{
		int cnt = -1;
		fill(vis + 1, vis + n + 1, false);
		queue<int> q;
		q.push(i);
		vis[i] = true;
		while (!q.empty())
		{
			auto cur = q.front(); q.pop();
			cnt++;
			for (auto nxt : adj[cur])
			{
				if (vis[nxt] == true) continue;
				vis[nxt] = true;
				q.push(nxt);
			}
		}

		result[i] = cnt;
	}

	int mx = *max_element(result + 1, result + n + 1);
	for (int i = 1; i <= n; i++)
		if (result[i] == mx) cout << i << " ";
	cout << "\n";

	return 0;
}