#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<int> adj[100001];
int p[100001];			// 부모 노드 번호 저장

void dfs(int cur)
{
	for (int nxt : adj[cur])
	{
		if (p[nxt] == cur || p[nxt] != 0) continue;
		p[nxt] = cur;
		dfs(nxt);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);

	for (int i = 2; i <= n; i++)
		cout << p[i] << "\n";

	return 0;
}