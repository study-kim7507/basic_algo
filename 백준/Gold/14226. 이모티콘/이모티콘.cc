// BOJ_16562. 친구비
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// 화면, 클립보드
bool vis[2001][2001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int s;
	cin >> s;

	queue<pair<int, pair<int, int>>> q;
	q.push({ 0, {1, 0} });
	vis[1][0] = true;

	while (!q.empty())
	{
		auto cur = q.front(); q.pop();

		if (cur.second.first == s)
		{
			std::cout << cur.first << "\n";
			return 0;
		}

		// 1. 화면에 있는 이모티콘을 복사해서 클립보드에 저장한다.
		// 3. 화면에 있는 이모티콘 중 하나를 삭제한다.
		if (cur.second.first >= 1)
		{
			// 1
			pair<int, pair<int, int>> p = { cur.first + 1, {cur.second.first, cur.second.first} };
			if (!vis[p.second.first][p.second.second])
			{
				vis[p.second.first][p.second.second] = true;
				q.push({ p.first, {p.second.first, p.second.second} });
			}

			// 3
			p = { cur.first + 1, {cur.second.first - 1, cur.second.second} };
			if (!vis[p.second.first][p.second.second])
			{
				vis[p.second.first][p.second.second] = true;
				q.push({ p.first, {p.second.first, p.second.second} });
			}
		}

		// 2. 클립보드에 있는 모든 이모티콘을 화면에 붙여넣기 한다.
		if (cur.second.first + cur.second.second <= s && cur.second.second >= 1)
		{
			pair<int, pair<int, int>> p = { cur.first + 1, {cur.second.first + cur.second.second, cur.second.second} };
			if (!vis[p.second.first][p.second.second])
			{
				vis[p.second.first][p.second.second] = true;
				q.push({ p.first, {p.second.first, p.second.second} });
			}
		}
	}

	std::cout << s << "\n";
	return 0;
}