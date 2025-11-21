// BOJ 17835. 면접보는 승범이네
#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


int n, m, k;
vector<pair<int, int>> roads[100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> k;
	
	for (int i = 0; i < m; i++)
	{
		int u, v, c;
		cin >> u >> v >> c;
		roads[v].push_back(make_pair(c, u));
	}

	vector<long long> dist(n + 1, LLONG_MAX);
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

	for (int i = 0; i < k; i++)
	{
		int u;
		cin >> u;
		dist[u] = 0;
		pq.push(make_pair(dist[u], u));
	}

	while (!pq.empty())
	{
		long long curDist = pq.top().first;
		int curCity = pq.top().second;
		pq.pop();

		if (dist[curCity] != curDist) continue;
		for (auto nxt : roads[curCity])
		{
			long long nxtDist = nxt.first;
			int nxtCity = nxt.second;

			if (dist[nxtCity] <= curDist + nxtDist) continue;

			dist[nxtCity] = curDist + nxtDist;
			pq.push(make_pair(dist[nxtCity], nxtCity));
		}
	}

	long long maxDist = 0;
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (maxDist < dist[i])
		{
			maxDist = dist[i];
			ans = i;
		}
	}
	std::cout << ans << "\n";
	std::cout << maxDist << "\n";
	return 0;
}