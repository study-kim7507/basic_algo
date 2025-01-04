// 12851. 숨바꼭질 2
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, k;
int dist[100001];

int result = 0;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;

	fill(dist, dist + 100001, 987654321);
	
	queue<int> q;
	q.push(n);
	dist[n] = 0;

	
	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		for (auto nxt : { cur - 1, cur + 1, cur * 2 })
		{
			if (nxt < 0 || nxt > 100000) continue;
			if (dist[nxt] < dist[cur] + 1) continue;
			else if (nxt == k && dist[nxt] > dist[cur] + 1) result = 1;
			else if (nxt == k && dist[nxt] == dist[cur] + 1) result++;

			q.push(nxt);
			dist[nxt] = dist[cur] + 1;
		}
	}
	

	cout << dist[k] << "\n";
	
	if (dist[k] == 0) cout << 1 << "\n";
	else cout << result << "\n";
	return 0;
}