// 14567. 선수 과목
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> adj[1001];
int indegree[1001];
int result[1001];

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		indegree[b]++;
	}

	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (indegree[i] == 0)
		{
			q.push(i);
			result[i] = 1;
		}		
	}

	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		for (auto nxt : adj[cur])
		{
			indegree[nxt]--;
			if (indegree[nxt] == 0)
			{
				q.push(nxt);
				result[nxt] = result[cur] + 1;
			}
		}
	}

	for (int i = 1; i <= n; i++)
		cout << result[i] << " ";

	return 0;
}