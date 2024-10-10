#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int n, m;

int indegree[101];

// {개수, 부품번호}
vector<pair<int, int>> edges[101];

// result[i][j] : i를 만드는데 필요한 j의 개수
int result[101][101];

bool isDefault[101];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y, k;
		cin >> x >> y >> k;				// X를 만드는데 Y는 K개 필요함
		edges[y].push_back({ k, x });
		indegree[x]++;
	}

	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (indegree[i] == 0)
		{
			q.push(i);
			isDefault[i] = true;	// 기본 부품 인지
		}
	}

	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		if (isDefault[cur] == true)
		{
			for (auto element : edges[cur])
			{
				result[element.second][cur] += element.first;
				if (--indegree[element.second] == 0) q.push(element.second);
			}
		}
		else
		{
			for (auto element : edges[cur])
			{
				for (int i = 1; i <= n; i++)
				{
					result[element.second][i] += (result[cur][i] * element.first);
				}
				if (--indegree[element.second] == 0) q.push(element.second);
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (isDefault[i] != true) continue;
		cout << i << " " << result[n][i] << "\n";
	}
	return 0;
}