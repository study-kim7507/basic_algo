// A->B로 가는 데 드는 최소비용과 경로
// n이 최대 1000, 플로이드 워셜 불가능
// 다익스트라

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, st, en;

// {비용, 정점}
vector<pair<int, int>> adj[1001];
const int INF = 0x3f3f3f3f;

int d[1001];							// 비용 저장
int pre[1001];							// 경로 저장

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ w, v });
	}
	
	cin >> st >> en;					// 시작점, 도착점

	fill(d, d + n + 1, INF);
	d[st] = 0;
	pre[st] = st;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ d[st], st });

	// {비용, 정점}
	while (!pq.empty())
	{
		auto cur = pq.top(); pq.pop();
		if (d[cur.second] != cur.first) continue;
		for (auto nxt : adj[cur.second])
		{
			if (d[nxt.second] <= d[cur.second] + nxt.first) continue;
			d[nxt.second] = d[cur.second] + nxt.first;
			pre[nxt.second] = cur.second;
			pq.push({ d[nxt.second], nxt.second });
		}
	}

	vector<int> path;
	for (int i = en; i != st; )
	{
		path.push_back(i);
		i = pre[i];
	}
	path.push_back(st);

	reverse(path.begin(), path.end());

	cout << d[en] << "\n" << path.size() << "\n";
	for (const int& element : path)
		cout << element << " ";
	return 0;
}