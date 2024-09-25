#include <iostream>
using namespace std;

int n, m;			// 방의 크기
int r, c;			// 로봇 청소기의 위치
int d;				// 로봇 청소기가 바라보는 방향

int room[50][50];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

pair<int, int> rotation[4] =		// 현재 바라보고 있는 방향에 따라 반시계 회전했을 때의 좌표가 어떻게 될지
{
	{0, -1},		// 현재 바라보고 있는 방향이 0번
	{-1, 0},			// 현재 바라보고 있는 방향이 1번
	{0, 1},			// 현재 바라보고 있는 방향이 2번
	{1, 0}			// 현재 바라보고 있는 방향이 3번
};

pair<int, int> back[4] =			// 현재 바라보고 있는 방향에 따라 후진했을 때의 좌표가 어떻게 될지
{
	{1, 0},
	{0, -1},
	{-1, 0},
	{0, 1}
};

void debugging()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << room[i][j] << " ";
		cout << "\n";
	}
	cout << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	cin >> r >> c >> d;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> room[i][j];

	while (true)
	{
		// 현재 칸이 청소되지 않았다면, 현재 칸을 청소
		if (room[r][c] == 0)
		{
			room[r][c] = -1;	// 청소
			// debugging();
		}
						

		// 주변 4칸을 조사
		bool isCan = false;
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = r + dx[dir];
			int ny = c + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (room[nx][ny] == 0)	// 주변 4칸 중 청소되지 않은 빈 칸이 있음
			{
				isCan = true;
				break;
			}
		}
		// 청소되지 않은 빈칸이 있는 경우
		if (isCan)
		{
			int tmpR = r;
			int tmpC = c;
			
			// 현재 바라보는 방향 기준 반시계 방향 90도 회전 
			// 회전 후, 바라보는 방향 기준 앞쪽 칸
			r += rotation[d].first;
			c += rotation[d].second;

			// 앞쪽 칸이 청소되지 않은 빈 칸이 아닌 경우
			if (room[r][c] != 0)
			{
				// 청소된 칸이라면 회전만 변경
				r = tmpR;
				c = tmpC;
			}
			d = d - 1 < 0 ? 3 : d - 1;
		}
		// 청소되지 않은 빈칸이 없는 경우
		else
		{
			// 현재 바라보는 방향의 뒤쪽으로 이동하되 벽을 만나면 종료
			r += back[d].first;
			c += back[d].second;
	
			
			// 벽을 만나면 청소 종료
			if (r < 0 || r >= n || c < 0 || c >= m) break;
			if (room[r][c] == 1) break;
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (room[i][j] == -1) ans++;
		}
	}

	cout << ans << "\n";

	return 0;
}
