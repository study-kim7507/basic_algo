// BOJ_10423. 전기가 부족해
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k;
int parent[1001];
vector<pair<int, pair<int, int>>> edges;

int uf_find(int x)
{
	if (x != parent[x]) return parent[x] = uf_find(parent[x]);
	return x;
}

void uf_union(int x, int y)
{
	x = uf_find(x);
	y = uf_find(y);

	if (x < y) parent[y] = x;
	else parent[x] = y;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i <= n; i++)
		parent[i] = i;
	for (int i = 0; i < k; i++)
	{
		int num;
		cin >> num;
		parent[num] = 0;
	}
	for (int i = 0; i < m; i++)
	{
		int	u, v, w;
		cin >> u >> v >> w;
		edges.push_back({ w, {u, v} });
		edges.push_back({ w, {v, u} });
	}

	sort(edges.begin(), edges.end());

	int cnt = k;
	int answer = 0;
	for (auto edge : edges)
	{
		if (uf_find(edge.second.first) != uf_find(edge.second.second))
		{
			uf_union(edge.second.first, edge.second.second);
			cnt++;
			answer += edge.first;

			if (cnt == n) break;
		}
	}

	std::cout << answer << "\n";
	return 0;
}