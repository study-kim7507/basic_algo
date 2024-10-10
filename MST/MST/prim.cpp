// 신장 트리 : 방향성이 없는 그래프의 부분 그래프들 중에서 모든 정점을 포함하는 트리
// 모든 정점을 포함하는 서브 그래프 중 '사이클이 없는'(트리) 그래프
// 트리의 성질에 따라 정점이 V개이면 간선은 V - 1

// 최소 신장 트리 : 신장 트리 중, 간선의 합이 최소인 신장 트리
	// 여러 개일 수 있음

// 프림 알고리즘
	// 1. 임의의 정점을 선택해 최소 신장 트리에 추가
	// 2. 최소 신장 트리에 포함된 정점과 최소 신장 트리에 포함되지 않은 정점을 연결하는 간선 중 비용이 가장 작은 것을 최소 신장 트리에 추가
		// 모든 간선을 순회하면서 비용이 가장 작은 것을 찾는 것은 비효율적
		// -> 우선순위 큐(priority_queue, min heap)을 이용해서 
	// 3. 최소 신장 트리에 V-1개의 간선이 추가될 때 까지 2번 과정을 반복

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

#define X first
#define Y second

int main()
{
	int v, e;
	// {비용, 정점 번호}
	vector<pair<int, int>> adj[10005];
	bool chk[10005];				// chk[i] : i번쨰 정점이 최소 신장 트리에 속해있는가?
	int cnt = 0;

	// {비용, 정점1, 정점2}
	// 비용을 기준 min heap (우선순위 큐)
	priority_queue < tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

	chk[1] = 1;
	for (auto nxt : adj[1])
		pq.push({ nxt.X, 1, nxt.Y });

	while (cnt < v - 1)
	{
		int cost, a, b;
		tie(cost, a, b) = pq.top(); pq.pop();
		if (chk[b]) continue;
		cout << cost << " " << a << " " << b << "\n";
		chk[b] = 1;
		cnt++;
		for (auto nxt : adj[b])
			if (!chk[nxt.Y])
				pq.push({ nxt.X, b, nxt.Y });
	}
}