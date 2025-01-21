// 1차원 bfs

#include <iostream>
#include <queue>
using namespace std;

int dist[100001];

int main()
{
	int n, k;
	cin >> n >> k;

	fill(dist, dist + 100001, -1);
	dist[n] = 0; // 최초 수빈이의 위치

	queue<int> q;
	q.push(n);

	while (dist[k] == -1)
	{
		auto cur = q.front(); q.pop();
		for (int pos : {cur - 1, cur + 1, cur * 2})
		{
			if (pos < 0 || pos > 100000) continue;
			if (dist[pos] != -1) continue;
			dist[pos] = dist[cur] + 1;
			q.push(pos);
		}
	}

	cout << dist[k] << "\n";
	return 0;
}