// 플로이드 워셜 풀이
#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
using namespace std;

int n, m, x;
int d[1001][1001];
const int INF = 0x3f3f3f3f;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> x;
	for (int i = 0; i <= n; i++)
	{
		fill(d[i], d[i] + n + 1, INF);
		d[i][i] = 0;
	}

	for (int i = 0; i < m; i++)
	{
		int u, v, t;
		cin >> u >> v >> t;
		d[u][v] = t;
	}

	// floyd-warshall
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

	int result = numeric_limits<int>::min();
	for (int i = 1; i <= n; i++)
		result = max(result, d[i][x] + d[x][i]);

	cout << result << "\n";
	return 0;
}