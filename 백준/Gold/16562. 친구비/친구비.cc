// BOJ_16562. 친구비
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int cost[10001];
int parent[10001];

int uf_find(int x)
{
	if (x != parent[x]) return parent[x] = uf_find(parent[x]);
	return x;
}

void uf_union(int x, int y)
{
	x = uf_find(x);
	y = uf_find(y);

	if (cost[x] < cost[y]) parent[y] = x;
	else parent[x] = y;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
		cin >> cost[i];
	}

	for (int i = 0; i < m; i++)
	{
		int v, w;
		cin >> v >> w;
		uf_union(v, w);
	}
	
	int answer = 0;
	for (int i = 1; i <= n; i++)
	{
		if (uf_find(0) != uf_find(i))
		{
			answer += cost[uf_find(i)];
			uf_union(0, i);
		}
	}

	if (answer > k) std::cout << "Oh no" << "\n";
	else std::cout << answer << "\n";
	return 0;
}