#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int n, r, q;
vector<int> adj[100001];
bool vis[100001];
int result[100001];

int dfs(int cur)
{
	vis[cur] = true;
	for (auto nxt : adj[cur])
	{
		if (vis[nxt] == true) continue;
		result[cur] += dfs(nxt);
	}
	result[cur]++;
	return result[cur];
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> r >> q;

	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(r);
	while (q--)
	{
		int u;
		cin >> u;
		cout << result[u] << "\n";
	}
	return 0;
}