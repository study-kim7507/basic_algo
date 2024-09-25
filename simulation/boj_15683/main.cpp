// 4가지 방향을 bool 값으로.. {상, 하, 좌, 우}
// 1번 카메라 -> [{0, 0, 0, 1}, {0, 1, 0, 0}, {0, 0, 1, 0}, {1, 0, 0, 0}]
// 2번 카메라 -> [{0, 0, 1, 1}, {1, 1, 0, 0}]
// 3번 카메라 -> [{1, 0, 0, 1}, {0, 1, 0, 1}, {0, 1, 1, 0}, {1, 0, 1, 0}]
// 4번 카메라 -> [{1, 0, 1, 1}, {1, 1, 0, 1}, {0, 1, 1, 1}, {1, 1, 1, 0}]
// 5번 카메라 -> [{1, 1, 1, 1}]

#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

int n, m; // x ,y

// 최대 8x8의 크기
int board[8][8];
int arr[8][8];


vector<tuple<bool, bool, bool, bool>> camera[6] =
{
	{{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
	{{0, 0, 0, 1}, {0, 1, 0, 0}, {0, 0, 1, 0}, {1, 0, 0, 0}},	// 1번 카메라
	{{0, 0, 1, 1}, {1, 1, 0, 0}},								// 2번 카메라
	{{1, 0, 0, 1}, {0, 1, 0, 1}, {0, 1, 1, 0}, {1, 0, 1, 0}},	// 3번 카메라
	{{1, 0, 1, 1}, {1, 1, 0, 1}, {0, 1, 1, 1}, {1, 1, 1, 0}},	// 4번 카메라
	{{1, 1, 1, 1}}												// 5번 카메라
};

int ans = 987654321;

// for backtracking
void copyBoard(int temp[8][8], bool rev)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (!rev)
				temp[i][j] = arr[i][j];
			else
				arr[i][j] = temp[i][j];
		}
	}
}

int count()
{
	int ret = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 0) ret++;
		}
	}
	return ret;
}
void check(int x, int y, bool up, bool down, bool left, bool right)
{
	int curX = x;
	int curY = y;

	if (up)
	{
		while (--curX >= 0)
		{
			if (arr[curX][curY] == 6) break;
			if ((arr[curX][curY] >= 1 && arr[curX][curY] <= 5)) continue;
			arr[curX][curY] = -1;
		}
	}

	curX = x;
	curY = y;

	if (down)
	{
		while (++curX < n)
		{
			if (arr[curX][curY] == 6) break;
			if ((arr[curX][curY] >= 1 && arr[curX][curY] <= 5)) continue;
			arr[curX][curY] = -1;
		}
	}

	curX = x;
	curY = y;

	if (left)
	{
		while (--curY >= 0)
		{
			if (arr[curX][curY] == 6) break;
			if ((arr[curX][curY] >= 1 && arr[curX][curY] <= 5)) continue;
			arr[curX][curY] = -1;
		}
	}
	
	curX = x;
	curY = y;
	if (right)
	{
		while (++curY < m)
		{
			if (arr[curX][curY] == 6) break;
			if ((arr[curX][curY] >= 1 && arr[curX][curY] <= 5)) continue;
			arr[curX][curY] = -1;
		}
	}
}

void func(int x, int y, int cnt)
{
	if (y >= m)
	{
		x = x + 1;
		y = 0;
	}

	if (cnt == n * m)
	{
		int tempResult = count();
		if (ans > tempResult) ans = tempResult;
		return;
	}

	// 현재 위치가 카메라가 아닌 경우
	if (!(arr[x][y] >= 1 && arr[x][y] <= 5))
	{
		func(x, y + 1, cnt + 1);
		return;
	}
		

	// 현재 위치가 카메라인 경우
	vector<tuple<bool, bool, bool, bool>> cur = camera[board[x][y]];
	for (auto dir : cur)
	{
		int temp[8][8];
		copyBoard(temp, false);
		
		bool up = get<0>(dir);
		bool down = get<1>(dir);
		bool left = get<2>(dir);
		bool right = get<3>(dir);

		check(x, y, up, down, left, right);

		func(x, y + 1, cnt + 1);
		copyBoard(temp, true);
	}
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			arr[i][j] = board[i][j];
		}
	}

	func(0, 0, 0);


	cout << ans << "\n";

	return 0;
}