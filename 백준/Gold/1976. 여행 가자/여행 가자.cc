// BOJ_1976. 여행가자
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;

vector<int> edges[201];
vector<int> plan;
int parent[201];
bool vis[201];

int find(int a)
{
	if (a != parent[a]) return find(parent[a]);
	return a;
}

void uni(int a, int b)
{
	a = find(a);
	b = find(b);

	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		parent[i] = i;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int num;
			cin >> num;
			if (num == 1)
			{
				edges[i].push_back(j);
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		int num;
		cin >> num;
		plan.push_back(num - 1);
	}

	int cnt = 0;

	int st = plan[0];
	queue<int> q;
	q.push(st);
	
	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		for (auto nxt : edges[cur])
		{
			if (find(cur) == find(nxt)) continue;

			uni(cur, nxt);
			cnt++;

			if (cnt == n - 1) break;

			q.push(nxt);
		}
	}

	bool can = true;
	for (int i = 1; i < plan.size(); i++)
	{
		if (find(plan[i - 1]) != find(plan[i])) can = false;
	}

	if (can) std::cout << "YES";
	else std::cout << "NO";

	return 0;
}