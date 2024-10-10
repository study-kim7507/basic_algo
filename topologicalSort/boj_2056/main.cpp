// 순서가 정해진 정렬 -> 위상 정렬
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int indegree[10001];
int t[10001];			// 작업을 수행하는데 걸리는 시간


vector<int> adj[10001];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int cost, num;
		cin >> cost >> num;
		t[i] = cost;
		for (int j = 0; j < num; j++)
		{
			int v;
			cin >> v;
			adj[v].push_back(i);
			indegree[i]++;
		}
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> zero;
	for (int i = 1; i <= n; i++)
		if (indegree[i] == 0) zero.push({ t[i], i });

	int ans = 0;
	while (!zero.empty())
	{
		auto cur = zero.top(); zero.pop();
		ans = cur.first;
		for (auto nxt : adj[cur.second])
		{
			if (--indegree[nxt] == 0) zero.push({ cur.first + t[nxt], nxt});
		}
	}

	cout << ans << "\n";
	return 0;
}