// 최소신장트리 : 무방향 연결 그래프에서, 모든 정점을 방문하는 간선의 합이 최소가 되는 트리 
	// 트리에서 간선의 개수는 정점의 개수 - 1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parent[1001];

int uf_find(int x)
{
	if (parent[x] != x)
		return parent[x] = uf_find(parent[x]);
	return x;
}

void uf_union(int x, int y)
{
	int a = uf_find(x);
	int b = uf_find(y);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		vector<pair<int, int>> edges;
		for (int i = 1; i <= n; i++)
			parent[i] = i;
		for (int i = 0; i < m; i++)
		{
			int u, v;
			cin >> u >> v;
			edges.push_back({ u, v });
		}

		int ans = 0;
		for (int i = 0; i < m; i++)
		{
			auto cur = edges[i];
			if (uf_find(cur.first) == uf_find(cur.second)) continue;
			uf_union(cur.first, cur.second);
			ans++;
		}
		cout << ans << "\n";
	}

	return 0;
}