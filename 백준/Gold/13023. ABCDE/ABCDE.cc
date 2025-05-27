// BOJ_13023.ABCDE
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<bool> vis;

bool answer = false;
void dfs(int cur, int depth)
{
	if (depth >= 5)
	{
		answer = true;
		return;
	}

	for (auto nxt : adj[cur])
	{
		if (vis[nxt]) continue;

		vis[nxt] = true;
		dfs(nxt, depth + 1);
		vis[nxt] = false;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	adj.assign(n, vector<int>());
	vis.assign(n, false);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 0; i < n; i++)
	{
		vis[i] = true;
		dfs(i, 1);
		vis[i] = false;
		if (answer)
		{
			std::cout << 1 << "\n";
			return 0;
		}
	}

	
	std::cout << 0 << "\n";
	return 0;
}