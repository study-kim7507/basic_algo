// BOJ_1368. 물대기
// 각 논에서 우물을 파는 비용을 하나의 논이 더 있다고 생각하고,
// 해당 논과의 연결 비용으로 간주하여 최소 신장 트리를 구하면
// 최소 비용을 구할 수 있다.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int N;
int w[100001];
int parent[10001];
struct Edge
{
	int a;
	int b;
	int c;

	bool operator<(const Edge& a)
	{
		return a.c > c;
	}
};

vector<Edge> edges;

void init()
{
	for (int i = 1; i <= N; i++)
	{
		parent[i] = i;
	}
}

int find(int a)
{
	if (parent[a] == a) return a;
	parent[a] = find(parent[a]);
	return parent[a];
}

void uni(int a, int b)
{
	int aRoot = find(a);
	int bRoot = find(b);
	if (aRoot <= bRoot) parent[bRoot] = aRoot;
	else parent[aRoot] = bRoot;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	init();
	// 논의 우물을 파는데 드는 비용
	for (int i = 1; i <= N; i++)
	{
		int cost;
		cin >> cost;
		w[i] = cost;
	}


	// 논을 연결하는데 드는 비용
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int p;
			cin >> p;
			if (i > j) edges.push_back({ i, j, p });
		}
	}

	// 우물을 파는 비용을 하나의 논이 더 있다고 생각
	// 해당 논과 연결하는 간선으로 생각하여 edges에 추가.
	for (int i = 1; i <= N; i++)
	{
		edges.push_back({ 0, i, w[i] });
	}

	// 크루스칼 알고리즘을 위한 정렬
	sort(edges.begin(), edges.end());

	ll ans = 0;
	for (int i = 0; i < edges.size(); i++)
	{
		auto curr = edges[i];
		if (find(curr.a) == find(curr.b))
			continue;
		uni(curr.a, curr.b);
		ans += curr.c;
	}

	cout << ans << "\n";
	return 0;
}