#include <iostream>
#include <limits>
using namespace std;

int n, m;
int dist[101][101];
const int INF = 987654321;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		fill(dist[i] + 1, dist[i] + n + 1, INF);
		dist[i][i] = 0;
	}
		

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		dist[a][b] = min(dist[a][b], c);
	}

	// floyd warshall
	for (int k = 1; k <= n; k++)
		for (int st = 1; st <= n; st++)
			for (int en = 1; en <= n; en++)
				dist[st][en] = min(dist[st][k] + dist[k][en], dist[st][en]);


	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (dist[i][j] == INF) cout << 0 << " ";
			else cout << dist[i][j] << " ";
		}
		cout << "\n";
	}
			
	return 0;
}