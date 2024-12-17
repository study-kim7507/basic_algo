// 1926. 그림
#include <iostream>
#include <queue>
using namespace std;

#define X first
#define Y second

int board[501][501];
bool visit[501][501];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int height, width; // n, m. 도화지의 세로, 가로 크기
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> height >> width;
	for (int y = 1; y <= height; y++)
	{
		for (int x = 1; x <= width; x++)
		{
			cin >> board[y][x];
		}
	}

	int pictureCount = 0; // 도화지 내의 그림의 개수
	int maxArea = 0;	  // 그림 중 가장 큰 그림의 넓이.

	for (int y = 1; y <= height; y++) // i : 세로, y
	{
		for (int x = 1; x <= width; x++) // j : 가로, ㅌ
		{
			if (board[y][x] != 0 && visit[y][x] != true)
			{
				int curPictureArea = 0; // 현재 그림의 넓이
				queue<pair<int, int>> q;
				q.push({ x, y });
				visit[y][x] = true; // 방문 표시
				while (!q.empty())
				{
					auto cur = q.front();
					q.pop();
					curPictureArea++;
					for (int dir = 0; dir < 4; dir++)
					{
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx > width || ny > height || nx <= 0 || ny <= 0) continue;
						if (visit[ny][nx] || board[ny][nx] != 1) continue;
						q.push({ nx, ny });
						visit[ny][nx] = true;
					}
				}
				pictureCount++;
				if (maxArea < curPictureArea)
					maxArea = curPictureArea;
			}
		}
	}

	cout << pictureCount << "\n";
	cout << maxArea << "\n";
	return 0;
}