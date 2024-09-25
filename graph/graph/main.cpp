// 그래프 = 정점과 간선으로 이루어진 자료구조
	// 차수 : 간선으로 연결된 정점의 개수
	// 무방향 그래프	(degree), 방향 그래프 (indegree, outdegree)
	// 순환 그래프, 비순환 그래프
	// 완전 그래프, 연결 그래프
		// 완전 그래프 : 모든 서로 다른 두 정점 쌍이 간선으로 연결된 그래프
		// 연결 그래프 : 임의의 두 정점 사이에 경로가 항상 존재하는 그래프


#include <iostream>
#include <algorithm> 
#include <queue>
#include <vector>
#include <stack>
using namespace std;

// 표현법1 : 인접행렬
void adj_matrix_ex()
{
	int adj_matrix[10][10] = {};			// O(V^2)의 공간복잡도
	int v, e;
	cin >> v >> e;
	for (int i = 0; i < e; i++)
	{
		int u, v;
		cin >> u >> v;					
		adj_matrix[u][v] = 1;				// u노드에서 v노드로 가는 간선 - 방향 그래프
		adj_matrix[v][u] = 1;				// v노드에서 u노드로 가는 간선 - 무방향 그래프
	}
}

// 표현법2 : 인접리스트
void adj_list_ex()
{
	vector<int> adj[10];					// O(V + E)
	int v, e;
	cin >> v >> e;
	for (int i = 0; i < e; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);				// u노드에서 v노드로 가는 간선 - 방향 그래프
		adj[v].push_back(u);				// v노드에서 u노드로 가는 간선 - 무방향 그래프
	}
}

// BFS = 그래프에서 너비를 우선으로 방문하는 알고리즘
vector<int> adj[10];
bool vis[10];

void bfs()
{
	queue<int> q;
	q.push(1);
	vis[1] = true;
	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		for (auto nxt : adj[cur])			// 현재 정점과 간선으로 연결된 모든 정점을 순회
		{
			if (vis[nxt]) continue;			// 이미 방문한 정점
			vis[nxt] = true;
		}
	}
}

int dist[10];
void bfs_dist()
{
	fill(dist, dist + 10, -1);
	queue<int> q;
	q.push(1);
	dist[1] = 0;
	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		for (auto nxt : adj[cur])
		{
			if (dist[nxt] != -1) continue;	// 이미 방문했음
			dist[nxt] = dist[cur] + 1;
			q.push(nxt);
		}
	}
	
}

// DFS
// 재귀 DFS, 비재귀 DFS는 방문 순서의 차이가 존재함
void dfs()
{
	stack<int> s;
	s.push(1);
	vis[1] = true;
	while (!s.empty())
	{
		auto cur = s.top(); s.pop();
		for (auto nxt : adj[cur])
		{
			if (vis[nxt] == true) continue;
			vis[nxt] = true;
			s.push(nxt);
		}
	}

}

void dfs_recursion(int cur)
{
	vis[cur] = true;
	cout << cur << " ";
	for (auto nxt : adj[cur])
	{
		if (vis[nxt]) continue;
		dfs_recursion(nxt);
	}
}