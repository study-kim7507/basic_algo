// BOJ_2623. 음악 프로그램
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> edges[1001];
int indegree[1001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int cnt = 0;
		cin >> cnt;
		
		int prev, next;
		cin >> prev;
		for (int j = 1; j < cnt; j++)
		{
			cin >> next;
			edges[prev].push_back(next);
			indegree[next]++;
			prev = next;
		}
	}

	queue<int> q;
	for (int i = 1; i <= n; i++)
		if (indegree[i] == 0) q.push(i);

	vector<int> ans;
	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		ans.push_back(cur);
		for (auto nxt : edges[cur])
		{
			if (--indegree[nxt] == 0) q.push(nxt);
		}
	}

	if (ans.size() != n) std::cout << 0 << "\n";
	else
	{
		for (auto e : ans)
			std::cout << e << "\n";
	}

	return 0;
}