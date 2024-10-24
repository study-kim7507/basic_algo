#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int n, m;
int inDegree[101];
bool isDefault[101];

// cnt[n][k] : n번 제품을 만드는데 필요한 k부품의 개수
int cnt[101][101];

vector<pair<int, int>> edges[101];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y, k;
		cin >> x >> y >> k;
		edges[y].push_back({ x, k });
		inDegree[x] += k;
	}

	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (inDegree[i] == 0)
		{
			q.push(i);
			isDefault[i] = true;
		}
	}
		
	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		for (auto nxt : edges[cur])
		{
			inDegree[nxt.first] -= nxt.second;
			if (isDefault[cur] == true)
				cnt[nxt.first][cur] += nxt.second;
			else
			{
				for (int i = 1; i <= n; i++)
					cnt[nxt.first][i] += cnt[cur][i] * nxt.second;
			}

			if (inDegree[nxt.first] == 0)
				q.push(nxt.first);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (isDefault[i] == true)
			cout << i << " " << cnt[n][i] << "\n";
	}
	return 0;
}