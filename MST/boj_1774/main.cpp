#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>
#include <math.h>
using namespace std;

#define X first
#define Y second

int n, m;
int parent[1001];

// [정점1][정점2] 가 이미 연결되어 있는지
bool isAlready[1001][1001];

// 황선자를 포함한 우주신들의 좌표를 저장
pair<int, int> pos[1001];	

// {거리, 정점1, 정점2}
vector<tuple<long double, int, int>> dist;

int uf_find(int x)
{
	if (parent[x] != x)
		return parent[x] = uf_find(parent[x]);
	return x;
}

void uf_union(int x, int y)
{
	int a = uf_find(x);
	int b = uf_find(y);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		int x, y;
		cin >> x >> y;
		pos[i] = { x, y };
		parent[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		isAlready[u][v] = isAlready[v][u] = true;
		uf_union(u, v);
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			auto pos1 = pos[i];
			auto pos2 = pos[j];
			long double d = sqrt(
				pow(double(pos1.X) - double(pos2.X), 2) +
				pow(double(pos1.Y) - double(pos2.Y), 2)
			);
			dist.push_back({ round(d * 100) / 100.0, i, j });
			dist.push_back({ round(d * 100) / 100.0, j, i });
		}
	}

	sort(dist.begin(), dist.end());
	long double ans = 0.0;
	int cnt = 0;
	for (int i = 0; i < dist.size(); i++)
	{
		int u, v;
		long double d;
		tie(d, u, v) = dist[i];
		if (uf_find(u) == uf_find(v)) continue;
		uf_union(u, v);
		if (!isAlready[u][v]) ans += d;
		cnt++;
		if (cnt == n - 1) break;
	}

	cout << fixed;
	cout.precision(2);
	cout << ans << "\n";
	return 0;
}