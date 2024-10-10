#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, r;
int items[101];				// 각 지역에 존재하는 아이템의 수를 저장
int dist[101][101];			// 모든 지역 사이의 최단거리를 계산

const int INF = 987654321;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> r;	
	for (int i = 1; i <= n; i++)
	{
		fill(dist[i], dist[i] + n + 1, INF);
		dist[i][i] = 0;
	}
		
	for (int i = 1; i <= n; i++)
		cin >> items[i];

	for (int i = 0; i < r; i++)
	{
		int a, b, l;
		cin >> a >> b >> l;
		dist[a][b] = min(dist[a][b], l);
		dist[b][a] = min(dist[b][a], l);
	}

	// floyd-warshall
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
		
	int result = 0;
	for (int i = 1; i <= n; i++)
	{
		int tmpResult = 0;
		for (int j = 1; j <= n; j++)
		{
			if (dist[i][j] <= m) tmpResult += items[j];
		}
		result = max(result, tmpResult);
	}

	cout << result << "\n";

	return 0;
}