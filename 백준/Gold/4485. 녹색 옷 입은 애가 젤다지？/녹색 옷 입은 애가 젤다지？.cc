// 다익스트라 알고리즘

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

const int INF = 0x3f3f3f3f;

int board[130][130];
int d[130][130];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for(int i = 1; ; i++)
	{
		int n;
		cin >> n;
		if (n == 0) return 0;

		
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> board[i][j];

	
		for (int i = 0; i < n; i++)
			fill(d[i], d[i] + n + 1, INF);

		// {비용, 정점}
		priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
		pq.push({ board[0][0], {0, 0} });
		d[0][0] = board[0][0];
		while (!pq.empty())
		{
			auto cur = pq.top(); pq.pop();
			if (d[cur.second.first][cur.second.second] < cur.first) continue;
			for (int dir = 0; dir < 4; dir++)
			{
				int nx = cur.second.first + dx[dir];
				int ny = cur.second.second + dy[dir];
				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
				if (cur.first + board[nx][ny] >= d[nx][ny]) continue;
				d[nx][ny] = cur.first + board[nx][ny];
				pq.push({d[nx][ny], { nx, ny }});
			}
		}

		cout << "Problem " << i << ": " << d[n - 1][n - 1] << "\n";

	}

	return 0;
}