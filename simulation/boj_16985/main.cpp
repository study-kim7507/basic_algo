#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

int board[5][5][5]; 
bool isAllSame[5];

int dist[5][5][5];
int tmp[5][5][5];

int dx[6] = { -1, 1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, -1, 1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, -1, 1 };

int ans = 987654321;

vector<tuple<int, int, int>> vertex =			// 시작점으로 선정 가능한 꼭짓점
{
	{0, 0, 0},
	{0, 4, 0},
	{4, 0, 0},
	{4, 4, 0},
	{0, 0, 4},
	{0, 4, 4},
	{4, 0, 4},
	{4, 4, 4}
};

// num에 해당하는 판을 90도 회전시키는 함수
void rotation(int num)			
{
	int tmp[5][5];
	for (int r = 0; r < 5; r++)
		for (int c = 0; c < 5; c++)
			tmp[r][c] = board[num][r][c];

	
	// rotation
	for (int r = 0; r < 5; r++)
		for (int c = 0; c < 5; c++)
			board[num][r][c] = tmp[5 - 1 - c][r];
}
void copy(int dir)
{
	if (dir == 0)
	{
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				for (int k = 0; k < 5; k++)
					tmp[i][j][k] = board[i][j][k];
		return;
	}
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			for (int k = 0; k < 5; k++)
				board[i][j][k] = tmp[i][j][k];
}

void bfs()
{
	// 판을 쌓는 순서도 참가자가 결정할 수 있음.
	// 순열
	int shuffle[5][5][5];
	int permu[5] = { 0, 1, 2, 3, 4 };
	do
	{
		for (int i = 0; i < 5; i++)
			for (int r = 0; r < 5; r++)
				for (int c = 0; c < 5; c++)
					shuffle[i][r][c] = board[permu[i]][r][c];

		for (int i = 0; i < 8; i++)
		{
			auto start = vertex[i];
			// 시작점이 참가자가 들어갈 수 없는 칸이라면 건너 뜀
			if (shuffle[get<0>(start)][get<1>(start)][get<2>(start)] == 0) continue;

			// 출구
			int endX = get<0>(start) == 0 ? 4 : 0;
			int endY = get<1>(start) == 0 ? 4 : 0;
			int endZ = get<2>(start) == 0 ? 4 : 0;
			// 출구가 참가자가 들어갈 수 없는 칸이라면 건너 뜀
			if (shuffle[endX][endY][endZ] == 0) continue;

			queue<tuple<int, int, int>> q;
			q.push(start);
			dist[get<0>(start)][get<1>(start)][get<2>(start)] = 1;
			while (!q.empty())
			{
				auto cur = q.front(); q.pop();
				for (int dir = 0; dir < 6; dir++)
				{
					int nx = get<0>(cur) + dx[dir];
					int ny = get<1>(cur) + dy[dir];
					int nz = get<2>(cur) + dz[dir];
					if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || nz < 0 || nz >= 5) continue;
					if (dist[nx][ny][nz] != 0 || shuffle[nx][ny][nz] == 0) continue;
					dist[nx][ny][nz] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
					q.push({ nx, ny, nz });
				}
			}

			if (dist[endX][endY][endZ] != 0)
				ans = min(ans, dist[endX][endY][endZ] - 1);

			// dist 초기화
			for (int i = 0; i < 5; i++)
				for (int j = 0; j < 5; j++)
					for (int k = 0; k < 5; k++)
						dist[i][j][k] = 0;
		}
	} while (next_permutation(permu, permu + 5));
}


void func(int cnt)
{
	if (cnt == 1)				
	{
		bfs();
		return;
	}

	for (int first = 0; first < (isAllSame[0] ? 1 : 4); first++)
	{
		for (int second = 0; second < (isAllSame[1] ? 1 : 4); second++)
		{
			for (int third = 0; third < (isAllSame[2] ? 1 : 4); third++)
			{
				for (int fourth = 0; fourth < (isAllSame[3] ? 1 : 4); fourth++)
				{
					for (int fifth = 0; fifth < (isAllSame[4] ? 1 : 4); fifth++)
					{
						func(cnt + 1);
						rotation(4);
					}
					rotation(3);
				}
				rotation(2);
			}
			rotation(1);
		}
		rotation(0);
	}
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int i = 0; i < 5; i++)
	{
		int isSame;
		for (int r = 0; r < 5; r++)
		{
			for (int c = 0; c < 5; c++)
			{
				cin >> board[i][r][c];
				if (r == 0 && c == 0) isSame = board[i][r][c];
				if (isSame != board[i][r][c]) isSame = -1;
			}
		}
		if (isSame != -1) isAllSame[i] = true;

	}

	func(0);


	if (ans != 987654321)
		cout << ans << "\n";
	else
		cout << -1 << "\n";
	return 0;
}