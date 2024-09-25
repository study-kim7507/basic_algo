#include <iostream>
using namespace std;

int n, m;
int board[21][21];

int x, y;
int k;

// 주사위 전개도
// front, up, back, down, left, right
int dice[6];

// 이동 명령을 수행
bool move(int moveDir)
{
	int tmp[6];
	for (int i = 0; i < 6; i++)
		tmp[i] = dice[i];

	if (moveDir == 1)			// 동쪽	- 오른쪽
	{
		if (y + 1 >= m) return false;
		dice[1] = tmp[4];
		dice[5] = tmp[1];
		dice[3] = tmp[5];
		dice[4] = tmp[3];
		y += 1;
	}
	else if (moveDir == 2)		// 서쪽	- 왼쪽
	{
		if (y - 1 < 0) return false;
		dice[1] = tmp[5];
		dice[4] = tmp[1];
		dice[3] = tmp[4];
		dice[5] = tmp[3];
		y -= 1;
	}
	else if (moveDir == 3)		// 북쪽 - 앞쪽
	{
		if (x - 1 < 0) return false;
		for (int i = 0; i < 3; i++)
			dice[i] = tmp[i + 1];
		dice[3] = tmp[0];
		x -= 1;
	}
	else if (moveDir == 4)		// 남쪽	- 뒤쪽
	{
		if (x + 1 >= n) return false;
		for (int i = 1; i <= 3; i++)
			dice[i] = tmp[i - 1];
		dice[0] = tmp[3];
		x += 1;
	}
	return true;
}	

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;				// 지도의 크기
	cin >> x >> y;				// 시작 위치
	cin >> k;					// 이동 명령의 수

	for (int r = 0; r < n; r++)
		for (int c = 0; c < m; c++)
			cin >> board[r][c];
		

	// 이동 명령 : 동쪽은 1, 서쪽은 2, 북쪽은 3, 남쪽은 4
	while (k--)
	{
		int moveDir;
		cin >> moveDir;
		bool canMove = move(moveDir);

		if (canMove) 
		{
			if (board[x][y] == 0) board[x][y] = dice[3];
			else if (board[x][y] != 0)
			{
				dice[3] = board[x][y];
				board[x][y] = 0;
			}


			cout << dice[1] << "\n";
		}
	}

	return 0;
}