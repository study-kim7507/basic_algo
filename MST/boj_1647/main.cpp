#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int n, m;
vector<tuple<int, int, int>> edges;
int parent[100001];

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
		parent[i] = i;

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edges.push_back({ c, a, b });
		edges.push_back({ c, b, a });
	}

	sort(edges.begin(), edges.end());

	int cnt = 0;
	long long ans = 0;
	for (int i = 0; i < edges.size(); i++)
	{
		int a, b, c;
		tie(c, a, b) = edges[i];
		if (uf_find(a) == uf_find(b)) continue;
		uf_union(a, b);
		ans += c;
		cnt++;
		if (cnt == n - 1)
		{
			ans -= c;
			break;
		}
	}

	cout << ans << "\n";
	return 0;
}