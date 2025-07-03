// BOJ_13549. 숨바꼭질 3
#include <iostream>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

int n, k;
int dist[200001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	fill(dist, dist + 200001, INT_MAX);
	cin >> n >> k;
	
	queue<int> q;
	q.push(n);
	dist[n] = 0;
	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		for (auto nxt : { cur - 1, cur + 1, cur * 2 })
		{
			if (nxt < 0 || nxt >= 200001) continue;
			if (dist[nxt] <= dist[cur]) continue;

			if (nxt != cur * 2) dist[nxt] = dist[cur] + 1;
			else dist[nxt] = dist[cur];

			q.push(nxt);
		}
	}

	std::cout << dist[k] << "\n";

	return 0;
}