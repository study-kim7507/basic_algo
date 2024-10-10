// for (auto nxt : adj[cur])
//		if (parent[nxt] == cur) continue;
//		if (parent[nxt] == parent[cur]) -> 사이클

// 모든 뉴런의 순회를 마친 뒤 사이클의 개수 -> 두 뉴런의 연결을 끊는 연산
// 모든 뉴런의 순회를 마친 뒤 트리의 개수 -> 두 뉴런을 연결하는 연산
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

int n, m;
vector<int> adj[100001];
int parent[100001];
bool vis[100001];
set<pair<int, int>> cycle;

int parent2[100001];
// 사이클을 찾기 위한 유니온-파인드
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

	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		parent[i] = i;

	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int treeCount = 0;

	for (int i = 1; i <= n; i++)
	{
		if (vis[i] == true) continue;

		queue<int> q;
		q.push(i);
		vis[i] = true;
		while (!q.empty())
		{
			int cur = q.front(); q.pop();
			for (int nxt : adj[cur])
			{
				if (parent2[cur] == nxt) continue;
				// 부모가 같으면 -> 사이클 형성
				if (uf_find(nxt) == uf_find(cur))
				{
					cycle.insert({ min(nxt, cur), max(nxt, cur) });
					continue;
				}
				parent2[nxt] = cur;
				q.push(nxt);
				uf_union(nxt, cur);
				vis[nxt] = true;
			}
		}
		treeCount++;
	}

	cout << cycle.size() + treeCount - 1 << "\n";
	return 0;
}