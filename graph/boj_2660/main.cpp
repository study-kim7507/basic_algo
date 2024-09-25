

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> adj[51];
int dist[51];

int score[51];				

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	while(true)
	{
		int u, v;
		cin >> u >> v;
		if (u == -1 && v == -1) break;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= n; i++)
	{
		int ans = 0;
		fill(dist, dist + n + 1, -1);

		queue<int> q;
		q.push(i);
		dist[i] = 0;
		while (!q.empty())
		{
			auto cur = q.front(); q.pop();
			for (auto nxt : adj[cur])
			{
				if (dist[nxt] != -1) continue;
				dist[nxt] = dist[cur] + 1;
				if (ans < dist[nxt]) ans = dist[nxt];
				q.push(nxt);
			}
		}
		score[i] = ans;
	}


	int min_score = 987654321;
	for (int i = 1; i <= n; i++)
		if (min_score > score[i]) min_score = score[i];

	int cnt = 0;
	vector<int> idx;
	for (int i = 1; i <= n; i++)
	{
		if (score[i] == min_score)
		{
			cnt++;
			idx.push_back(i);
		}
	}
		
	cout << min_score << " " << cnt << "\n";
	for (const auto& e : idx)
		cout << e << " ";

	return 0;
}