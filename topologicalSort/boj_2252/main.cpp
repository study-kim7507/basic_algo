// 학생 A가 학생 B의 앞에 서야한다
	// 위상 정렬, A->B

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;					// 학생의 수, 키를 비교한 횟수
vector<int> adj[32001];

int indegree[32001];
queue<int> zero;

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

	for (int i = 1; i <= n; i++)
		if (indegree[i] == 0) zero.push(i);


	while (!zero.empty())
	{
		int cur = zero.front(); zero.pop();
		if (indegree[cur] == 0) result.push_back(cur);

		for (auto nxt : adj[cur])
			if (--indegree[nxt] == 0) zero.push(nxt);
	}

	for (const int& element : result)
		cout << element << " ";

	return 0;
}