// n개의 별들을 잇는 최소 비용을 구하는 문제
// 모든 정점을 잇는 최단 거리 -> 최소 신장 트리
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <tuple>
using namespace std;

int n;
int parent[101];

// {비용, 정점1, 정점2}
vector<tuple<double, int, int>> edges;
vector<pair<double, double>> vertex;

int uf_find(int x)
{
	if (x != parent[x])
		return parent[x] = uf_find(parent[x]);
	return x;
}

void uf_union(int x, int y)
{
	int a = uf_find(x);
	int b = uf_find(y);

	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}

double getDistance(const pair<double, double>& u, const pair<double, double>& v)
{
	return sqrt(pow(u.first - v.first, 2) + pow(u.second - v.second, 2));
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		double x, y;
		cin >> x >> y;
		vertex.push_back({ x, y });
	}

	for (int i = 0; i < n; i++)
	{
		auto u = vertex[i];
		for (int j = i + 1; j < n; j++)
		{
			auto v = vertex[j];
			edges.push_back({ getDistance(u, v), i, j });
		}
	}

	for (int i = 0; i <= n; i++)
		parent[i] = i;

	sort(edges.begin(), edges.end());
	
	int cnt = 0;
	float ans = 0;
	for (int i = 0; i < edges.size(); i++)
	{
		float cost;
		int u, v;
		tie(cost, u, v) = edges[i];
		if (uf_find(u) == uf_find(v)) continue;
		uf_union(u, v);
		ans += cost;
		if (cnt++ == n - 1) break;
	}

	cout << ans << "\n";
	return 0;
}