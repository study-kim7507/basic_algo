// BOJ 1167. 트리의 지름
// 임의의 정점에서 시작해서 가장 먼 거리에 있는 정점을 구함
// 구해진 정점에서 가장 먼 거리에 있는 정점까지의 거리를 구함
// 총 2번의 DFS를 통해 트리의 지름을 구할 수 있음
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<vector<pair<int, int>>> edges;

int maxNode, maxDist;

void dfs(int curNode, int curDist, vector<bool>& visit)
{
	if (curDist >= maxDist)
	{
		maxNode = curNode;
		maxDist = curDist;
	}

	for (auto nxt : edges[curNode])
	{
		int nxtNode = nxt.first;
		int dist = nxt.second;

		if (visit[nxtNode]) continue;

		visit[nxtNode] = true;
		dfs(nxtNode, curDist + dist, visit);
		// visit[nxtNode] = false;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	edges = vector<vector<pair<int, int>>>(n + 1, vector<pair<int, int>>());
	for (int i = 0; i < n; i++)
	{
		int u;
		cin >> u;

		while (true)
		{
			int v, c;
			
			cin >> v;
			if (v == -1) break;

			cin >> c;
			edges[u].push_back({ v, c });
			edges[v].push_back({ u, c });
		}
	}

	vector<bool> visit(n + 1, false);
	visit[1] = true;
	dfs(1, 0, visit);

	maxDist = 0;
	fill(visit.begin(), visit.end(), false);
	visit[maxNode] = true;
	dfs(maxNode, 0, visit);

	std::cout << maxDist << "\n";

	return 0;
}