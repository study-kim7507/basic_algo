// 1922. 네트워크 연결
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

int parent[1001];

int uf_find(int x)
{
	if (x != parent[x]) return uf_find(parent[x]);
	return parent[x];
}

void uf_union(int x, int y)
{
	int a = uf_find(x);
	int b = uf_find(y);

	if (x < y) parent[b] = a;
	else parent[a] = b;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		parent[i] = i;

	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		pq.push(tie(c, a, b));
	}

	int count = 0;
	int result = 0;
	while (!pq.empty())
	{
		auto cur = pq.top(); pq.pop();

		if (uf_find(get<1>(cur)) != uf_find(get<2>(cur)))
		{
			uf_union(get<1>(cur), get<2>(cur));
			result += get<0>(cur);
			count++;
		}

		if (count == n - 1) break;
	}

	cout << result << "\n";
	return 0;
}