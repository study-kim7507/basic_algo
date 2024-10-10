// 최초 트리의 개수를 BFS, DFS를 이용하여 개수를 세고 이를 바탕으로 연결 그래프를 만든다 
	// -> 연결 그래프의 간선의 수 : 최초 간선의 수 + 트리의 개수 - 1  -> 트리의 개수 - 1 개의 뉴런 연결 연산
// 그리고 트리의 특성에 맞게 간선의 개수는 노드의 개수 - 1 이므로 이를 남기고 모두 제거
	// -> 최초 간선의 수 + 트리의 개수 - 1 - 노드의 개수 - 1 개의 뉴런 끊는 연산
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

int n, m;
vector<int> adj[100001];
bool vis[100001];
int parent[100001];

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
				if (parent[cur] == nxt) continue;
				if (vis[nxt] == true) continue;
				vis[nxt] = true;
				parent[nxt] = cur;
				q.push(nxt);
			}
		}
		treeCount++;
	}

	cout << m + treeCount - 1 - n + 1 + treeCount - 1<< "\n";
	return 0;
}