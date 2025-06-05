// BOJ_2056. 작업
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int indegree[10001];
int cost[10001];

vector<int> adjs[10001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int c;
		cin >> c;
		cost[i] = c;

		int cnt;
		cin >> cnt;
		for (int j = 0; j < cnt; j++)
		{
			int k;
			cin >> k;
			adjs[k].push_back(i);
			indegree[i]++;
		}
	}

	for (int i = 1; i <= n; i++)
		if (indegree[i] == 0) pq.push({ cost[i], i });
	
	int answer = 0;
	while (!pq.empty())
	{
		auto cur = pq.top(); pq.pop();
		answer = max(answer, cur.first);
		for (auto nxt : adjs[cur.second])
		{
			indegree[nxt]--;
			if (indegree[nxt] == 0)
			{
				pq.push({ answer + cost[nxt], nxt });
			}
		}
	}
	std::cout << answer << "\n";
	return 0;
}