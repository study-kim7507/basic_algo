#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define X first
#define Y second

char board[12][6];
int visit[12][6];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0 ,1 };

int ans = 0;
bool destroyPuyo(const vector<pair<int, int>>& startPos)
{
	vector<vector<pair<int, int>>> destroy;
	for (int i = 0; i < startPos.size(); i++)
	{
		vector<pair<int, int>> curDestroy;
		auto start = startPos[i];
		queue<pair<int, int>> q;
		q.push({ start.X, start.Y });

		while (!q.empty())
		{
			auto cur = q.front(); q.pop();
			for (int dir = 0; dir < 4; dir++)
			{
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6) continue;
				if (board[nx][ny] != board[cur.X][cur.Y]) continue;
				if (visit[nx][ny] == -1) continue;
				q.push({ nx, ny });
				visit[nx][ny] = -1;
				curDestroy.push_back({ nx, ny });
			}
		}

		destroy.push_back(curDestroy);
	}

	bool result = true;										// 뿌실 뿌요가 있는지
	for (int i = 0; i < destroy.size(); i++)
	{
		auto cur = destroy[i];
		if (cur.size() >= 4)
		{		
			result = false;
			for (int j = 0; j < cur.size(); j++)
			{
				board[cur[j].X][cur[j].Y] = '.';			// 해당 칸의 뿌요는 부심
			}
		}
	}

	if (!result) ans++;
	return result;
}


// 뿌요가 부셔진 이후 위에 존재하던 뿌요를 바닥까지 내리기
void re()
{
	for (int i = 10; i >= 0; i--)
	{
		int cur = i;
		for (int j = 0; j < 6; j++)
		{
			while (cur + 1 < 12 && board[cur + 1][j] == '.')
			{
				board[cur + 1][j] = board[cur][j];
				board[cur][j] = '.';
				cur++;
			}
			cur = i;
		}
	}

	return;
}

void forDebugging()
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 6; j++)
			cout << board[i][j];
		cout << "\n";
	}
	cout << "\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int x = 0; x < 12; x++)
	{
		for (int y = 0; y < 6; y++)
		{
			cin >> board[x][y];
		}
	}

	// 더 이상 터질 뿌요들이 없을 때까지 반복
	while (true)
	{
		bool end = false;
		vector<pair<int, int>> startPos;

		for (int i = 0; i < 12; i++)
			fill(visit[i], visit[i] + 6, 0);

		for (int x = 0; x < 12; x++)
		{
			for (int y = 0; y < 6; y++)
			{
				if (board[x][y] != '.' && visit[x][y] == 0)
				{
					queue<pair<int, int>> q;
					
					q.push({ x, y });
					startPos.push_back({ x, y });
					
					visit[x][y] = 1;
					int cnt = 1;

					while (!q.empty())
					{
						auto cur = q.front(); q.pop();
						for (int dir = 0; dir < 4; dir++)
						{
							int nx = cur.X + dx[dir];
							int ny = cur.Y + dy[dir];
							if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6) continue;
							if (board[cur.X][cur.Y] != board[nx][ny]) continue;
							if (visit[nx][ny] != 0) continue;
							q.push({ nx, ny });
							visit[nx][ny] += ++cnt;
						}
					}
				}
			}
		}

		end = destroyPuyo(startPos);

		// forDebugging();

		re();

		

	

		// 더 이상 터질 뿌요가 없음
		if (end) break;
	}
	// forDebugging();

	cout << ans << "\n";
	return 0;
}