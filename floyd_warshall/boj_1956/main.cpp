// 플로이드 워셜로 모든 정점 사이의 최단 거리를 구한 뒤
// 가능한 두 정점 사이의 왕복 최단 거리가 짧은 것을 결과로 반환
// 만약 모든 두 정점 사이가 왕복이 불가능하다면 -1을 반환

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

int v, e;
int dist[401][401];				// 최단 거리
const int INF = 987654321;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> v >> e;
	for (int i = 0; i <= v; i++)
	{
		fill(dist[i], dist[i] + v + 1, INF);
		dist[i][i] = 0;
	}
		
	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		dist[a][b] = c;			// 같은 도로가 여러 번 주어지지 않음
	}

	// 플로이드 워셜
	for (int k = 1; k <= v; k++)
		for (int i = 1; i <= v; i++)
			for (int j = 1; j <= v; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	int ans = numeric_limits<int>::max();
	// i -> j -> i로 왕복하는 도로의 길이의 합이 최소가 되는 경우를 찾기 위함
	// O(v^2)
	for (int i = 1; i <= v; i++)
	{
		for (int j = 1; j <= v; j++)
		{
			if (i == j) continue;
			ans = min(ans, dist[i][j] + dist[j][i]);
		}
	}

	if (ans >= INF) cout << -1 << "\n";
	else cout << ans << "\n";
	return 0;
}