// BOJ 13913. 숨바꼭질 4
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int dist[200001];
int previous[200001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k;

	dist[n] = 1;
	previous[n] = -1;

	queue<int> q;
	q.push(n);

	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		for (auto nxt : { cur - 1, cur + 1, 2 * cur })
		{
			if (nxt < 0 || nxt >= 200000) continue;
			if (dist[nxt] != 0 && dist[nxt] <= dist[cur] + 1) continue;

			dist[nxt] = dist[cur] + 1;
			previous[nxt] = cur;
			q.push(nxt);
		}
	}

	std::cout << dist[k] - 1 << "\n";
	
	vector<int> path;

	int cur = k;
	while (cur != -1)
	{
		path.push_back(cur);
		cur = previous[cur];
	}

	reverse(path.begin(), path.end());
	for (auto e : path)
		std::cout << e << " ";

	return 0;
}