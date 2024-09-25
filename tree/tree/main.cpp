// 트리 또한 간선과 정점으로 이루어진 자료구조, 그래프의 특별한 종류
// 제일 꼭대기의 정점은 루트, 간선으로 직접 연결된 상하 정점을 부모와 자식이라고 한다
// 자식이 없는 노드는 리프 노드
// Depth : 루트와의 거리

// 트리 
	// 무방향이면서 사이클이 없는 연결 그래프
	// 연결 그래프이면서 임의의 간선을 제거하면 연결 그래프가 아니게 되는 그래프
	// 임의의 두 점을 연결하는 simple path가 유일한 그래프
	// V개의 정점을 가지고 V-1개의 간선을 가지는 연결 그래프
	// 사이클이 없는 연결 그래프이면서 임의의 간선을 추가하면 사이클이 생기는 그래프
	// V개의 정점을 가지고 V-1개의 간선을 가지는 사이클이 없는 그래프 

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

vector<int> adj[10];
int p[10];				// 부모 노드 번호 저장
int depth[10];

void bfs(int root)
{
	queue<int> q;
	q.push(root);
	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		cout << cur << "\n";
		for (int nxt : adj[cur])
		{
			if (p[cur] == nxt) continue;
			q.push(nxt);
			p[nxt] = cur;
			depth[nxt] = depth[cur] + 1;
		}
	}
}

void dfs(int root)
{
	stack<int> s;
	s.push(root);
	while (!s.empty())
	{
		auto cur = s.top(); s.pop();
		for (auto nxt : adj[cur])
		{
			if (p[nxt] == cur) continue;
			s.push(nxt);
			p[nxt] = cur;
			depth[nxt] = depth[cur] + 1;
		}

	}
}

void dfs_recursion(int cur)
{
	cout << cur << " ";
	for (int nxt : adj[cur])
	{
		if (p[nxt] == cur) continue;
		p[nxt] = cur;
		depth[nxt] = depth[cur] + 1;
		dfs_recursion(nxt);
	}
}

// 이진 트리에서의 순회
int lc[9] = { 0, 2, 4, 6, 0, 0, 0, 0, 0 };
int rc[9] = { 0, 3, 5,  7, 0, 8, 0, 0, 0 };

// 전위 순회 : 현재 -> 왼쪽 서브트리 전위 순회 -> 오른쪽 서브트리 전위 순회
void preorder(int cur)
{
	cout << cur << " ";
	if (lc[cur] != 0) preorder(lc[cur]);
	if (rc[cur] != 0) preorder(rc[cur]);
}

// 중위 순회 : 왼쪽 서브트리 중위 순회 -> 현재 -> 오른쪽 서브트리 중위 순회
void inorder(int cur)
{
	if (lc[cur] != 0) inorder(lc[cur]);
	cout << cur << " ";
	if (rc[cur] != 0) inorder(rc[cur]);
}

// 후위 순회 : 왼쪽 서브트리 후위 순회 -> 오른쪽 서브트리 후위 순회 -> 현재
void postorder(int cur)
{
	if (lc[cur] != 0) postorder(lc[cur]);
	if (rc[cur] != 0) postorder(rc[cur]);
	cout << cur << " ";
}