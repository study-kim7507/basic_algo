#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, r, q;
vector<int> adj[51];
bool isAlive[51];

void remove_node(int target)
{
	bool vis[51];
	fill(vis, vis + 51, false);

	isAlive[target] = false;
	queue<int> q;
	q.push(r);
	vis[r] = true;
	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		for (auto nxt : adj[cur])
		{
			if (vis[nxt] == true) continue;
			vis[nxt] = true;
			q.push(nxt);
			if (isAlive[cur] == false) isAlive[nxt] = false;
		}
	}
}

int bfs()
{
	int ret = 0;
	bool vis[51];
	fill(vis, vis + 51, false);

	queue<int> q;
	q.push(r);
	vis[r] = true;
	while (!q.empty())
	{
		/*
		2
		- 1 0
		1
		*/
		bool isHaveChild = false;
		auto cur = q.front(); q.pop();
		for (auto nxt : adj[cur])
		{
			if (vis[nxt] == true) continue;
			if (isAlive[nxt] == false) continue;
			vis[nxt] = true;
			q.push(nxt);
			isHaveChild = true;
		}
		if (!isHaveChild) ret++;
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	fill(isAlive, isAlive + 51, true);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int p;
		cin >> p;
		if (p == -1) r = i;
		else adj[p].push_back(i);
	}

	cin >> q;
	if (q == r)
	{
		cout << 0 << "\n";
		return 0;
	}

	remove_node(q);
	cout << bfs() << "\n";

	return 0;
}