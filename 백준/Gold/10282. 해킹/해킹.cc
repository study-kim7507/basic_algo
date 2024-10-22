// 시작 정점에서 도달할 수 있는 모든 정점까지의 최단거리를 구함
// 가장 먼 정점의 번호와 거리를 출력
// 다익스트라

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

// {거리, 정점}
vector<pair<int, int>> adj[10001];
int dist[10001];
const int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int n, d, c;
		cin >> n >> d >> c;

		fill(adj, adj + n + 1, vector<pair<int, int>>());
		fill(dist, dist + n + 1, INF);

		for (int i = 0; i < d; i++)
		{
			int a, b, s;
			cin >> a >> b >> s;
			adj[b].push_back({ s, a });
		}

		priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		pq.push({ 0, c });
		dist[c] = 0;

		while (!pq.empty())
		{
			auto cur = pq.top(); pq.pop();
			if (dist[cur.second] != cur.first) continue;
			for (auto nxt : adj[cur.second])
			{
				if (dist[nxt.second] <= cur.first + nxt.first) continue;
				dist[nxt.second] = cur.first + nxt.first;
				pq.push({ dist[nxt.second], nxt.second });
			}
		}

		int cnt = 0;
		int time = 0;
		for (int i = 1; i <= n; i++)
		{
			if (dist[i] != INF)
			{
				cnt++;
				if (dist[i] > time) time = dist[i];
			}
		}
		cout << cnt << " " << time << "\n";
		
	}

	return 0;
}