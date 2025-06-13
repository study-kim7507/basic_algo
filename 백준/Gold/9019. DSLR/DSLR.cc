// BOJ_9019.DSLR
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string vis[10000];

int d(int cur)
{
	return (2 * cur) % 10000;
}
int s(int cur)
{
	return cur - 1 < 0 ? 9999 : cur - 1;
}
int l(int cur)
{
	return (cur % 1000) * 10 + (cur / 1000);
}
int r(int cur)
{
	return (cur % 10) * 1000 + (cur / 10);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int a, b;
		cin >> a >> b;

		fill(vis, vis + 10000, "");

		queue<int> q;
		q.push(a);
		vis[a] = "0";
		while (!q.empty())
		{
			auto cur = q.front(); q.pop();
			if (cur == b) break;
			for (int dir = 0; dir < 4; dir++)
			{
				int num = 0;
				if (dir == 0)
				{
					num = d(cur);
					if (vis[num] != "") continue;
					vis[num] = vis[cur] + "D";
				}
				else if (dir == 1)
				{
					num = s(cur);
					if (vis[num] != "") continue;
					vis[num] = vis[cur] + "S";
				}
				else if (dir == 2)
				{
					num = l(cur);
					if (vis[num] != "") continue;
					vis[num] = vis[cur] + "L";
				}
				else if (dir == 3)
				{
					num = r(cur);
					if (vis[num] != "") continue;
					vis[num] = vis[cur] + "R";
				}

				q.push(num);
			}
		}

		std::cout << vis[b].substr(1, vis[b].size()) << "\n";
	}

	return 0;
}