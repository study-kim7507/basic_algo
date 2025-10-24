// 위상 정렬
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> adj[32001];
int inDegree[32001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		inDegree[v]++;
	}

	queue<int> q;
	for (int i = 1; i <= n; i++)
		if (inDegree[i] == 0) q.push(i);

	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		cout << cur << " ";
		for (auto nxt : adj[cur])
		{
			if (--inDegree[nxt] == 0) q.push(nxt);
		}
	}

	return 0;
}