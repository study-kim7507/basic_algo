#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;
pair<int, int> startPos;
pair<int, int> endPos;
int n;

bool bfs()
{
	bool vis[101];
	fill(vis, vis + 101, false);

	queue<pair<int, int>> q;
	q.push({ startPos.first, startPos.second });

	while (!q.empty())
	{
		auto cur = q.front(); q.pop();

		if (abs(cur.first - endPos.first) + abs(cur.second - endPos.second) <= 1000) return true;

		for (int i = 0; i < n; i++)
		{
			if (vis[i] == true) continue;
			auto cur_pos = v[i];
			if (abs(cur.first - cur_pos.first) + abs(cur.second - cur_pos.second) <= 1000)
			{
				vis[i] = true;
				q.push(cur_pos);
			}
		}
	}


	return false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		v.clear();
		cin >> n;

		int st_x, st_y;
		cin >> st_x >> st_y;
		startPos = { st_x, st_y };

		for (int i = 0; i < n; i++)
		{
			int x, y;
			cin >> x >> y;
			v.push_back({ x, y });
		}

		int en_x, en_y;
		cin >> en_x >> en_y;
		endPos = { en_x, en_y };

		if (bfs()) cout << "happy" << "\n";
		else cout << "sad" << "\n";

	}

	return 0;
}