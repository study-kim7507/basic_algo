// 최대 64개의 칸에서 3개를 선택

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define X first
#define Y second

int n, m;
int board[10][10];
bool visit[10][10];
queue<pair<int, int>> virus;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int ans = -1;

void combi()
{
	vector<int> v = { 0, 0, 1, 1, 1};
	do
	{
		for (int i = 0; i < 5; i++)
			if (v[i] == 1) cout << i << " ";
		cout << "\n";
	} while (next_permutation(v.begin(), v.end()));
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 2)
				virus.push({ i, j });
		}
	}
		
	vector<int> combi(n * m, 0);
	for (int i = 0; i < 3; i++)
		combi[combi.size() - 1 - i] = 1;

	do
	{
		int tmp[10][10];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				tmp[i][j] = board[i][j];
				visit[i][j] = 0;
			}
		}
			
		bool isCan = true;						// 랜덤하게 뽑은 3개의 좌표에 벽을 모두 세울 수 있는지
		for (int i = 0; i < combi.size(); i++)
		{
			if (combi[i] == 1)
			{
				int posX = i / m;
				int posY = i % m;
				if (tmp[posX][posY] != 0)
				{
					isCan = false;
					break;
				}
				tmp[posX][posY] = 2;
			}
		}
		if (!isCan) continue;		

		queue<pair<int, int>> curVirus = virus;
		visit[curVirus.front().X][curVirus.front().Y] = 1;
		while (!curVirus.empty())
		{
			auto cur = curVirus.front(); curVirus.pop();
			tmp[cur.X][cur.Y] = 2;
			for (int dir = 0; dir < 4; dir++)
			{
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if (tmp[nx][ny] != 0 || visit[nx][ny] != 0) continue;
				curVirus.push({ nx, ny });
				visit[nx][ny] = 1;
			}
		}

		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (tmp[i][j] == 0)
					cnt++;
			}
		}
		ans = max(ans, cnt);
	} while (next_permutation(combi.begin(), combi.end()));


	cout << ans << "\n";

	return 0;
}