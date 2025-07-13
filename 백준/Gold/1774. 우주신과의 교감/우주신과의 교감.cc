// BOJ_1774. 우주신과의 교감
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

#define X first
#define Y second

int n, m;
pair<int, int> pos[1001];
vector<pair<double, pair<int, int>>> v;

int parent[1001];

int uf_find(int x)
{
	if (x != parent[x]) return parent[x] = uf_find(parent[x]);
	return x;
}

void uf_union(int x, int y)
{
	x = uf_find(x);
	y = uf_find(y);

	if (x <= y) parent[y] = x;
	else parent[x] = y;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		parent[i] = i;

	for (int i = 1; i <= n; i++)
	{
		int x, y;
		cin >> x >> y;
		pos[i] = { x, y };
	}

	int cnt = 0;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		if (uf_find(a) != uf_find(b))
		{
			uf_union(a, b);
			cnt++;
		}
	}
	
	for (int i = 1; i <= n - 1; i++)
	{
		auto a = pos[i];
		for (int j = i + 1; j <= n; j++)
		{
			auto b = pos[j];

			double d = sqrt(pow(a.X - b.X, 2) + pow(a.Y - b.Y, 2));
			v.push_back({ d, {i, j} });
		}
	}

	sort(v.begin(), v.end());

	double ans = 0;
	for (auto e : v)
	{
		double d = e.first;
		int curIdx1 = e.second.first;
		int curIdx2 = e.second.second;

		if (uf_find(curIdx1) != uf_find(curIdx2))
		{
			uf_union(curIdx1, curIdx2);
			ans += d;
			cnt++;
		}

		if (cnt == n - 1) break;
	}
	
	ans = round(ans * 1000) / 1000;
	std::cout << fixed;
	std::cout.precision(2);
	std::cout << ans << "\n";
	return 0;
}