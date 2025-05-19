// BOJ_1967. 트리의 지름
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<pair<int, int>> adj[10001];

int answer = -1;
void bfs(int st)
{
	vector<int> dist(n + 1, -1);

	queue<int> q;
	q.push(st);
	dist[st] = 0;

	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		for (auto nxt : adj[cur])
		{
			if (dist[nxt.first] != -1) continue;

			dist[nxt.first] = (dist[cur] + nxt.second);
			q.push(nxt.first);
		}
	}

	answer = max(answer, *max_element(dist.begin(), dist.end()));
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b, c });
		adj[b].push_back({ a, c });
	}

	for (int i = 1; i <= n; i++)
		bfs(i);

	std::cout << answer << "\n";
	return 0;
}