// 위상 정렬 : '방향 그래프'(DAG) 에서 간선으로 주어진 정점 간 선후관계를 위배하지 않도록 나열하는 정렬 

// 사이클이 존재하는 경우, 올바른 위상 정렬이 존재할 수 없음
// 위상 정렬을 수행했음에도 모든 노드가 정렬 결과에 포함되지 않는 경우 -> 사이클이 있음을 알 수 있다
 
// 정렬의 결과가 여러 개 존재할 수 있음

// 정점과 간선을 실제로 지울 필요 없이 미리 Indegree의 값을 저장했다가 매번 뻗어나가는 정점들의 Indegree 값만 1감소 시켜도 된다
// Indegree가 0인 정점을 구하기 위해 매번 모든 정점들을 다 확인하는 대신 목록을 따로 저장하고 있다가 직전에 제거한 정점에서 연결된 정점들만 추가

// 1. 맨 처음 모든 간선을 읽으며 Indegree 테이블을 채움
// 2. Indegree가 0인 정점들을 모두 큐에 넣음
// 3. 큐에서 정점을 꺼내어 위상 정렬 결과에 추가
// 4. 해당 정점으로부터 연결된 모든 정점의 Indegree 값을 1 감소시킴 이 때, Indegree가 0이 되었다면 그 정점을 큐에 추가
// 5. 큐가 빌 때까지 3, 4번 반복


/* Example
1 2
3 2
3 4
4 2
4 5
5 6
7 5
*/

// 원소 간의 선후 관계가 주어지고 순서를 정해야 한다 -> 위상정렬

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int n = 7;
vector<int> adj[10];

int indegree[10];
queue<int> zero;

vector<int> result;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int i = 0; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		indegree[v]++;
	}

	for (int i = 1; i <= n; i++)
	{
		if (indegree[i] == 0) zero.push(i);
		// cout << indegree[i] << " ";
	}
	
	while (!zero.empty())
	{
		auto cur = zero.front(); zero.pop();
		result.push_back(cur);

		for (auto nxt : adj[cur])
			if (-- indegree[nxt] == 0) zero.push(nxt);
	}

	if (result.size() != n) cout << "cycle exists" << "\n";
	else
	{
		for (const int& element : result)
			cout << element << " ";
	}
	return 0;
}

