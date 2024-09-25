// 먼저 모든 파티를 순회하면서, 이미 진실을 알고있는 인원이 참가하는 파티에 있는 모든 인원들은 진실을 알게되므로 진실을 알고있는 인원에 포함
// 다시 파티를 순회하면서, 파티에 참여하는 인원들이 모두 진실을 모르는 경우 과장된 이야기를 할 수 있는 파티가 된다.

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

int n, m, k;			// 사람의 수, 파티의 수
int knowTrue[51];
vector<int> adj[51];
vector<int> party[51];

void bfs()
{
	queue<int> q;
	for (int i = 1; i <= n; i++)
		if (knowTrue[i] == true)
			q.push(i);

	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		for (auto nxt : adj[cur])
		{
			if (knowTrue[nxt]) continue;
			knowTrue[nxt] = true;
			q.push(nxt);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	cin >> k;

	for (int i = 0; i < k; i++)
	{
		int num;
		cin >> num;
		knowTrue[num] = true;
	}

	for (int i = 0; i < m; i++)
	{
		int num;
		cin >> num;

		int prev = 0;
		for (int j = 0; j < num; j++)
		{
			int p;
			cin >> p;
			party[i].push_back(p);
			if (prev == 0)
			{
				prev = p;
				continue;
			}
			else
			{
				adj[prev].push_back(p);
				adj[p].push_back(prev);
				prev = p;
			}
		}
	}

	bfs();

	int ans = 0;
	for (int i = 0; i < m; i++)
	{
		bool known = false;
		for (int p : party[i]) if (knowTrue[p]) known = true;
		if (!known) ans++;
	}
	cout << ans << "\n";
	return 0;
}