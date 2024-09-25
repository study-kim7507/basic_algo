#include <iostream>
#include <queue>
using namespace std;

int visit[100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	fill(visit, visit + 100001, -1);

	// 수빈이의 위치
	queue<int> q;
	q.push(n);
	visit[n] = 0;

	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		for (int nxt : {cur - 1, cur + 1, cur * 2})
		{
			if (nxt < 0 || nxt > 100000) continue;
			// if (visit[nxt] != -1) continue;
			if (nxt == cur * 2)
			{
				if (visit[nxt] <= visit[cur])
				{
					visit[nxt] = visit[cur];
					q.push(nxt);
				}
				
			}
			else
			{
				if (visit[nxt] <= visit[cur])
				{
					visit[nxt] = visit[cur] + 1;
					q.push(nxt);
				}
			}
		}
	}
	cout << visit[k] << "\n";
	return 0;
}