// 플로이드 워셜 경로복원 문제
#include <iostream>
#include <vector>
using namespace std;

int n, m;
int dist[101][101];
int nxt[101][101];

const int INF = 987654321;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		fill(dist[i] + 1, dist[i] + 1 + n, INF);
		dist[i][i] = 0;
	}

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (dist[a][b] > c)
		{
			dist[a][b] = c;
			nxt[a][b] = b;
		}
	}
		
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (dist[i][k] + dist[k][j] < dist[i][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
					nxt[i][j] = nxt[i][k];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (dist[i][j] == INF) cout << 0 << " ";
			else cout << dist[i][j] << " ";
		}
		cout << "\n";
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (nxt[i][j] == 0)
			{
				cout << 0 << "\n";
				continue;
			}
			vector<int> route;
			int k = i;
			route.push_back(i);
			while (nxt[k][j] != j)
			{
				k = nxt[k][j];
				route.push_back(k);
			}
			route.push_back(j);

			cout << route.size() << " ";
			for (const int& element : route)
				cout << element << " ";
			cout << "\n";
		}
	}

	return 0;
}