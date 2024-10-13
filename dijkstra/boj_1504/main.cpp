// 1 -> v1 -> v2 -> n
// 1 -> v2 -> v1 -> n
// 두 가지 경로에서 최단 경로
// 플로이드 워셜 or 다익스트라

#include <iostream>
#include <queue>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

int n, e, v1, v2;
int d[801][801];
const int INF = 123456789;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> e;
	for (int i = 0; i <= n; i++)
	{
		fill(d[i], d[i] + n + 1, INF);
		d[i][i] = 0;
	}
	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		d[a][b] = d[b][a] = c;
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

	cin >> v1 >> v2;
	long long path1 = d[1][v1] + d[v1][v2] + d[v2][n];
	long long path2 = d[1][v2] + d[v2][v1] + d[v1][n];
	
	long long result = min(path1, path2);

	if (result >= INF) cout << -1 << "\n";
	else cout << result << "\n";
	return 0;
}