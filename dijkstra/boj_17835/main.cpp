// 반대로, 면접장에서 각 도시로의 최단거리를 구하면 된다. 
	// 입력을 반대로 받아야함
// k개의 면접장을 시작점으로 다익스트라

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

int n, m, k;

// {거리, 정점}
vector<pair<long long, int>> adj[100001];
long long d[100001];
const long long INF = numeric_limits<long long>::max();

bool cmp(const pair<long long, int>& a, const pair<long long, int>& b)
{
	if (a.first > b.first) return a.first > b.first;
	else if (a.first == b.first) return a.second < b.second;
	return false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < m; i++)
	{
		int u, v, c;
		cin >> u >> v >> c;				// u -> v : c
		adj[v].push_back({ c, u });
	}

	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
	
	fill(d, d + n + 1, INF);
	for (int i = 0; i < k; i++)
	{
		int n;
		cin >> n;
		pq.push({ 0, n });
		d[n] = 0;
	}

	while (!pq.empty())
	{
		auto cur = pq.top(); pq.pop();
		if (d[cur.second] < cur.first) continue;
		for (auto nxt : adj[cur.second])
		{
			if (d[nxt.second] < d[cur.second] + nxt.first) continue;
			d[nxt.second] = d[cur.second] + nxt.first;
			pq.push({ d[nxt.second], nxt.second,  });
		}
	}

	// {거리, 도시번호}
	vector<pair<long long, int>> enDist;					
	for (int i = 1; i <= n; i++)
		enDist.push_back({ d[i], i });
	
	sort(enDist.begin(), enDist.end(), cmp);

	cout << enDist[0].second << "\n" << enDist[0].first << "\n";

	return 0;
}