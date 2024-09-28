// 특정 노드들의 대소관계가 주어지고 순서대로 정렬 -> 위상 정렬
// queue를 이용하여 매 시점 노드가 제거될 때, indegree가 0이되는 노드를 queue에 추가해서 정렬
// 해당 문제는 indegree 0인 문제들 중, 쉬운 문제, 즉 번호가 작은 노드들을 먼저 정렬에 포함 시켜야 함 -> min heap을 이용
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> adj[32001];
int indegree[32001];

vector<int> result;

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
		indegree[v]++;
	}

	// min heap 이용
	priority_queue<int, vector<int>, greater<>> zero;
	for (int i = 1; i <= n; i++)
		if (indegree[i] == 0) zero.push(i);
	
	while (!zero.empty())
	{
		auto cur = zero.top(); zero.pop();
		result.push_back(cur);
		for (auto nxt : adj[cur])
			if (--indegree[nxt] == 0) zero.push(nxt);
	}

	for (const int& element : result)
		cout << element << " ";
	cout << "\n";

	return 0;
}
