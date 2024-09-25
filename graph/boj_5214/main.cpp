#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, k, m;
vector<int> adj[110000];
long long dist[110000];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k >> m;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 0; j < k; j++)
		{
			int station;
			cin >> station;
			adj[n + i].push_back(station);
			adj[station].push_back(n + i);
		}
	}

	queue<int> q;
	q.push(1);
	dist[1] = 1;
	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		for (auto nxt : adj[cur])
		{
			if (dist[nxt] != 0) continue;
			if (nxt > n) dist[nxt] = dist[cur];
			else dist[nxt] = dist[cur] + 1;
			q.push(nxt);
		}
	}

	if (dist[n] == 0) cout << -1 << "\n";
	else cout << dist[n] << "\n";


	return 0;
}