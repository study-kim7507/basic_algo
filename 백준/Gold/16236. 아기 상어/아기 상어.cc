// BOJ_16235. 아기 상어
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define X first
#define Y second

const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, -1, 0, 1 };

int ans = 0;

int n;
int board[21][21];

pair<int, int> currentPos;
int currentSize = 2;
int currentEatCount = 0;


struct cmp
{
	bool operator()(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b)
	{
		if (a.X != b.X) return a.X > b.X;                 // 거리 짧은 게 우선
		if (a.Y.X != b.Y.X) return a.Y.X > b.Y.X;         // x (행) 작은 게 우선
		return a.Y.Y > b.Y.Y;                             // y (열) 작은 게 우선
	}
};


pair<int, pair<int, int>> bfs()
{
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, cmp> pq;

	vector<vector<int>> dist(n + 1, vector<int>(n + 1, 0));
	queue<pair<int, int>> q;
	dist[currentPos.X][currentPos.Y] = 1;
	q.push({ currentPos.X, currentPos.Y });

	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (dist[nx][ny]) continue;
			if (board[nx][ny] > currentSize) continue;

			q.push({ nx, ny });
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;

			if (board[nx][ny] != 0 && board[nx][ny] < currentSize) 
				pq.push({ dist[nx][ny] - 1, {nx, ny} });
		}
	}

	if (pq.empty()) return { -1, { -1, -1} };
	return pq.top();
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 9)
			{
				currentPos = make_pair(i, j);
				board[i][j] = 0;
			}
		}
	}

	while (true)
	{
		auto ret = bfs();
		if (ret.Y.X == -1 && ret.Y.Y == -1) break;

		ans += ret.X;
		currentPos.X = ret.Y.X; currentPos.Y = ret.Y.Y;

		currentEatCount++;
		if (currentSize == currentEatCount)
		{
			currentSize++;
			currentEatCount = 0;
		}

		board[ret.Y.X][ret.Y.Y] = 0;
	}

	std::cout << ans << "\n";
	return 0;
}

