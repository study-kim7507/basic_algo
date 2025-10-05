#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;

		int tcost[1001];
		for (int i = 1; i <= n; i++)
			cin >> tcost[i];

		int indegree[1001];
		vector<int> adj[1001];
		fill(indegree, indegree + 1001, 0);
		for (int i = 0; i < k; i++)
		{
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			indegree[v]++;
		}

		// {누적 소요 시간, 건물 번호} 
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		for (int i = 1; i <= n; i++)
			if (indegree[i] == 0) pq.push({ tcost[i], i });
	
		int result[1001];
		while (!pq.empty())
		{
			auto cur = pq.top(); pq.pop();
			result[cur.second] = cur.first;
			for (int nxt : adj[cur.second])
				if (--indegree[nxt] == 0) pq.push({ cur.first + tcost[nxt], nxt });
		}
		int w;
		cin >> w;
		cout << result[w] << "\n";
	}
	return 0;
}