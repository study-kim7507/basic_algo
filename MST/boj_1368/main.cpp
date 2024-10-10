// 우물을 파는 것 -> 0번 노드와의 연결로 간주
// 모든 논에 물을 대는 것 -> 신장 트리
// 모든 논에 물을 댈 때 최소 비용으로 -> 최소 신장트리

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int n;
// {비용, 정점1, 정점2}
vector<tuple<int, int, int>> edges;
int parent[301];

// 유니온 파인드
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

	cin >> n;
	for (int i = 0; i <= n; i++)
		parent[i] = i;
	
	for (int i = 1; i <= n; i++)
	{
		int c;
		cin >> c;
		edges.push_back({ c, 0, i });
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int c;
			cin >> c;
			if (i == j) continue;
			edges.push_back({ c, i, j });
		}
	}
	
	// 비용을 기준으로 오름차순 정렬
	sort(edges.begin(), edges.end());
	int cnt = 0;
	int ans = 0;
	for (int i = 0; i < edges.size(); i++)
	{
		int cost, a, b;
		tie(cost, a, b) = edges[i];
		if (uf_find(a) == uf_find(b)) continue;
		uf_union(a, b);
		ans += cost;
		cnt++;
		if (cnt == n) break;
	}
	cout << ans << "\n";

	return 0;
}