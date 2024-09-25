// �׷��� = ������ �������� �̷���� �ڷᱸ��
	// ���� : �������� ����� ������ ����
	// ������ �׷���	(degree), ���� �׷��� (indegree, outdegree)
	// ��ȯ �׷���, ���ȯ �׷���
	// ���� �׷���, ���� �׷���
		// ���� �׷��� : ��� ���� �ٸ� �� ���� ���� �������� ����� �׷���
		// ���� �׷��� : ������ �� ���� ���̿� ��ΰ� �׻� �����ϴ� �׷���


#include <iostream>
#include <algorithm> 
#include <queue>
#include <vector>
#include <stack>
using namespace std;

// ǥ����1 : �������
void adj_matrix_ex()
{
	int adj_matrix[10][10] = {};			// O(V^2)�� �������⵵
	int v, e;
	cin >> v >> e;
	for (int i = 0; i < e; i++)
	{
		int u, v;
		cin >> u >> v;					
		adj_matrix[u][v] = 1;				// u��忡�� v���� ���� ���� - ���� �׷���
		adj_matrix[v][u] = 1;				// v��忡�� u���� ���� ���� - ������ �׷���
	}
}

// ǥ����2 : ��������Ʈ
void adj_list_ex()
{
	vector<int> adj[10];					// O(V + E)
	int v, e;
	cin >> v >> e;
	for (int i = 0; i < e; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);				// u��忡�� v���� ���� ���� - ���� �׷���
		adj[v].push_back(u);				// v��忡�� u���� ���� ���� - ������ �׷���
	}
}

// BFS = �׷������� �ʺ� �켱���� �湮�ϴ� �˰���
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
		for (auto nxt : adj[cur])			// ���� ������ �������� ����� ��� ������ ��ȸ
		{
			if (vis[nxt]) continue;			// �̹� �湮�� ����
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
			if (dist[nxt] != -1) continue;	// �̹� �湮����
			dist[nxt] = dist[cur] + 1;
			q.push(nxt);
		}
	}
	
}

// DFS
// ��� DFS, ����� DFS�� �湮 ������ ���̰� ������
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