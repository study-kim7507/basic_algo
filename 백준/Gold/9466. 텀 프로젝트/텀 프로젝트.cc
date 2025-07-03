// BOJ_9466. 텀 프로젝트
#include <iostream>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;

int n;
int table[100001];
bool vis[100001];

int cnt = 0;
void bfs(int st)
{
	unordered_set<int> us;
	queue<int> q;
	q.push(st);
	vis[st] = true;
	us.insert(st);

	int idx;
	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		if (us.find(table[cur]) != us.end())
		{
			idx = cur;
			break;
		}
		if (vis[table[cur]]) return;

		us.insert(table[cur]);
		vis[table[cur]] = true;
		q.push(table[cur]);
	}

	int stIdx = idx;
	int temp = 1;
	while (table[idx] != stIdx)
	{
		idx = table[idx];
		temp++;
	}
	cnt += temp;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> table[i];

		for (int i = 1; i <= n; i++)
		{
			if (vis[i]) continue;
			bfs(i);
		}

		std::cout << n - cnt << "\n";
	
		cnt = 0;
		fill(vis, vis + 100001, false);
	}

	return 0;
}